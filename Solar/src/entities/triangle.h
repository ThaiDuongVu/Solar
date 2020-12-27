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
		/// <summary>
		/// Base constructor.
		/// </summary>
		using GameObject::GameObject;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="color">Initial color</param>
		Triangle(Color color = Color::White());
		/// <summary>
		/// Destructor.
		/// </summary>
		~Triangle();

		/// <summary>
		/// Render triangle.
		/// </summary>
		/// <param name="app">Application to render on</param>
		/// <param name="draw_mode">Which mode to draw</param>
		void Draw(App app, DrawMode draw_mode = DrawMode::kFill);

		/// <summary>
		/// Change triangle color.
		/// </summary>
		/// <param name="color">Color to set</param>
		void SetColor(Color color = Color::White());
		/// <summary>
		/// Set whether object is bounded.
		/// </summary>
		/// <param name="is_bounded">Value to set</param>
		void SetBounded(bool is_bounded = false);

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
		/// Triangle color.
		/// </summary>
		Color color = Color::White();
		/// <summary>
		/// Whether object is confined within window bound.
		/// </summary>
		bool is_bounded = false;

		const float scale_factor_ = 0.1f;

		/// <summary>
		/// Vertices needed to draw a triangle.
		/// </summary>
		Vector2 vertex[3] = { NULL, NULL, NULL };
		float vertices[9] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		/// <summary>
		/// Triangle shader.
		/// </summary>
		Shader shader = Shader("./resources/default_vertex_shader.shader", "./resources/default_fragment_shader.shader");

		/// <summary>
		/// Whether triangle has been initialized.
		/// </summary>
		bool done_init = false;

		/// <summary>
		/// Initialize triangle.
		/// </summary>
		/// <param name="app">Application to init on</param>
		void Init(App app);
		/// <summary>
		/// Update triangle vertices.
		/// </summary>
		/// <param name="app">Application to update on</param>
		void Update(App app);

		/// <summary>
		/// Limit object within the game window.
		/// </summary>
		/// <param name="app">Application to limit to</param>
		/// <param name="width_scale">Width scale of the window</param>
		/// <param name="height_scale">Height scale of the window</param>
		void Bound(App app, double width_scale, double height_scale);
		
		/// <summary>
		/// Calculate vertex coordinates based on current rotation.
		/// </summary>
		/// <param name="app">Application to calculate on</param>
		/// <param name="vertex">Vertex to calculate</param>
		Vector2 CalculateRotation(App app, Vector2 vertex);
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
