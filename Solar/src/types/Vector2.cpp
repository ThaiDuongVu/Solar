#include "Vector2.h"
#include <glm.hpp>

namespace Solar
{
	glm::vec2 vector2 = glm::vec2(0.0, 0.0);

	void Vector2::Update()
	{
		this->x = vector2.x;
		this->y = vector2.y;
	}

	Vector2::~Vector2()
	{
		vector2.x = 0.0;
		vector2.y = 0.0;

		this->Update();
	}
	Vector2::Vector2(double x, double y)
	{
		vector2.x = x;
		vector2.y = y;

		this->Update();
	}

	float Vector2::Length()
	{
		return glm::length(vector2);
	}
} // namespace Solar
