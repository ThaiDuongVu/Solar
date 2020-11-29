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
		Triangle(Color color = Color::White(), Color32 color32 = Color32::White());
		~Triangle();

		Color color_ = Color::White();

		void Init();
		void Draw(DrawMode draw_mode = DrawMode::kFill);

		void Move(Vector2 movement);

	private:
		// Vertex & fragment shader
		unsigned int vertex_shader_ = NULL;
		unsigned int fragment_shader_ = NULL;

		// Vertex buffer objects
		unsigned int vbo_ = NULL;
		// Vertex array object
		unsigned int vao_ = NULL;

		// Shader program
		unsigned int shader_program_ = NULL;

		const float scale_factor_ = 0.05f;

		// Vertices needed to draw a triangle
		Vector2 vertex_[3] = {
			Vector2(-transform_.scale_.x_, -transform_.scale_.y_) * scale_factor_,
			Vector2(transform_.scale_.x_, -transform_.scale_.y_) * scale_factor_,
			Vector2(0, transform_.scale_.y_) * scale_factor_
		};

		float vertices_[9] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		Shader shader = Shader("./default_vertex_shader.shader", "./default_fragment_shader.shader");

		void UpdateVertices();
	};
} // namespace solar


#endif // !SOLAR_TRIANGLE_H_
