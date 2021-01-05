#pragma once

#ifndef SOLAR_Square_H_
#define SOLAR_Square_H_

#include "../core.h"
#include "../app.h"
#include "game_object.h"
#include "../types/color.h"
#include "../types/color32.h"
#include "../types/vector2.h"
#include "../rendering/shader.h"

namespace solar
{
	class SOLAR_API Square : public GameObject
	{
	public:
		/// <summary>
		/// Base constructor.
		/// </summary>
		using GameObject::GameObject;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="color">Initial color</param>
		Square(Color color = Color::White());
		/// <summary>
		/// Destructor.
		/// </summary>
		~Square();

		/// <summary>
		/// Square color.
		/// </summary>
		Color color = Color::White();
		/// <summary>
		/// Whether object is confined within window bound.
		/// </summary>
		bool is_bounded = false;

		/// <summary>
		/// Render square.
		/// </summary>
		/// <param name="app">Application to render on</param>
		/// <param name="draw_mode">Which mode to draw</param>
		void Draw(App app, DrawMode draw_mode = DrawMode::kFill);

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
		/// Vertices needed to draw a Square.
		/// </summary>
		Vector2 vertex[4] = { NULL, NULL, NULL, NULL };
		float vertices[12] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		/// <summary>
		/// Square shader.
		/// </summary>
		Shader shader = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		/// <summary>
		/// Whether square has been initialized.
		/// </summary>
		bool done_init = false;

		/// <summary>
		/// Initialize square.
		/// </summary>
		/// <param name="app">Application to init on</param>
		void Init(App app);
		/// <summary>
		/// Update square vertices.
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

} // namespace solar

#endif // !SOLAR_Square_H_

