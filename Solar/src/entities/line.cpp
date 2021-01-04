#include "line.h"
#include "../mathf.h"
#include "../core.h"
#include "../debug.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

namespace solar
{
	Line::Line(Color color)
	{
		this->color = color;
	}
	Line::~Line()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		shader.Delete();
	}

	void Line::SetColor(Color color)
	{
		this->color = color;

		shader.Use();
		shader.SetFloat("red", this->color.r);
		shader.SetFloat("green", this->color.g);
		shader.SetFloat("blue", this->color.b);
		shader.SetFloat("alpha", this->color.a);
	}
	void Line::SetBounded(bool is_bounded)
	{
		this->is_bounded = is_bounded;
	}
	void Line::SetLength(double length)
	{
		this->length = length;
	}

	void Line::Init(App app)
	{
		// Initialize shader
		shader.Init();

		// Generate buffer and vertex array
		glGenBuffers(1, &vbo);
		glGenVertexArrays(1, &vao);

		// Bind buffer and vertex array
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		SetColor(this->color);

		// Finish initialization
		done_init = true;
	}
	void Line::Update(App app)
	{
		// Line position
		double x = transform.position.x;
		double y = transform.position.y;

		// Down vertex
		vertex[0] = Vector2(x / (app.Width() / 2.0f), y / (app.Height() / 2.0f));
		// Up vertex
		vertex[1] = Vector2(x / (app.Width() / 2.0f), y / (app.Height() / 2.0f) + length / (app.Height()));

		for (int i = 0; i < 2; i++)
		{
			vertex[i] = CalculateRotation(app, vertex[i]);
		}
		//Debug::Log(vertex[1].ToString());
		if (is_bounded) CalculateBound(app);

		vertices[0] = (float)vertex[0].x;
		vertices[1] = (float)vertex[0].y;
		vertices[3] = (float)vertex[1].x;
		vertices[4] = (float)vertex[1].y;
	}

	void Line::CalculateBound(App app)
	{

	}
	Vector2 Line::CalculateRotation(App app, Vector2 vertex)
	{
		// Sine & Cosine of current rotation
		double sin = Mathf::Sin(Mathf::DegreeToRadian(transform.rotation));
		double cos = Mathf::Cos(Mathf::DegreeToRadian(transform.rotation));

		// Point of rotation
		double x_point = transform.position.x;
		double y_point = transform.position.y;

		// Current vertex point
		double vertex_x = vertex.x * (app.Width() / 2.0f);
		double vertex_y = vertex.y * (app.Height() / 2.0f);

		// Rotate vertex vector to match with current rotation
		return (Vector2(x_point, y_point)
			+ Vector2(cos * (vertex_x - x_point) - sin * (vertex_y - y_point), sin * (vertex_x - x_point) + cos * (vertex_y - y_point)))
			/ Vector2((app.Width() / 2.0f), (app.Height() / 2.0f));
	}

	void Line::Draw(App app, DrawMode draw_mode)
	{
		// If object is not visible then return
		if (!this->is_visible) return;

		// Perform initialization if not already
		if (!done_init) this->Init(app);

		if (draw_mode == DrawMode::kFill)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		Update(app);

		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
		// Draw vertices
		glDrawArrays(GL_LINE_STRIP, 0, 2);
	}
} // namespace solar