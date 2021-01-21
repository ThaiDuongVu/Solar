#include "text.h"
#include <map>
#include "../debug.h"
#include "../types/vector2.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>
#include <../glm/gtc/matrix_transform.hpp>
#include <../glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H  

namespace solar
{
	FT_Library ft;
	FT_Face face;

	struct Character
	{
		// ID handle of the glyph texture
		unsigned int texture_id = 0;
		// Size of glyph
		Vector2 size = Vector2();
		// Offset from baseline to left/top of glyph
		Vector2 bearing = Vector2();
		// Offset to advance to next glyph
		unsigned int advance = 0;
	};
	std::map<char, Character> characters;

	Text::Text(std::string message, Color color, Transform transform, Font font)
	{
		this->font = font;
		this->message = message;
		this->color = color;
		this->transform = transform;
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
			characters.insert(std::pair<char, Character>(c, character));
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

		done_init = true;
	}

	void Text::Draw(App app)
	{
		if (!done_init) Init(app);

		// Activate corresponding render state	
		shader.Use();

		glUniform3f(glGetUniformLocation(shader.program, "textColor"), color.r, color.g, color.b);
		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(vao);

		float x = (float)transform.position.x;
		float y = (float)transform.position.y;

		// Iterate through all characters
		for (std::string::const_iterator c = message.begin(); c != message.end(); c++)
		{
			Character ch = characters[*c];

			float x_pos = (float)(x + ch.bearing.x * transform.scale.x);
			float y_pos = (float)(y - (ch.size.y - ch.bearing.y) * transform.scale.y);

			float width = (float)(ch.size.x * transform.scale.x);
			float height = (float)(ch.size.y * transform.scale.y);

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
			glBindTexture(GL_TEXTURE_2D, ch.texture_id);

			// Update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);

			// Advance cursors for next glyph (note that advance is number of 1/64 pixels)
			// Bitshift by 6 to get value in pixels (2^6 = 64)
			x += (float)((ch.advance >> 6) * transform.scale.x);
		}

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

} // namespace solar
