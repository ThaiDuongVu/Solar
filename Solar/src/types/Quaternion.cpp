#include "quaternion.h"
#include <glm.hpp>
#include <gtc/quaternion.hpp>

namespace solar
{
	glm::dquat quaterion = glm::dquat();

	Quaternion::Quaternion(double x, double y, double z, double w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = z;
	}
	Quaternion::~Quaternion()
	{
	}

	Quaternion Quaternion::Identity()
	{
		return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
	}

	double Quaternion::Length()
	{
		return glm::length(quaterion);
	}

	Quaternion Quaternion::Normalized()
	{
		return Quaternion(glm::normalize(quaterion).x, glm::normalize(quaterion).y, glm::normalize(quaterion).z, glm::normalize(quaterion).w);
	}
} // namespace solar
