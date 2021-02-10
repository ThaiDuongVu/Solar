#include "viewport.h"

namespace Solar
{
	Viewport::Viewport(Color color)
	{
		this->background_color = Color::Black();
	}
	Viewport::~Viewport()
	{
	}

	void Viewport::Shake(double intensity, double duration, double decrease_factor)
	{
	}

} // namespace Solar
