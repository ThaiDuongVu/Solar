#include "game_object.h"
#include <glad.h>
#include <glfw3.h>

namespace solar
{
	GameObject::GameObject(Transform transform, bool is_visible)
	{
		this->transform_ = transform;
		this->is_visible_ = is_visible;
	}
	GameObject::~GameObject()
	{
	}
} // namespace solar
