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

namespace Solar
{
	class SOLAR_API Line : public GameObject
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="color">Initial color</param>
		Line(Transform transform = Transform::Default(), Color color = Color::White(), bool is_visible = true, bool is_parallax = false, bool is_bounded = false);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Line();

		/// <summary>
		/// Line color.
		/// </summary>
		Color color = Color::White();
		/// <summary>
		/// Whether object is confined within window bound.
		/// </summary>
		bool is_bounded = false;
		/// <summary>
		/// Line length.
		/// </summary>
		double length = 50.0f;

		/// <summary>
		/// Render line.
		/// </summary>
		/// <param name="app">Application to render on</param>
		/// <param name="draw_mode">Which mode to draw</param>
		void Draw(App app, DrawMode draw_mode = DrawMode::Line);

	private:
		/// <summary>
		/// Vertex buffer objects.
		/// </summary>
		unsigned int vbo = NULL;
		/// <summary>
		/// Vertex array object.
		/// </summary>
		unsigned int vao = NULL;

		/// <summary>
		/// Vertices needed to draw a line.
		/// </summary>
		Vector2 vertex[2] = { NULL, NULL };
		float vertices[12] = {
			// Position data	// Color data
			0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f,	0.0f, 0.0f, 0.0f 
		};

		/// <summary>
		/// Line shader.
		/// </summary>
		Shader shader = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		/// <summary>
		/// Whether line has been initialized.
		/// </summary>
		bool done_init = false;

		/// <summary>
		/// Initialize line.
		/// </summary>
		/// <param name="app">Application to init on</param>
		void Init(App app);
		/// <summary>
		/// Update line vertices.
		/// </summary>
		/// <param name="app">Application to update on</param>
		void Update(App app);

		/// <summary>
		/// Limit object within the game window.
		/// </summary>
		/// <param name="app">Application to limit to</param>
		/// <param name="width_scale">Width scale of the window</param>
		/// <param name="height_scale">Height scale of the window</param>
		void CalculateBound(App app);

		/// <summary>
		/// Calculate vertex coordinates based on current rotation.
		/// </summary>
		/// <param name="app">Application to calculate on</param>
		/// <param name="vertex">Vertex to calculate</param>
		Vector2 CalculateRotation(App app, Vector2 vertex);
	};
} // namespace Solar


#endif // !SOLAR_LINE_H_
