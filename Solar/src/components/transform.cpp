#include "transform.h"

namespace Solar
{
	Transform::Transform(Vector2 position, double rotation, Vector2 scale)
	{
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}
	Transform::~Transform()
	{

	}

	Transform Transform::Default()
	{
		return Transform();
	}
} // namespace Solar
