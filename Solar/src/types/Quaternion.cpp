#include "quaternion.h"
#include <glm.hpp>
#include <gtc/quaternion.hpp>

namespace solar
{
	Quaternion::Quaternion(double x, double y, double z, double w)
	{
		this->x_ = x;
		this->y_ = y;
		this->z_ = z;
		this->w_ = z;
	}
	Quaternion::~Quaternion()
	{
	}

	// Convert a quaternion to glm type
	glm::dquat QuaternionToglm(Quaternion quaternion)
	{
		return glm::dquat(quaternion.w_, quaternion.x_, quaternion.y_, quaternion.z_);
	}
	// Convert glm to a Quaternion
	Quaternion glmToQuaternion(glm::dquat quaternion)
	{
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}

	double Quaternion::Length()
	{
		return glm::length(QuaternionToglm(*this));
	}
	double Quaternion::Dot(Quaternion other)
	{
		return glm::dot(QuaternionToglm(*this), QuaternionToglm(other));
	}
	Quaternion Quaternion::Normalized()
	{
		return Quaternion(glm::normalize(QuaternionToglm(*this)).x, glm::normalize(QuaternionToglm(*this)).y, glm::normalize(QuaternionToglm(*this)).z, glm::normalize(QuaternionToglm(*this)).w);
	}

	std::string Quaternion::ToString()
	{
		return "(" + std::to_string(this->x_) + ", " + std::to_string(this->y_) + ", " + std::to_string(this->z_) + ", " + std::to_string(this->w_) + ")";
	}

#pragma region Arithmetic Operators
	Quaternion Quaternion::operator+(Quaternion other)
	{
		glm::dquat quaternion = glm::operator+(QuaternionToglm(*this), QuaternionToglm(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator-(Quaternion other)
	{
		glm::dquat quaternion = glm::operator-(QuaternionToglm(*this), QuaternionToglm(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator*(Quaternion other)
	{
		glm::dquat quaternion = glm::operator*(QuaternionToglm(*this), QuaternionToglm(other));
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);;
	}

	Quaternion Quaternion::operator*(double other)
	{
		glm::dquat quaternion = glm::operator*(QuaternionToglm(*this), other);
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
	Quaternion Quaternion::operator/(double other)
	{
		glm::dquat quaternion = glm::operator/(QuaternionToglm(*this), other);
		return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
	}
#pragma endregion

#pragma region Logical Operators
	bool Quaternion::operator==(Quaternion other)
	{
		return glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).x == 1.0f && glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).y == 1.0f && glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).z == 1.0f && glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).w == 1.0f;
	}
	bool Quaternion::operator!=(Quaternion other)
	{
		return glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).x == 0.0f || glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).y == 0.0f || glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).z == 0.0f || glm::equal(QuaternionToglm(*this), QuaternionToglm(other)).w == 0.0f;
	}
	bool Quaternion::operator>(Quaternion other)
	{
		return glm::greaterThan(QuaternionToglm(*this), QuaternionToglm(other)).x == 1.0f && glm::greaterThan(QuaternionToglm(*this), QuaternionToglm(other)).y == 1.0f && glm::greaterThan(QuaternionToglm(*this), QuaternionToglm(other)).z == 1.0f && glm::greaterThan(QuaternionToglm(*this), QuaternionToglm(other)).w == 1.0f;
	}
	bool Quaternion::operator<(Quaternion other)
	{
		return glm::lessThan(QuaternionToglm(*this), QuaternionToglm(other)).x == 1.0f && glm::lessThan(QuaternionToglm(*this), QuaternionToglm(other)).y == 1.0f && glm::lessThan(QuaternionToglm(*this), QuaternionToglm(other)).z == 1.0f && glm::lessThan(QuaternionToglm(*this), QuaternionToglm(other)).w == 1.0f;
	}
	bool Quaternion::operator>=(Quaternion other)
	{
		return glm::greaterThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).x == 1.0f && glm::greaterThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).y == 1.0f && glm::greaterThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).z == 1.0f && glm::greaterThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).w == 1.0f;
	}
	bool Quaternion::operator<=(Quaternion other)
	{
		return glm::lessThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).x == 1.0f && glm::lessThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).y == 1.0f && glm::lessThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).z == 1.0f && glm::lessThanEqual(QuaternionToglm(*this), QuaternionToglm(other)).w == 1.0f;
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
		return glm::length(QuaternionToglm(a));
	}
	double Quaternion::Dot(Quaternion a, Quaternion b)
	{
		return glm::dot(QuaternionToglm(a), QuaternionToglm(b));
	}
	Quaternion Quaternion::Normalized(Quaternion a)
	{
		return Quaternion(glm::normalize(QuaternionToglm(a)).x, glm::normalize(QuaternionToglm(a)).y, glm::normalize(QuaternionToglm(a)).z, glm::normalize(QuaternionToglm(a)).w);
	}

	std::string Quaternion::ToString(Quaternion a)
	{
		return "(" + std::to_string(a.x_) + ", " + std::to_string(a.y_) + ", " + std::to_string(a.z_) + ", " + std::to_string(a.w_) + ")";
	}

} // namespace solar
