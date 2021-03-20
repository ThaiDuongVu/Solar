#include "text.h"
#include "../debug.h"
#include "../types/vector2.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <../glm/gtc/matrix_transform.hpp>
#include <../glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H  

namespace Solar
{
	FT_Library ft;
	FT_Face face;

	Text::Text(Transform transform, std::string message, Color color, Font font, bool is_visible, bool is_parallax) : GameObject(transform, is_visible, is_parallax)
	{
		this->message = message;
		this->color = color;
		this->font = font;
	}
	Text::~Text()
	{
	}

	void Text::Init(App app)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		shader.Init();
		glm::mat4 projection = glm::ortho(0.0f, (float)app.Width(), 0.0f, (float)app.Height());
		shader.Use();
		glUniformMatrix4fv(glGetUniformLocation(shader.program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		if (FT_Init_FreeType(&ft))
		{
			Debug::LogError("Failed to initialize FreeType Library");
			return;
		}

		if (FT_New_Face(ft, font.path, 0, &face))
		{
			Debug::LogError("Failed to load font");
			return;
		}

		FT_Set_Pixel_Sizes(face, font.width, font.height);

		// Disable byte-alignment restriction
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		// Load first 128 characters of ASCII set
		for (unsigned char c = 0; c < 128; c++)
		{
			// load character glyph 
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				Debug::LogError("Failed to load Glyph");
				Debug::Log(c);
				break;
			}

			// Generate texture
			unsigned int texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RED,
				face->glyph->bitmap.width,
				face->glyph->bitmap.rows,
				0,
				GL_RED,
				GL_UNSIGNED_BYTE,
				face->glyph->bitmap.buffer
			);

			// Set texture options
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			// Now store character for later use
			Character character = {
				texture,
				Vector2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
				Vector2(face->glyph->bitmap_left, face->glyph->bitmap_top),
				(unsigned int)face->glyph->advance.x
			};
			character_set.insert(std::pair<char, Character>(c, character));
		}

		glBindTexture(GL_TEXTURE_2D, 0);

		FT_Done_Face(face);
		FT_Done_FreeType(ft);

		// Generate buffer and vertex array
		glGenBuffers(1, &vbo);
		glGenVertexArrays(1, &vao);

		// Bind buffer and vertex array
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		//Position attribute
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
		glEnableVertexAttribArray(0);

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		transform.scale = Vector2(1.0f, 1.0f);

		done_init = true;
	}

	void Text::Draw(App app)
	{
		if (!done_init) Init(app);
		if (!is_visible) return;

		// Activate corresponding render state	
		shader.Use();

		glUniform3f(glGetUniformLocation(shader.program, "textColor"), color.r, color.g, color.b);
		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(vao);

		// Viewport position
		double viewport_x = (is_parallax) ? 0.0f : -app.viewport.transform.position.x;
		double viewport_y = (is_parallax) ? 0.0f : -app.viewport.transform.position.y;

		// Text position
		float x = (float)transform.position.x + app.Width() / 2.0f + (float)viewport_x * app.Width() / 2.0f;
		float y = (float)transform.position.y + app.Height() / 2.0f + (float)viewport_y * app.Height() / 2.0f;

		// Iterate through all characters
		for (std::string::const_iterator c = message.begin(); c != message.end(); c++)
		{
			Character character = character_set[*c];

			float x_pos = (float)(x + character.bearing.x * transform.scale.x);
			float y_pos = (float)(y - (character.size.y - character.bearing.y) * transform.scale.y);

			float width = (float)(character.size.x * transform.scale.x);
			float height = (float)(character.size.y * transform.scale.y);

			// Update VBO for each character
			float vertices[6][4] = {
				{ x_pos,		 y_pos + height,   0.0f, 0.0f },
				{ x_pos,		 y_pos,			   0.0f, 1.0f },
				{ x_pos + width, y_pos,			   1.0f, 1.0f },

				{ x_pos,		 y_pos + height,   0.0f, 0.0f },
				{ x_pos + width, y_pos,			   1.0f, 1.0f },
				{ x_pos + width, y_pos + height,   1.0f, 0.0f }
			};

			// Render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, character.texture_id);

			// Update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);

			// Advance cursors for next glyph (note that advance is number of 1/64 pixels)
			// Bitshift by 6 to get value in pixels (2^6 = 64)
			x += (float)((character.advance >> 6) * transform.scale.x);
		}

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

} // namespace Solar
