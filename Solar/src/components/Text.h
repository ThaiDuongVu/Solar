#pragma once

#ifndef SOLAR_TEXT_H_
#define SOLAR_TEXT_H_

#include "../Core.h"
#include "../types/Color.h"

namespace solar
{
	class SOLAR_API Text
	{
	public:
		const char *text;
		Color color;
	};
} // namespace solar

#endif // !SOLAR_TEXT_H_