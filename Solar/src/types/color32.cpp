#include "color32.h"
#include "../mathf.h"

namespace Solar
{
	Color32::Color32(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
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

#pragma region Arithmetic Operators
	Color32 Color32::operator+(Color32 other)
	{
		return Color32(this->r + other.r, this->g + other.g, this->b + other.b, this->a + other.a);
	}
	Color32 Color32::operator-(Color32 other)
	{
		return Color32(this->r - other.r, this->g - other.g, this->b - other.b, this->a - other.a);
	}
	Color32 Color32::operator*(Color32 other)
	{
		return Color32(this->r * other.r, this->g * other.g, this->b * other.b, this->a * other.a);
	}
	Color32 Color32::operator/(Color32 other)
	{
		return Color32(this->r / other.r, this->g / other.g, this->b / other.b, this->a / other.a);
	}

	Color32 Color32::operator+=(Color32 other)
	{
		*this = *this + other;
		return *this;
	}
	Color32 Color32::operator-=(Color32 other)
	{
		*this = *this - other;
		return *this;
	}
	Color32 Color32::operator*=(Color32 other)
	{
		*this = *this * other;
		return *this;
	}
	Color32 Color32::operator/=(Color32 other)
	{
		*this = *this / other;
		return *this;
	}

	Color32 Color32::operator+(unsigned int other)
	{
		return Color32(this->r + other, this->g + other, this->b + other, this->a + other);
	}
	Color32 Color32::operator-(unsigned int other)
	{
		return Color32(this->r - other, this->g - other, this->b - other, this->a - other);
	}
	Color32 Color32::operator*(unsigned int other)
	{
		return Color32(this->r * other, this->g * other, this->b * other, this->a * other);
	}
	Color32 Color32::operator/(unsigned int other)
	{
		return Color32(this->r / other, this->g / other, this->b / other, this->a / other);
	}

	Color32 Color32::operator+=(unsigned int other)
	{
		*this = *this + other;
		return *this;
	}
	Color32 Color32::operator-=(unsigned int other)
	{
		*this = *this - other;
		return *this;
	}
	Color32 Color32::operator*=(unsigned int other)
	{
		*this = *this * other;
		return *this;
	}
	Color32 Color32::operator/=(unsigned int other)
	{
		*this = *this / other;
		return *this;
	}
#pragma endregion

#pragma region Logical Operators
	bool Color32::operator==(Color32 other)
	{
		return (this->r == other.r && this->g == other.r && this->b == other.b && this->a == other.a);
	}
	bool Color32::operator!=(Color32 other)
	{
		return (this->r != other.r || this->g != other.r || this->b != other.b || this->a != other.a);
	}
	bool Color32::operator>(Color32 other)
	{
		return (this->r > other.r && this->g > other.r && this->b > other.b && this->a > other.a);
	}
	bool Color32::operator>=(Color32 other)
	{
		return (this->r >= other.r && this->g >= other.r && this->b >= other.b && this->a >= other.a);
	}
	bool Color32::operator<(Color32 other)
	{
		return (this->r < other.r&& this->g < other.r&& this->b < other.b&& this->a < other.a);
	}
	bool Color32::operator<=(Color32 other)
	{
		return (this->r <= other.r && this->g <= other.r && this->b <= other.b && this->a <= other.a);
	}
#pragma endregion

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

	Color32 Color32::Red()
	{
		return Color32(255, 0, 0, 255);
	}
	Color32 Color32::Green()
	{
		return Color32(0, 255, 0, 255);
	}
	Color32 Color32::Blue()
	{
		return Color32(0, 0, 255, 255);
	}
	Color32 Color32::Yellow()
	{
		return Color32(255, 255, 0, 255);
	}
	Color32 Color32::Pink()
	{
		return Color32(255, 0, 255, 255);
	}
	Color32 Color32::Teal()
	{
		return Color32(0, 255, 255, 255);
	}
	Color32 Color32::White()
	{
		return Color32(255, 255, 255, 255);
	}
	Color32 Color32::Black()
	{
		return Color32(0, 0, 0, 255);
	}
} // namespace Solar
