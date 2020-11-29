#pragma once

#ifndef SOLAR_TRIANGLE_H_
#define SOLAR_TRIANGLE_H_

#include "../core.h"
#include "game_object.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
#include "../rendering/shader.h"

namespace solar
{
	class SOLAR_API Triangle : public GameObject
	{
	public:
		// Constructor & destructor
		using GameObject::GameObject;
		Triangle(Color color = Color::White());
		~Triangle();

		// Initialization
		void Init();
		// Draw triangle
		void Draw(DrawMode draw_mode = DrawMode::kFill);

		// Change triangle color
		void ChangeColor(Color color);
		// Move triangle using movement vector
		void Translate(Vector2 movement);

	private:
		// Vertex buffer objects
		unsigned int vbo_ = NULL;
		// Vertex array object
		unsigned int vao_ = NULL;

		// Triangle color
		Color color_ = Color::White();

		const float scale_factor_ = 0.075f;

		// Vertices needed to draw a triangle
		Vector2 vertex_[3] = { NULL, NULL, NULL };
		float vertices_[9] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		// Triangle shader
		Shader shader_ = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		// Update triangle vertices
		void Update();
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
