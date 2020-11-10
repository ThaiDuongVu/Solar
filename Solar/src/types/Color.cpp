#include "Color.h"

namespace Solar
{
	Color::Color(float r, float g, float b, float a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	Color::~Color()
	{
	}

	void Color::Clamp(float& value)
	{
		if (value > 1.0f)
		{
			value = 1.0f;
		}
		else if (value < 0.0f)
		{
			value = 0.0f;
		}
	}

	Color Color::Normalize()
	{
		Clamp(this->r);
		Clamp(this->g);
		Clamp(this->b);
		Clamp(this->a);

		return Color(r, g, b, a);
	}
};
