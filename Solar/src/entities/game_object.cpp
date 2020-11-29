#include "game_object.h"
#include <glad.h>
#include <glfw3.h>

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
