#include "Quaternion.h"
#include <iostream>
#include <glm.hpp>
#include <gtc/quaternion.hpp>

namespace Solar
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

	double Quaternion::Length()
	{
		return glm::length(quaterion);
	}
}
