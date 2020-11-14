#include "color.h"
#include "../mathf.h"

namespace solar
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

	Color Color::Normalize()
	{
		this->r = Mathf::Clamp(this->r, 0.0f, 1.0f);
		this->g = Mathf::Clamp(this->g, 0.0f, 1.0f);
		this->b = Mathf::Clamp(this->b, 0.0f, 1.0f);
		this->a = Mathf::Clamp(this->a, 0.0f, 1.0f);

		return Color(r, g, b, a);
	}
} // namespace solar
