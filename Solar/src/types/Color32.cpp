#include "color32.h"
#include "../mathf.h"

namespace solar
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

	Color Color32::Normalize()
	{
		this->r = Mathf::Clamp(this->r, 0, 255);
		this->g = Mathf::Clamp(this->g, 0, 255);
		this->b = Mathf::Clamp(this->b, 0, 255);
		this->a = Mathf::Clamp(this->a, 0, 255);

		float r = this->r / 255.0f;
		float g = this->g / 255.0f;
		float b = this->b / 255.0f;
		float a = this->a / 255.0f;

		return Color(r, g, b, a);
	}
} // namespace solar
