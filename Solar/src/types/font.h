#pragma once

#ifndef SOLAR_FONT_H_
#define SOLAR_FONT_H_

#include "../core.h"
#include "../debug.h"

namespace Solar
{
	class SOLAR_API Font
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="path">Initial path to font</param>
		/// <param name="width">Initial font width</param>
		/// <param name="height">Initial font height</param>
		Font(const char* path = "./resources/default_font.ttf", int width = 0, int height = 48);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Font();

		/// <summary>
		/// Path to font.
		/// </summary>
		const char* path;

		/// <summary>
		/// Font width.
		/// </summary>
		int width;
		/// <summary>
		/// Font height.
		/// </summary>
		int height;
	};
} // namespace Solar

#endif // !SOLAR_FONT_H_