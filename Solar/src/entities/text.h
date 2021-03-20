#pragma once

#ifndef SOLAR_TEXT_H_
#define SOLAR_TEXT_H_

#include <string>
#include <map>
#include "../core.h"
#include "../app.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
#include "../components/transform.h"
#include "../rendering/shader.h"
#include "../types/font.h"

namespace Solar
{
	class SOLAR_API Text : public GameObject
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="font">Initial font</param>
		/// <param name="message">Initial message</param>
		/// <param name="color">Initial color</param>
		Text(Transform transform = Transform::Default(), std::string message = "", Color color = Color::White(), Font font = Font(), bool is_visible = true, bool is_parallax = true);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Text();

		/// <summary>
		/// Text message.
		/// </summary>
		std::string message;

		/// <summary>
		/// Text font.
		/// </summary>
		Font font;

		/// <summary>
		/// Text color.
		/// </summary>
		Color color;

		/// <summary>
		/// Text shader.
		/// </summary>
		Shader shader = Shader("./resources/default_vertex_text_shader.shader", "./resources/default_fragment_text_shader.shader");

		/// <summary>
		/// Render text.
		/// </summary>
		/// <param name="app">Application to render on</param>
		void Draw(App app);

	private:
		/// <summary>
		/// Initialize text.
		/// </summary>
		/// <param name="app">Application to init on</param>
		void Init(App app);

		/// <summary>
		/// Vertex array object.
		/// </summary>
		unsigned int vao = NULL;
		/// <summary>
		/// Vertex buffer object.
		/// </summary>
		unsigned int vbo = NULL;

		/// <summary>
		/// Whether text has been initialized.
		/// </summary>
		bool done_init = false;

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
		/// <summary>
		/// Set of character in current font.
		/// </summary>
		std::map<char, Character> character_set;
	};

} // namespace Solar

#endif // !SOLAR_TEXT_H_