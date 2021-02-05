#include "color.h"
#include "../mathf.h"

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

#pragma region Arithmetic Operators
	Color Color::operator+(Color other)
	{
		return Color(this->r + other.r, this->g + other.g, this->b + other.b, this->a + other.a);
	}
	Color Color::operator-(Color other)
	{
		return Color(this->r - other.r, this->g - other.g, this->b - other.b, this->a - other.a);
	}
	Color Color::operator*(Color other)
	{
		return Color(this->r * other.r, this->g * other.g, this->b * other.b, this->a * other.a);
	}
	Color Color::operator/(Color other)
	{
		return Color(this->r / other.r, this->g / other.g, this->b / other.b, this->a / other.a);
	}

	Color Color::operator+=(Color other)
	{
		*this = *this + other;
		return *this;
	}
	Color Color::operator-=(Color other)
	{
		*this = *this - other;
		return *this;
	}
	Color Color::operator*=(Color other)
	{
		*this = *this * other;
		return *this;
	}
	Color Color::operator/=(Color other)
	{
		*this = *this / other;
		return *this;
	}

	Color Color::operator+(float other)
	{
		return Color(this->r + other, this->g + other, this->b + other, this->a + other);
	}
	Color Color::operator-(float other)
	{
		return Color(this->r - other, this->g - other, this->b - other, this->a - other);
	}
	Color Color::operator*(float other)
	{
		return Color(this->r * other, this->g * other, this->b * other, this->a * other);
	}
	Color Color::operator/(float other)
	{
		return Color(this->r / other, this->g / other, this->b / other, this->a / other);
	}

	Color Color::operator+=(float other)
	{
		*this = *this + other;
		return *this;
	}
	Color Color::operator-=(float other)
	{
		*this = *this - other;
		return *this;
	}
	Color Color::operator*=(float other)
	{
		*this = *this * other;
		return *this;
	}
	Color Color::operator/=(float other)
	{
		*this = *this / other;
		return *this;
	}
#pragma endregion

#pragma region Logical Operators
	bool Color::operator==(Color other)
	{
		return (this->r == other.r && this->g == other.r && this->b == other.b && this->a == other.a);
	}
	bool Color::operator!=(Color other)
	{
		return (this->r != other.r || this->g != other.r || this->b != other.b || this->a != other.a);
	}
	bool Color::operator>(Color other)
	{
		return (this->r > other.r && this->g > other.r && this->b > other.b && this->a > other.a);
	}
	bool Color::operator>=(Color other)
	{
		return (this->r >= other.r && this->g >= other.r && this->b >= other.b && this->a >= other.a);
	}
	bool Color::operator<(Color other)
	{
		return (this->r < other.r && this->g < other.r && this->b < other.b && this->a < other.a);
	}
	bool Color::operator<=(Color other)
	{
		return (this->r <= other.r && this->g <= other.r && this->b <= other.b && this->a <= other.a);
	}
#pragma endregion

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

	Color Color::Red()
	{
		return Color(1.0f, 0.0f, 0.0f, 1.0f);
	}
	Color Color::Green()
	{
		return Color(0.0f, 1.0f, 0.0f, 1.0f);
	}
	Color Color::Blue()
	{
		return Color(0.0f, 0.0f, 1.0f, 1.0f);
	}
	Color Color::Yellow()
	{
		return Color(1.0f, 1.0f, 0.0f, 1.0f);
	}
	Color Color::Pink()
	{
		return Color(1.0f, 0.0f, 1.0f, 1.0f);
	}
	Color Color::Teal()
	{
		return Color(0.0f, 1.0f, 1.0f, 1.0f);
	}
	Color Color::White()
	{
		return Color(1.0f, 1.0f, 1.0f, 1.0f);
	}
	Color Color::Black()
	{
		return Color(0.0f, 0.0f, 0.0f, 1.0f);
	}

} // namespace Solar
