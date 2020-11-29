#include "triangle.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include "../debug.h"

namespace solar
{
	bool done_init = false;

	Triangle::Triangle(Color color)
	{
		this->color_ = color;
	}
	Triangle::~Triangle()
	{
		glDeleteVertexArrays(1, &vao_);
		glDeleteBuffers(1, &vbo_);
		shader_.Delete();
	}

	void Triangle::Init()
	{
		// Initialize shader
		shader_.Init();

		Update();

		// Generate buffer and vertex array
		glGenBuffers(1, &vbo_);
		glGenVertexArrays(1, &vao_);

		// Bind buffer and vertex array
		glBindVertexArray(vao_);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		shader_.Use();
		shader_.SetFloat("red", this->color_.r_);
		shader_.SetFloat("green", this->color_.g_);
		shader_.SetFloat("blue", this->color_.b_);
		shader_.SetFloat("alpha", this->color_.a_);

		// Finish initialization
		done_init = true;
	}

	void Triangle::Draw(DrawMode draw_mode)
	{
		// Perform initialization if not already
		if (!done_init) this->Init();

		if (draw_mode == DrawMode::kFill)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}

		Update();
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Triangle::Update()
	{
		vertex_[0] = Vector2(transform_.position_.x_ - transform_.scale_.x_, transform_.position_.y_ - transform_.scale_.y_);
		vertex_[1] = Vector2(transform_.position_.x_ + transform_.scale_.x_, transform_.position_.y_ - transform_.scale_.y_);
		vertex_[2] = Vector2(transform_.position_.x_, transform_.position_.y_ + transform_.scale_.y_);

		for (int i = 0; i < (sizeof(vertex_) / sizeof(vertex_[0])); i++)
		{
			vertex_[i] *= transform_.scale_ * scale_factor_;
		}

		vertices_[0] = (float)vertex_[0].x_;
		vertices_[1] = (float)vertex_[0].y_;
		vertices_[3] = (float)vertex_[1].x_;
		vertices_[4] = (float)vertex_[1].y_;
		vertices_[6] = (float)vertex_[2].x_;
		vertices_[7] = (float)vertex_[2].y_;

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_DYNAMIC_DRAW);
	}

	void Triangle::ChangeColor(Color color)
	{
		this->color_ = color;

		shader_.Use();
		shader_.SetFloat("red", this->color_.r_);
		shader_.SetFloat("green", this->color_.g_);
		shader_.SetFloat("blue", this->color_.b_);
		shader_.SetFloat("alpha", this->color_.a_);
	}
	void Triangle::Translate(Vector2 movement)
	{
		transform_.position_ += movement;
	}
} // namespace solar
