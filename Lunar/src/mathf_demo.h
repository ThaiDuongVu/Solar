#include <solar.h>
using namespace Solar;

inline std::string BoolToString(bool value)
{
	return value ? "true" : "false";
}

/// <summary>
/// Demonstrate math methods provided.
/// </summary>
inline void MathfDemo()
{
	Debug::Log("Approximation tests:");
	Debug::LogColor(BoolToString(Mathf::Approximate(0.1f, 0.02f, 0.1f)), Solar::Debug::ColorLightGreen);
	Debug::LogColor(BoolToString(Mathf::Approximate(0.1f, 0.02f, 0.05f)), Solar::Debug::ColorRed);

	Debug::Log("Clamp tests:");
	Debug::LogColor(BoolToString(Mathf::Clamp(-1.0f, 0.0f, 1.0f)), Solar::Debug::ColorLightGreen);
	Debug::LogColor(BoolToString(Mathf::Clamp(-3, -5, -1)), Solar::Debug::ColorRed);

	Debug::Log("Absolute value tests:");
	Debug::LogColor(Mathf::Abs(-10), Solar::Debug::ColorLightGreen);
	Debug::LogColor(Mathf::Abs(2.5f), Solar::Debug::ColorLightGreen);

	Debug::Log("Ceiling tests:");
	Debug::LogColor(Mathf::Ceiling(-10.5f), Solar::Debug::ColorLightGreen);
	Debug::LogColor(Mathf::Ceiling(2.5f), Solar::Debug::ColorLightGreen);

	Debug::Log("Floor tests:");
	Debug::LogColor(Mathf::Floor(-10.5f), Solar::Debug::ColorLightGreen);
	Debug::LogColor(Mathf::Floor(2.5f), Solar::Debug::ColorLightGreen);

	Debug::Log("Minimum tests:");

	Debug::Log("Maximum tests:");

	Debug::Log("Modulus tests:");

	Debug::Log("Round tests:");

	Debug::Log("Round even tests:");

	Debug::Log("Power tests:");

	Debug::Log("Square root tests:");

	Debug::Log("Trigonometric tests:");

	Debug::Log("Randomization tests:");
}