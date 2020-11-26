#pragma once

#ifndef SOLAR_TRIANGLE_H_
#define SOLAR_TRIANGLE_H_

#include "../core.h"
#include "game_object.h"
#include "../types/color.h"
#include "../types/color32.h"

namespace solar
{
	class SOLAR_API Triangle : public GameObject
	{
	public:
		// Constructor & destructor
		using GameObject::GameObject;
		Triangle();
		//using GameObject::~GameObject;
		~Triangle();

		Color color_ = Color();

		void Render();
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
