#pragma once

#ifndef SOLAR_TRANSFORM_H_
#define SOLAR_TRANSFORM_H_

#include "../core.h"
#include "../types/vector2.h"

namespace Solar
{
	class SOLAR_API Transform
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="position">Initial position</param>
		/// <param name="rotation">Initial rotation</param>
		/// <param name="scale">Initial scale</param>
		Transform(Vector2 position = Vector2::Zero(), double rotation = 0.0f, Vector2 scale = Vector2(50.0f, 50.0f));
		/// <summary>
		/// Destructor.
		/// </summary>
		~Transform();

		/// <summary>
		/// Transform position.
		/// </summary>
		Vector2 position;
		/// <summary>
		/// Transform rotation.
		/// </summary>
		double rotation;
		/// <summary>
		/// Transform scale.
		/// </summary>
		Vector2 scale;

		/// <summary>
		/// Returns default transform.
		/// </summary>
		/// <returns>Default transform</returns>
		static Transform Default();
	};
} // namespace Solar


#endif // !SOLAR_TRANSFORM_H_

