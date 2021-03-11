#include "viewport.h"
#include "debug.h"
#include "mathf.h"
#include "game_time.h"

namespace Solar
{
	Viewport::Viewport(Transform transform, bool is_visible, bool is_parallax, Color color) : GameObject(transform, is_visible, is_parallax)
	{
		this->transform = transform;
		this->is_visible = is_visible;
		this->is_parallax = is_parallax;
		this->background_color = Color::Black();
	}
	Viewport::~Viewport()
	{
	}

	void Viewport::StartShaking(double intensity, double duration, double decrease_factor)
	{
		this->shake_intensity = intensity;
		this->shake_duration = duration;
		this->shake_decrease_factor = decrease_factor;

		this->is_shaking = true;
		original_position = this->transform.position;
	}
	void Viewport::StopShaking()
	{
		this->shake_intensity = 0.0f;
		this->shake_duration = 0.0f;
		this->shake_decrease_factor = 0.0f;

		this->is_shaking = false;
		this->transform.position = original_position;
		original_position = Vector2::Zero();
	}

	void Viewport::Shake()
	{
		// Decrease shake duration every frame
		shake_duration -= Time::FixedFrameTime() * shake_decrease_factor;

		// If shake duration runs out then stop shaking
		if (shake_duration <= 0.0f)
			StopShaking();

		// Randomize viewport position in intensity range
		this->transform.position = original_position + Vector2(Mathf::Random(-shake_intensity, shake_intensity), Mathf::Random(-shake_intensity, shake_intensity)) * Time::FixedFrameTime();
	}

} // namespace Solar
