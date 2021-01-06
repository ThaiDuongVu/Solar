#pragma once

#ifndef SOLAR_TEXT_H_
#define SOLAR_TEXT_H_

#include "../core.h"
#include "../app.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
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
		/// <param name="font">Text font</param>
		Text();
		/// <summary>
		/// Destructor.
		/// </summary>
		~Text();

		/// <summary>
		/// Text font.
		/// </summary>
		Font font = Font();

		/// <summary>
		/// Text color.
		/// </summary>
		Color color = Color::White();

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
		/// Whether text has been initialized.
		/// </summary>
		bool done_init = false;
	};

} // namespace solar

#endif // !SOLAR_TEXT_H_