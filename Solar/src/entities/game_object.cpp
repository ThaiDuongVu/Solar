#include "game_object.h"
#include <glad.h>
#include <glfw3.h>

namespace solar
{
	GameObject::GameObject(Transform transform, bool is_visible)
	{
		this->transform = transform;
		this->is_visible = is_visible;
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Move(Vector2 movement)
	{
		transform.position += movement;
	}
	void GameObject::Move(double movement_x, double movement_y)
	{
		transform.position += Vector2(movement_x, movement_y);
	}

	void GameObject::Rotate(double rotation)
	{
		transform.rotation += rotation;
	}

	void GameObject::Scale(Vector2 scale)
	{
		transform.scale += scale;
	}
	void GameObject::Scale(double scale_x, double scale_y)
	{
		transform.scale += Vector2(scale_x, scale_y);
	}

	void GameObject::Destroy()
	{
		delete(this);
	}
} // namespace solar
