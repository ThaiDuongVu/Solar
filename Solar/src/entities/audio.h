#pragma once

#ifndef SOLAR_AUDIO_H
#define SOLAR_AUDIO_H

#include "../core.h"
#include "game_object.h"

namespace Solar
{
	class SOLAR_API Audio
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="path">Path to audio file</param>
		Audio(const char* path = "./resources/audio.wav", double volume = 1.0f, double pitch = 1.0f);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Audio();

		/// <summary>
		/// Path to audio file.
		/// </summary>
		const char* path;

		/// <summary>
		/// Current audio volume.
		/// </summary>
		double volume;
		
		/// <summary>
		/// Current audio pitch.
		/// </summary>
		double pitch;
	};
} // namespace Solar

#endif // !SOLAR_AUDIO_H