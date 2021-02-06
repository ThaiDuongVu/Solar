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

		Color color;
	};
} // namespace Solar

#endif // !SOLAR_VIEWPORT_H_