#include "vector2.h"
#include <iostream>
#include <glm.hpp>

namespace Solar
{
	Vector2::Vector2(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	Vector2::~Vector2()
	{
	}

	// Convert a Vector2 to glm type
	glm::dvec2 Vector2Toglm(Vector2 vector2)
	{
		return glm::dvec2(vector2.x, vector2.y);
	}
	// Convert glm to a Vector2
	Vector2 glmToVector2(glm::dvec2 vector2)
	{
		return Vector2(vector2.x, vector2.y);
	}

	void Vector2::Translate(Vector2 difference)
	{
		this->x += difference.x;
		this->y += difference.y;
	}

	void Vector2::Translate(double difference_x, double difference_y)
	{
		this->x += difference_x;
		this->y += difference_y;
	}

	double Vector2::Length()
	{
		return glm::length(Vector2Toglm(*this));
	}
	double Vector2::Distance(Vector2 other)
	{
		return glm::distance(Vector2Toglm(*this), Vector2Toglm(other));
	}
	double Vector2::Dot(Vector2 other)
	{
		return glm::dot(Vector2Toglm(*this), Vector2Toglm(other));
	}
	Vector2 Vector2::Normalized()
	{
		return Vector2(glm::normalize(Vector2Toglm(*this)).x, glm::normalize(Vector2Toglm(*this)).y);
	}

	std::string Vector2::ToString()
	{
		return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
	}

#pragma region Arithmetic Operators
	Vector2 Vector2::operator+(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator+(Vector2Toglm(*this), Vector2Toglm(other));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator-(Vector2Toglm(*this), Vector2Toglm(other));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator*(Vector2Toglm(*this), Vector2Toglm(other));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator/(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator/(Vector2Toglm(*this), Vector2Toglm(other));
		return Vector2(vector2.x, vector2.y);
	}

	Vector2 Vector2::operator+=(Vector2 other)
	{
		*this = *this + other;
		return *this;
	}
	Vector2 Vector2::operator-=(Vector2 other)
	{
		*this = *this - other;
		return *this;
	}
	Vector2 Vector2::operator*=(Vector2 other)
	{
		*this = *this * other;
		return *this;
	}
	Vector2 Vector2::operator/=(Vector2 other)
	{
		*this = *this / other;
		return *this;
	}

	Vector2 Vector2::operator+(double other)
	{
		glm::dvec2 vector2 = glm::operator+(Vector2Toglm(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(double other)
	{
		glm::dvec2 vector2 = glm::operator-(Vector2Toglm(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(double other)
	{
		glm::dvec2 vector2 = glm::operator*(Vector2Toglm(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator/(double other)
	{
		glm::dvec2 vector2 = glm::operator/(Vector2Toglm(*this), other);
		return Vector2(vector2.x, vector2.y);
	}

	Vector2 Vector2::operator+=(double other)
	{
		*this = *this + other;
		return *this;
	}
	Vector2 Vector2::operator-=(double other)
	{
		*this = *this - other;
		return *this;
	}
	Vector2 Vector2::operator*=(double other)
	{
		*this = *this * other;
		return *this;
	}
	Vector2 Vector2::operator/=(double other)
	{
		*this = *this / other;
		return *this;
	}
#pragma endregion

#pragma region Logical Operators
	bool Vector2::operator==(Vector2 other)
	{
		return glm::equal(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f && glm::equal(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
	bool Vector2::operator!=(Vector2 other)
	{
		return glm::notEqual(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f || glm::notEqual(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
	bool Vector2::operator>(Vector2 other)
	{
		return glm::greaterThan(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f && glm::greaterThan(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
	bool Vector2::operator<(Vector2 other)
	{
		return glm::lessThan(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f && glm::lessThan(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
	bool Vector2::operator>=(Vector2 other)
	{
		return glm::greaterThanEqual(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f && glm::greaterThanEqual(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
	bool Vector2::operator<=(Vector2 other)
	{
		return glm::lessThanEqual(Vector2Toglm(*this), Vector2Toglm(other)).x == 1.0f && glm::lessThanEqual(Vector2Toglm(*this), Vector2Toglm(other)).y == 1.0f;
	}
#pragma endregion

	Vector2 Vector2::Zero()
	{
		return Vector2(0.0f, 0.0f);
	}
	Vector2 Vector2::Identity()
	{
		return Vector2(1.0f, 1.0f);
	}

	Vector2 Vector2::UnitX()
	{
		return Vector2(1.0f, 0.0f);
	}
	Vector2 Vector2::UnitY()
	{
		return Vector2(0.0f, 1.0f);
	}

	Vector2 Vector2::Up()
	{
		return Vector2(0.0f, 1.0f);
	}
	Vector2 Vector2::Down()
	{
		return Vector2(0.0f, -1.0f);
	}
	Vector2 Vector2::Left()
	{
		return Vector2(-1.0f, 0.0f);
	}
	Vector2 Vector2::Right()
	{
		return Vector2(1.0f, 0.0f);
	}

	void Vector2::Translate(Vector2 a, Vector2 difference)
	{
		a.x += difference.x;
		a.y += difference.y;
	}
	void Vector2::Translate(Vector2 a, double difference_x, double difference_y)
	{
		a.x += difference_x;
		a.y += difference_y;
	}

	double Vector2::Length(Vector2 a)
	{
		return glm::length(Vector2Toglm(a));
	}
	double Vector2::Distance(Vector2 a, Vector2 b)
	{
		return glm::distance(Vector2Toglm(a), Vector2Toglm(b));
	}
	double Vector2::Dot(Vector2 a, Vector2 b)
	{
		return glm::dot(Vector2Toglm(a), Vector2Toglm(b));
	}
	Vector2 Vector2::Normalized(Vector2 a)
	{
		return Vector2(glm::normalize(Vector2Toglm(a)).x, glm::normalize(Vector2Toglm(a)).y);
	}

	std::string Vector2::ToString(Vector2 a)
	{
		return "(" + std::to_string(a.x) + ", " + std::to_string(a.y) + ")";
	}

} // namespace Solar
