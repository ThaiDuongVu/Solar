#pragma once

#ifndef SOLAR_LINE_H_
#define SOLAR_LINE_H_

#include "../core.h"
#include "../app.h"
#include "game_object.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
#include "../rendering/shader.h"

namespace solar
{
	class SOLAR_API Line : public GameObject
	{
	public:
		// Base constructor
		using GameObject::GameObject;

		// Constructor & destructor
		Line(Color color = Color::White());
		~Line();

		// Draw Line
		void Draw(App app, DrawMode draw_mode = DrawMode::kLine);

		// Change Line color
		void SetColor(Color color = Color::White());
		// Set whether object is bounded
		void SetBounded(bool is_bounded = false);
		// Set line length
		void SetLength(double length = 1.0f);

	private:
		// Vertex buffer objects
		unsigned int vbo = NULL;
		// Vertex array object
		unsigned int vao = NULL;

		// Line color
		Color color = Color::White();
		// Whether object is confined within window bound
		bool is_bounded = false;
		// Line length
		double length = 1.0f;

		const float scale_factor_ = 0.1f;

		// Vertices needed to draw a Line
		Vector2 vertex[2] = { NULL, NULL };
		float vertices[6] = { NULL,NULL, NULL, NULL, NULL, NULL };

		// Line shader
		Shader shader = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		bool done_init = false;

		// Initialization
		void Init(App app);
		// Update Line vertices
		void Update(App app);

		// Limit object within the game window
		void Bound(App app, double width_scale, double height_scale);
		// Calculate vertex coordinates based on current rotation
		Vector2 CalculateRotation(App app, Vector2 vertex);
	};
} // namespace solar


#endif // !SOLAR_LINE_H_
