#include "vector2.h"
#include <glm.hpp>

namespace solar
{
	glm::dvec2 vector2 = glm::dvec2(0.0f, 0.0f);

	Vector2::Vector2(double x, double y)
	{
		this->x = x;
		this->y = y;

		vector2.x = x;
		vector2.y = y;
	}
	Vector2::~Vector2()
	{
	}

	Vector2 Vector2::Zero()
	{
		return Vector2(0.0f, 0.0f);
	}

	Vector2 Vector2::Identity()
	{
		return Vector2(1.0f, 1.0f);
	}

	double Vector2::Length()
	{
		return glm::length(vector2);
	}

	Vector2 Vector2::Normalized()
	{
		return Vector2(glm::normalize(vector2).x, glm::normalize(vector2).y);
	}

#pragma region Operators
	Vector2 Vector2::operator+(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator+(glm::dvec2(this->x, this->y), glm::dvec2(other.x, other.y));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator-(glm::dvec2(this->x, this->y), glm::dvec2(other.x, other.y));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator*(glm::dvec2(this->x, this->y), glm::dvec2(other.x, other.y));
		return Vector2(vector2.x, vector2.y);;
	}
	Vector2 Vector2::operator/(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator/(glm::dvec2(this->x, this->y), glm::dvec2(other.x, other.y));
		return Vector2(vector2.x, vector2.y);
	}

	Vector2 Vector2::operator+(double other)
	{
		glm::dvec2 vector2 = glm::operator+(glm::dvec2(this->x, this->y), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(double other)
	{
		glm::dvec2 vector2 = glm::operator-(glm::dvec2(this->x, this->y), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(double other)
	{
		glm::dvec2 vector2 = glm::operator*(glm::dvec2(this->x, this->y), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator/(double other)
	{
		glm::dvec2 vector2 = glm::operator/(glm::dvec2(this->x, this->y), other);
		return Vector2(vector2.x, vector2.y);
	}
#pragma endregion

} // namespace solar
