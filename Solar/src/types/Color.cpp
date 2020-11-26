#include "color.h"
#include "../mathf.h"

namespace solar
{
	Color::Color(float r, float g, float b, float a)
	{
		this->r_ = r;
		this->g_ = g;
		this->b_ = b;
		this->a_ = a;
	}
	Color::~Color()
	{
	}

	Color Color::Normalize()
	{
		this->r_ = Mathf::Clamp(this->r_, 0.0f, 1.0f);
		this->g_ = Mathf::Clamp(this->g_, 0.0f, 1.0f);
		this->b_ = Mathf::Clamp(this->b_, 0.0f, 1.0f);
		this->a_ = Mathf::Clamp(this->a_, 0.0f, 1.0f);

		return Color(this->r_, this->g_, this->b_, this->a_);
	}
	std::string Color::ToString()
	{
		return "(" + std::to_string(this->r_) + ", " + std::to_string(this->g_) + ", " + std::to_string(this->b_) + ", " + std::to_string(this->a_) + ")";
	}

#pragma region Arithmetic Operators
	Color Color::operator+(Color other)
	{
		return Color(this->r_ + other.r_, this->g_ + other.g_, this->b_ + other.b_, this->a_ + other.a_);
	}
	Color Color::operator-(Color other)
	{
		return Color(this->r_ - other.r_, this->g_ - other.g_, this->b_ - other.b_, this->a_ - other.a_);
	}
	Color Color::operator*(Color other)
	{
		return Color(this->r_ * other.r_, this->g_ * other.g_, this->b_ * other.b_, this->a_ * other.a_);
	}
	Color Color::operator/(Color other)
	{
		return Color(this->r_ / other.r_, this->g_ / other.g_, this->b_ / other.b_, this->a_ / other.a_);
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
		return Color(this->r_ + other, this->g_ + other, this->b_ + other, this->a_ + other);
	}
	Color Color::operator-(float other)
	{
		return Color(this->r_ - other, this->g_ - other, this->b_ - other, this->a_ - other);
	}
	Color Color::operator*(float other)
	{
		return Color(this->r_ * other, this->g_ * other, this->b_ * other, this->a_ * other);
	}
	Color Color::operator/(float other)
	{
		return Color(this->r_ / other, this->g_ / other, this->b_ / other, this->a_ / other);
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
		return (this->r_ == other.r_ && this->g_ == other.r_ && this->b_ == other.b_ && this->a_ == other.a_);
	}
	bool Color::operator!=(Color other)
	{
		return (this->r_ != other.r_ || this->g_ != other.r_ || this->b_ != other.b_ || this->a_ != other.a_);
	}
	bool Color::operator>(Color other)
	{
		return (this->r_ > other.r_ && this->g_ > other.r_ && this->b_ > other.b_ && this->a_ > other.a_);
	}
	bool Color::operator>=(Color other)
	{
		return (this->r_ >= other.r_ && this->g_ >= other.r_ && this->b_ >= other.b_ && this->a_ >= other.a_);
	}
	bool Color::operator<(Color other)
	{
		return (this->r_ < other.r_ && this->g_ < other.r_ && this->b_ < other.b_ && this->a_ < other.a_);
	}
	bool Color::operator<=(Color other)
	{
		return (this->r_ <= other.r_ && this->g_ <= other.r_ && this->b_ <= other.b_ && this->a_ <= other.a_);
	}
#pragma endregion

	Color Color::Normalize(Color color)
	{
		color.r_ = Mathf::Clamp(color.r_, 0.0f, 1.0f);
		color.g_ = Mathf::Clamp(color.g_, 0.0f, 1.0f);
		color.b_ = Mathf::Clamp(color.b_, 0.0f, 1.0f);
		color.a_ = Mathf::Clamp(color.a_, 0.0f, 1.0f);

		return Color(color.r_, color.g_, color.b_, color.a_);
	}
	std::string Color::ToString(Color color)
	{
		return "(" + std::to_string(color.r_) + ", " + std::to_string(color.g_) + ", " + std::to_string(color.b_) + ", " + std::to_string(color.a_) + ")";
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

} // namespace solar
