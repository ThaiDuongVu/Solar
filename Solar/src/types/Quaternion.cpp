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

	// Convert a quaternion to glm type
	glm::dquat glmQuaternion(Quaternion quaternion)
	{
		return glm::dquat(quaternion.w, quaternion.x, quaternion.y, quaternion.z);
	}

	double Quaternion::Length()
	{
		return glm::length(glmQuaternion(*this));
	}

	double Quaternion::Dot(Quaternion other)
	{
		return glm::dot(glmQuaternion(*this), glmQuaternion(other));
	}

	Quaternion Quaternion::Normalized()
	{
		return Quaternion(glm::normalize(glmQuaternion(*this)).x, glm::normalize(glmQuaternion(*this)).y, glm::normalize(glmQuaternion(*this)).z, glm::normalize(glmQuaternion(*this)).w);
	}

#pragma region Operators
	Quaternion Quaternion::operator+(Quaternion other)
	{
		glm::dquat quaternion = glm::operator+(glmQuaternion(*this), glmQuaternion(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator-(Quaternion other)
	{
		glm::dquat quaternion = glm::operator-(glmQuaternion(*this), glmQuaternion(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator*(Quaternion other)
	{
		glm::dquat quaternion = glm::operator*(glmQuaternion(*this), glmQuaternion(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);;
	}

	Quaternion Quaternion::operator*(double other)
	{
		glm::dquat quaternion = glm::operator*(glmQuaternion(*this), other);
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator/(double other)
	{
		glm::dquat quaternion = glm::operator/(glmQuaternion(*this), other);
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
#pragma endregion

	Quaternion Quaternion::Zero()
	{
		return Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
	}

	Quaternion Quaternion::Identity()
	{
		return Quaternion(1.0f, 1.0f, 1.0f, 1.0f);
	}

	double Quaternion::Length(Quaternion a)
	{
		return glm::length(glmQuaternion(a));
	}

	double Quaternion::Dot(Quaternion a, Quaternion b)
	{
		return glm::dot(glmQuaternion(a), glmQuaternion(b));
	}

	Quaternion Quaternion::Normalized(Quaternion a)
	{
		return Quaternion(glm::normalize(glmQuaternion(a)).x, glm::normalize(glmQuaternion(a)).y, glm::normalize(glmQuaternion(a)).z, glm::normalize(glmQuaternion(a)).w);
	}

} // namespace solar
