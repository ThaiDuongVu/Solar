#pragma once

#ifndef SOLAR_VIEWPORT_H_
#define SOLAR_VIEWPORT_H_

#include "core.h"
#include "entities/game_object.h"
#include "components/transform.h"
#include "types/color.h"
#include "types/color32.h"

namespace Solar
{
	class SOLAR_API Viewport : public GameObject
	{
	public:
		/// <summary>
		/// Base constructor.
		/// </summary>
		using GameObject::GameObject;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="transform">Initial transform</param>
		Viewport(Color color = Color::Black());
		/// <summary>
		/// Destructor.
		/// </summary>
		~Viewport();

		/// <summary>
		/// Viewport background color.
		/// </summary>
		Color background_color;

		/// <summary>
		/// Shake the current viewport.
		/// </summary>
		/// <param name="intensity">How rough to shake</param>
		/// <param name="duration">How long to shake for</param>
		/// <param name="decrease_factor">How fast to stop the shaking</param>
		void Shake(double intensity, double duration, double decrease_factor);
	};
} // namespace Solar

#endif // !SOLAR_VIEWPORT_H_