#include "color32.h"
#include "../mathf.h"

namespace solar
{
	Color32::Color32(unsigned int r, unsigned int g, unsigned int b, unsigned int a)
	{
		this->r_ = r;
		this->g_ = g;
		this->b_ = b;
		this->a_ = a;
	}
	Color32::~Color32()
	{
	}

	Color Color32::Normalize()
	{
		this->r_ = Mathf::Clamp(this->r_, 0, 255);
		this->g_ = Mathf::Clamp(this->g_, 0, 255);
		this->b_ = Mathf::Clamp(this->b_, 0, 255);
		this->a_ = Mathf::Clamp(this->a_, 0, 255);

		float r = this->r_ / 255.0f;
		float g = this->g_ / 255.0f;
		float b = this->b_ / 255.0f;
		float a = this->a_ / 255.0f;

		return Color(r, g, b, a);
	}
	std::string Color32::ToString()
	{
		return "(" + std::to_string(this->r_) + ", " + std::to_string(this->g_) + ", " + std::to_string(this->b_) + ", " + std::to_string(this->a_) + ")";
	}

#pragma region Arithmetic Operators
	Color32 Color32::operator+(Color32 other)
	{
		return Color32(this->r_ + other.r_, this->g_ + other.g_, this->b_ + other.b_, this->a_ + other.a_);
	}
	Color32 Color32::operator-(Color32 other)
	{
		return Color32(this->r_ - other.r_, this->g_ - other.g_, this->b_ - other.b_, this->a_ - other.a_);
	}
	Color32 Color32::operator*(Color32 other)
	{
		return Color32(this->r_ * other.r_, this->g_ * other.g_, this->b_ * other.b_, this->a_ * other.a_);
	}
	Color32 Color32::operator/(Color32 other)
	{
		return Color32(this->r_ / other.r_, this->g_ / other.g_, this->b_ / other.b_, this->a_ / other.a_);
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
		return Color32(this->r_ + other, this->g_ + other, this->b_ + other, this->a_ + other);
	}
	Color32 Color32::operator-(unsigned int other)
	{
		return Color32(this->r_ - other, this->g_ - other, this->b_ - other, this->a_ - other);
	}
	Color32 Color32::operator*(unsigned int other)
	{
		return Color32(this->r_ * other, this->g_ * other, this->b_ * other, this->a_ * other);
	}
	Color32 Color32::operator/(unsigned int other)
	{
		return Color32(this->r_ / other, this->g_ / other, this->b_ / other, this->a_ / other);
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
		return (this->r_ == other.r_ && this->g_ == other.r_ && this->b_ == other.b_ && this->a_ == other.a_);
	}
	bool Color32::operator!=(Color32 other)
	{
		return (this->r_ != other.r_ || this->g_ != other.r_ || this->b_ != other.b_ || this->a_ != other.a_);
	}
	bool Color32::operator>(Color32 other)
	{
		return (this->r_ > other.r_ && this->g_ > other.r_ && this->b_ > other.b_ && this->a_ > other.a_);
	}
	bool Color32::operator>=(Color32 other)
	{
		return (this->r_ >= other.r_ && this->g_ >= other.r_ && this->b_ >= other.b_ && this->a_ >= other.a_);
	}
	bool Color32::operator<(Color32 other)
	{
		return (this->r_ < other.r_&& this->g_ < other.r_&& this->b_ < other.b_&& this->a_ < other.a_);
	}
	bool Color32::operator<=(Color32 other)
	{
		return (this->r_ <= other.r_ && this->g_ <= other.r_ && this->b_ <= other.b_ && this->a_ <= other.a_);
	}
#pragma endregion

	Color Color32::Normalize(Color32 color)
	{
		color.r_ = Mathf::Clamp(color.r_, 0, 255);
		color.g_ = Mathf::Clamp(color.g_, 0, 255);
		color.b_ = Mathf::Clamp(color.b_, 0, 255);
		color.a_ = Mathf::Clamp(color.a_, 0, 255);

		float r = color.r_ / 255.0f;
		float g = color.g_ / 255.0f;
		float b = color.b_ / 255.0f;
		float a = color.a_ / 255.0f;

		return Color(r, g, b, a);
	}
	std::string Color32::ToString(Color32 color)
	{
		return "(" + std::to_string(color.r_) + ", " + std::to_string(color.g_) + ", " + std::to_string(color.b_) + ", " + std::to_string(color.a_) + ")";
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
} // namespace solar
