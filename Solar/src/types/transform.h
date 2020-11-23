#pragma once

#ifndef SOLAR_TRANSFORM_H_
#define SOLAR_TRANSFORM_H_

#include "../Core.h"
#include "vector2.h"
#include "quaternion.h"

namespace solar
{
	class SOLAR_API Transform
	{
	public:
		// Constructor & destructor
		Transform(Vector2 position = Vector2::Zero(), Quaternion rotation = Quaternion::Identity(), Vector2 scale = Vector2::Identity());
		~Transform();

		Vector2 position_; // Transform position
		Quaternion rotation_; // Transform rotation
		Vector2 scale_; // Transform scale

		static Transform Default(); // Default transform_
	};
} // namespace solar


#endif // !SOLAR_TRANSFORM_H_

