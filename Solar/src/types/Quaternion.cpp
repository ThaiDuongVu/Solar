#include "quaternion.h"
#include <glm.hpp>
#include <gtc/quaternion.hpp>

namespace solar
{
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
		return Quaternion(1.0f, 1.0f, 1.0f, 1.0f);
	}

	double Quaternion::Length()
	{
		glm::dquat quaternion = glm::dquat(this->x, this->y, this->z, this->w);
		return glm::length(quaternion);
	}

	Quaternion Quaternion::Normalized()
	{
		glm::dquat quaternion = glm::dquat(this->x, this->y, this->z, this->w);
		return Quaternion(glm::normalize(quaternion).x, glm::normalize(quaternion).y, glm::normalize(quaternion).z, glm::normalize(quaternion).w);
	}
} // namespace solar
