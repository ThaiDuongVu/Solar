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

		return Color(this->r, this->g, this->b, this->a);
	}

	std::string Color::ToString()
	{
		return "(" + std::to_string(this->r) + ", " + std::to_string(this->g) + ", " + std::to_string(this->b) + ", " + std::to_string(this->a) + ")";
	}

	Color Color::Normalize(Color color)
	{
		color.r = Mathf::Clamp(color.r, 0.0f, 1.0f);
		color.g = Mathf::Clamp(color.g, 0.0f, 1.0f);
		color.b = Mathf::Clamp(color.b, 0.0f, 1.0f);
		color.a = Mathf::Clamp(color.a, 0.0f, 1.0f);

		return Color(color.r, color.g, color.b, color.a);
	}

	std::string Color::ToString(Color color)
	{
		return "(" + std::to_string(color.r) + ", " + std::to_string(color.g) + ", " + std::to_string(color.b) + ", " + std::to_string(color.a) + ")";
	}

} // namespace solar
