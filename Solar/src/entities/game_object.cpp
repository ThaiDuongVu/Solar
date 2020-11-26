#include "game_object.h"

namespace solar
{
	GameObject::GameObject(Transform transform)
	{
		this->transform_ = transform;
	}
	GameObject::~GameObject()
	{
	}
} // namespace solar
