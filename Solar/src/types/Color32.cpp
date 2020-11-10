#include "Color32.h"

namespace Solar
{
	Color32::Color32(int r, int g, int b, int a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	Color32::~Color32()
	{
	}

	void Color32::Clamp(int& value)
	{
		if (value > 255)
		{
			value = 255;
		}
		else if (value < 0)
		{
			value = 0;
		}
	}

	Color Color32::ToColor()
	{
		Clamp(this->r);
		Clamp(this->g);
		Clamp(this->b);
		Clamp(this->a);

		float r = this->r / 255.0f;
		float g = this->g / 255.0f;
		float b = this->b / 255.0f;
		float a = this->a / 255.0f;

		return Color(r, g, b, a);
	}
};
