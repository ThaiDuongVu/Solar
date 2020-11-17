#include "vector2.h"
#include <iostream>
#include <glm.hpp>

namespace solar
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
	glm::dvec2 glmVector(Vector2 vector2)
	{
		return glm::dvec2(vector2.x, vector2.y);
	}

	double Vector2::Length()
	{
		return glm::length(glmVector(*this));
	}
	double Vector2::Distance(Vector2 other)
	{
		return glm::distance(glmVector(*this), glmVector(other));
	}
	double Vector2::Dot(Vector2 other)
	{
		return glm::dot(glmVector(*this), glmVector(other));
	}
	Vector2 Vector2::Normalized()
	{
		return Vector2(glm::normalize(glmVector(*this)).x, glm::normalize(glmVector(*this)).y);
	}

#pragma region Operators
	Vector2 Vector2::operator+(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator+(glmVector(*this), glmVector(other));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator-(glmVector(*this), glmVector(other));
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator*(glmVector(*this), glmVector(other));
		return Vector2(vector2.x, vector2.y);;
	}
	Vector2 Vector2::operator/(Vector2 other)
	{
		glm::dvec2 vector2 = glm::operator/(glmVector(*this), glmVector(other));
		return Vector2(vector2.x, vector2.y);
	}

	Vector2 Vector2::operator+(double other)
	{
		glm::dvec2 vector2 = glm::operator+(glmVector(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator-(double other)
	{
		glm::dvec2 vector2 = glm::operator-(glmVector(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator*(double other)
	{
		glm::dvec2 vector2 = glm::operator*(glmVector(*this), other);
		return Vector2(vector2.x, vector2.y);
	}
	Vector2 Vector2::operator/(double other)
	{
		glm::dvec2 vector2 = glm::operator/(glmVector(*this), other);
		return Vector2(vector2.x, vector2.y);
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

	double Vector2::Length(Vector2 a)
	{
		return glm::length(glmVector(a));
	}
	double Vector2::Distance(Vector2 a, Vector2 b)
	{
		return glm::distance(glmVector(a), glmVector(b));
	}
	double Vector2::Dot(Vector2 a, Vector2 b)
	{
		return glm::dot(glmVector(a), glmVector(b));
	}
	Vector2 Vector2::Normalized(Vector2 a)
	{
		return Vector2(glm::normalize(glmVector(a)).x, glm::normalize(glmVector(a)).y);
	}

} // namespace solar
