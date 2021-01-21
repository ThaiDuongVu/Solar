#pragma once

#ifndef SOLAR_TEXT_H_
#define SOLAR_TEXT_H_

#include <string>
#include "../core.h"
#include "../app.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
#include "../components/transform.h"
#include "../rendering/shader.h"
#include "../types/font.h"

namespace solar
{
	class SOLAR_API Text
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="font">Initial font</param>
		/// <param name="message">Initial message</param>
		/// <param name="color">Initial color</param>
		Text(std::string message = "", Color color = Color::White(), Transform transform = Transform(), Font font = Font());
		/// <summary>
		/// Destructor.
		/// </summary>
		~Text();

		/// <summary>
		/// Text transform.
		/// </summary>
		Transform transform;

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
	};

} // namespace solar

#endif // !SOLAR_TEXT_H_