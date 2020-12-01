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
	};
} // namespace solar

#endif // !SOLAR_GAME_OBJECT_H_
