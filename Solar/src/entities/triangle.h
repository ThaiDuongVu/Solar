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

		// Constructor
		Triangle(Color color = Color::White());
		// Destructor
		~Triangle();

		// Draw triangle
		void Draw(App app, DrawMode draw_mode = DrawMode::kFill);

		// Change triangle color
		void SetColor(Color color = Color::White());
		// Set whether object is bounded
		void SetBounded(bool is_bounded = false);

	private:
		// Vertex buffer objects
		unsigned int vbo = NULL;
		// Vertex array object
		unsigned int vao = NULL;

		// Triangle color
		Color color = Color::White();
		// Whether object is confined within window bound
		bool is_bounded = false;

		const float scale_factor_ = 0.1f;

		// Vertices needed to draw a triangle
		Vector2 vertex[3] = { NULL, NULL, NULL };
		float vertices[9] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		// Triangle shader
		Shader shader = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		// Whether triangle is initialized
		bool done_init = false;

		// Initialization
		void Init(App app);
		// Update triangle vertices
		void Update(App app);

		// Limit object within the game window
		void Bound(App app, double width_scale, double height_scale);
		// Calculate vertex coordinates based on current rotation
		Vector2 CalculateRotation(App app, Vector2 vertex);
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
