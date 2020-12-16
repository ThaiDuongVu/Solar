#include "transform.h"

namespace solar
{
	Transform::Transform(Vector2 position, double rotation, Vector2 scale)
	{
		this->position_ = position;
		this->rotation_ = rotation;
		this->scale_ = scale;
	}
	Transform::~Transform()
	{

	}

	Transform Transform::Default()
	{
		return Transform();
	}
} // namespace solar
