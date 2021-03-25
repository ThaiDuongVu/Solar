#include "audio.h"

namespace Solar
{
	Audio::Audio(const char* path, double volume, double pitch)
	{
		this->path = path;
		this->volume = volume;
		this->pitch = pitch;
	}
	Audio::~Audio()
	{
	}
} // namespace Solar
