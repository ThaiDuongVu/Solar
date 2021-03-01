#pragma once

#ifndef SOLAR_VIEWPORT_H_
#define SOLAR_VIEWPORT_H_

#include "core.h"
#include "time.h"
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
		/// Constructor.
		/// </summary>
		/// <param name="transform">Initial transform</param>
		Viewport(Transform transform = Transform::Default(), bool is_visible = true, bool is_parallax = false, Color color = Color::Black());
		/// <summary>
		/// Destructor.
		/// </summary>
		~Viewport();

		/// <summary>
		/// Viewport background color.
		/// </summary>
		Color background_color;

		/// <summary>
		/// Start shaking the current viewport.
		/// </summary>
		/// <param name="intensity">How rough to shake</param>
		/// <param name="duration">How long to shake for</param>
		/// <param name="decrease_factor">How fast to stop the shaking</param>
		void StartShaking(double intensity = 0.0f, double duration = 0.0f, double decrease_factor = 0.0f);

		/// <summary>
		/// Stop shaking the current viewport.
		/// </summary>
		void StopShaking();

		/// <summary>
		/// Whether viewport is shaking or not.
		/// </summary>
		bool is_shaking = false;

		/// <summary>
		/// Randomize viewport position during shake period.
		/// Note: Shaking only affects non-parallax game objects.
		/// </summary>
		void Shake();

	private:
		/// <summary>
		/// How rough to shake.
		/// </summary>
		double shake_intensity = 0.0f;
		/// <summary>
		/// How long to shake for.
		/// </summary>
		double shake_duration = 0.0f;
		/// <summary>
		/// How fast to stop the shaking.
		/// </summary>
		double shake_decrease_factor = 0.0f;

		/// <summary>
		/// Viewport position when started shaking.
		/// </summary>
		Vector2 original_position = Vector2::Zero();
	};
} // namespace Solar

#endif // !SOLAR_VIEWPORT_H_