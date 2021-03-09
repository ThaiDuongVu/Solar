#pragma once

#ifndef SOLAR_AUDIO_H
#define SOLAR_AUDIO_H

#include "../core.h"
#include "game_object.h"

namespace Solar
{
	class SOLAR_API Audio : public GameObject
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		Audio(Transform transform = Transform::Default(), bool is_visible = true, bool is_parallax = true);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Audio();
	};
} // namespace Solar

#endif // !SOLAR_AUDIO_H