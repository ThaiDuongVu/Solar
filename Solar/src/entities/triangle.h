#pragma once

#ifndef SOLAR_TRIANGLE_H_
#define SOLAR_TRIANGLE_H_

#include "../core.h"
#include "../app.h"
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
		// Base constructor
		using GameObject::GameObject;

		// Constructor & destructor
		Triangle(Color color = Color::White());
		~Triangle();

		// Draw triangle
		void Draw(App app, DrawMode draw_mode = DrawMode::kFill);

		// Change triangle color
		void SetColor(Color color = Color::White());
		// Set whether object is bounded
		void SetBounded(bool is_bounded = false);

		// Move triangle using movement vector
		void Translate(Vector2 movement = Vector2::Zero());
		void Translate(double movement_x = 0.0f, double movement_y = 0.0f);

	private:
		// Vertex buffer objects
		unsigned int vbo_ = NULL;
		// Vertex array object
		unsigned int vao_ = NULL;

		// Triangle color
		Color color_ = Color::White();
		// Whether object is confined within window bound
		bool is_bounded_ = false;

		const float scale_factor_ = 0.1f;

		// Vertices needed to draw a triangle
		Vector2 vertex_[3] = { NULL, NULL, NULL };
		float vertices_[9] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		// Triangle shader
		Shader shader_ = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		// Initialization
		void Init(App app);
		// Update triangle vertices
		void Update(App app);
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
