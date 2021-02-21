#include "game_object.h"
#include <glad.h>
#include <glfw3.h>

namespace Solar
{
	GameObject::GameObject(Transform transform, bool is_visible, bool is_parallax)
	{
		this->transform = transform;
		this->is_visible = is_visible;
		this->is_parallax = is_parallax;
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Move(Vector2 movement)
	{
		transform.position.Translate(movement);
	}
	void GameObject::Move(double movement_x, double movement_y)
	{
		transform.position.Translate(movement_x, movement_y);
	}

	void GameObject::Rotate(double rotation)
	{
		transform.rotation += rotation;

		if (transform.rotation >= 360.0f)
			transform.rotation = 0.0f;
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
		//TODO: Destroy this game object
	}
} // namespace Solar
