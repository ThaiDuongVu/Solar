#include "triangle.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

#include "../debug.h"

namespace solar
{
	bool done_init = false;

	const char* vertex_shader_source = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";

	const char* fragment_shader_source = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
		"}\0";

	Triangle::Triangle(Color color, Color32 color32)
	{
		this->color_ = color;
		this->color_ = color32.Normalize();
	}
	Triangle::~Triangle()
	{
		glDeleteVertexArrays(1, &vao_);
		glDeleteBuffers(1, &vbo_);
		glDeleteProgram(shader_program_);
	}

	void Triangle::Init()
	{
		shader.Init();

		// Draw triangle
		// Generate buffer and vertex array
		glGenBuffers(1, &vbo_);
		glGenVertexArrays(1, &vao_);

		UpdateVertices();

		// Bind buffer and vertex array
		glBindVertexArray(vao_);
		glBindBuffer(GL_ARRAY_BUFFER, vbo_);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

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

		//glUseProgram(shader_program_);
		shader.Use();
		glBindVertexArray(vao_);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Triangle::UpdateVertices()
	{
		vertex_[0] *= transform_.scale_;
		vertex_[1] *= transform_.scale_;
		vertex_[2] *= transform_.scale_;

		vertices_[0] = (float)vertex_[0].x_;
		vertices_[1] = (float)vertex_[0].y_;
		vertices_[3] = (float)vertex_[1].x_;
		vertices_[4] = (float)vertex_[1].y_;
		vertices_[6] = (float)vertex_[2].x_;
		vertices_[7] = (float)vertex_[2].y_;
	}

	void Triangle::Move(Vector2 movement)
	{
		vertex_[0].x_ += movement.x_;
		vertex_[1].x_ += movement.x_;
		vertex_[2].x_ += movement.x_;

		vertex_[0].y_ += movement.y_;
		vertex_[1].y_ += movement.y_;
		vertex_[2].y_ += movement.y_;

		// Update all triangle vertices
		UpdateVertices();
		// Re-initialization
		Init();
	}
} // namespace solar
