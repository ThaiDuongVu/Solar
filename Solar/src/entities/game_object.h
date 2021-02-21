#pragma once

#ifndef SOLAR_GAME_OBJECT_H_
#define SOLAR_GAME_OBJECT_H_

#include "../core.h"
#include "../components/transform.h"

namespace Solar
{
	class SOLAR_API GameObject
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="transform">Initial object transform</param>
		/// <param name="is_visible">Initial object visibility</param>
		GameObject(Transform transform = Transform::Default(), bool is_visible = true, bool is_parallax = false);
		/// <summary>
		/// Destructor.
		/// </summary>
		~GameObject();

		enum class DrawMode 
		{
			Fill,
			Line
		};

		/// <summary>
		/// Object transform.
		/// </summary>
		Transform transform;

		/// <summary>
		/// Object visibility.
		/// </summary>
		bool is_visible = true;

		/// <summary>
		/// Whether object moves with viewport.
		/// </summary>
		bool is_parallax = false;

		/// <summary>
		/// Destroy current object.
		/// </summary>
		void Destroy();

		/// <summary>
		/// Move object with movement vector.
		/// </summary>
		/// <param name="movement">Movement vector</param>
		void Move(Vector2 movement = Vector2::Zero());
		/// <summary>
		/// Move object with x & y axis speed.
		/// </summary>
		/// <param name="movement_x">x axis speed</param>
		/// <param name="movement_y">y axis speed</param>
		void Move(double movement_x = 0.0f, double movement_y = 0.0f);

		/// <summary>
		/// Rotate object.
		/// </summary>
		/// <param name="rotation"></param>
		void Rotate(double rotation = 0.0f);

		/// <summary>
		/// Scale object with scale vector.
		/// </summary>
		/// <param name="scale">Scale vector</param>
		void Scale(Vector2 scale = Vector2::Zero());
		/// <summary>
		/// Scale object with x & y scale axis.
		/// </summary>
		/// <param name="scale_x">x scale axis</param>
		/// <param name="scale_y">y scale axis</param>
		void Scale(double scale_x = 0.0f, double scale_y = 0.0f);
	};
} // namespace Solar

#endif // !SOLAR_GAME_OBJECT_H_
