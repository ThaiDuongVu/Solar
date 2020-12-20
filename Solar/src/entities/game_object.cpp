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

	void GameObject::Move(Vector2 movement)
	{
		transform_.position_ += movement;
	}
	void GameObject::Move(double movement_x, double movement_y)
	{
		transform_.position_ += Vector2(movement_x, movement_y);
	}

	void GameObject::Rotate(double rotation)
	{
		transform_.rotation_ += rotation;
	}

	void GameObject::Destroy()
	{
		delete(this);
	}
} // namespace solar
