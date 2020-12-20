#pragma once

#ifndef SOLAR_GAME_OBJECT_H_
#define SOLAR_GAME_OBJECT_H_

#include "../core.h"
#include "../components/transform.h"

namespace solar
{
	class SOLAR_API GameObject
	{
	public:
		// Constructor & destructor
		GameObject(Transform transform = Transform::Default(), bool is_visible = true);
		~GameObject();

		enum class DrawMode 
		{
			kFill,
			kLine
		};

		Transform transform_;
		bool is_visible_ = true;

		void Destroy();

		// Move object using movement vector
		void Move(Vector2 movement = Vector2::Zero());
		void Move(double movement_x = 0.0f, double movement_y = 0.0f);

		// Rotate object
		void Rotate(double rotation = 0.0f);
	};
} // namespace solar

#endif // !SOLAR_GAME_OBJECT_H_
