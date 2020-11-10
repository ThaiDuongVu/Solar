#include "Vector2.h"
#include <glm.hpp>

namespace Solar
{
	glm::dvec2 vector2 = glm::dvec2(0.0f, 0.0f);

	void Vector2::Update()
	{
		this->x = vector2.x;
		this->y = vector2.y;
	}

	Vector2::~Vector2()
	{
		vector2.x = 0.0f;
		vector2.y = 0.0f;

		this->Update();
	}
	Vector2::Vector2(double x, double y)
	{
		vector2.x = x;
		vector2.y = y;

		this->Update();
	}

	double Vector2::Length()
	{
		return glm::length(vector2);
	}

	Vector2 Vector2::Normalized()
	{
		return Vector2(glm::normalize(vector2).x, glm::normalize(vector2).y);
	}
} // namespace Solar
