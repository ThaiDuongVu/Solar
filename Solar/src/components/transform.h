#pragma once

#ifndef SOLAR_TRANSFORM_H_
#define SOLAR_TRANSFORM_H_

#include "../core.h"
#include "../types/vector2.h"
#include "../types/quaternion.h"

namespace solar
{
	class SOLAR_API Transform
	{
	public:
		// Constructor & destructor
		Transform(Vector2 position = Vector2::Zero(), double rotation = 0.0f, Vector2 scale = Vector2::Identity());
		~Transform();

		Vector2 position_; // Transform position
		double rotation_; // Transform rotation
		Vector2 scale_; // Transform scale

		static Transform Default(); // Default transform
	};
} // namespace solar


#endif // !SOLAR_TRANSFORM_H_

