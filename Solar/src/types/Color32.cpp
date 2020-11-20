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

	std::string Color32::ToString()
	{
		return "(" + std::to_string(this->r) + ", " + std::to_string(this->g) + ", " + std::to_string(this->b) + ", " + std::to_string(this->a) + ")";
	}

	Color Color32::Normalize(Color32 color)
	{
		color.r = Mathf::Clamp(color.r, 0, 255);
		color.g = Mathf::Clamp(color.g, 0, 255);
		color.b = Mathf::Clamp(color.b, 0, 255);
		color.a = Mathf::Clamp(color.a, 0, 255);

		float r = color.r / 255.0f;
		float g = color.g / 255.0f;
		float b = color.b / 255.0f;
		float a = color.a / 255.0f;

		return Color(r, g, b, a);
	}

	std::string Color32::ToString(Color32 color)
	{
		return "(" + std::to_string(color.r) + ", " + std::to_string(color.g) + ", " + std::to_string(color.b) + ", " + std::to_string(color.a) + ")";
	}
} // namespace solar
