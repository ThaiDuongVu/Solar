#include "line.h"
#include "../mathf.h"
#include "../core.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

namespace Solar
{
	Line::Line(Transform transform, Color color, bool is_visible, bool is_parallax, bool is_bounded) : GameObject(transform, is_visible, is_parallax)
	{
		this->color = color;
		this->is_bounded = is_bounded;
	}
	Line::~Line()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		shader.Delete();
	}

	void Line::Init(App app)
	{
		// Initialize shader
		shader.Init();

		// Generate buffer and vertex array
		glGenBuffers(1, &vbo);
		glGenVertexArrays(1, &vao);

		// Finish initialization
		done_init = true;
	}
	void Line::Update(App app)
	{
		// Line position
		double x = transform.position.x;
		double y = transform.position.y;

		// Viewport position
		double viewport_x = (is_parallax) ? 0.0f : -app.viewport.transform.position.x;
		double viewport_y = (is_parallax) ? 0.0f : -app.viewport.transform.position.y;

		// Down vertex
		vertex[0] = Vector2(x / (app.Width() / 2.0f) + viewport_x, y / (app.Height() / 2.0f) + viewport_y);
		// Up vertex
		vertex[1] = Vector2(x / (app.Width() / 2.0f) + viewport_x, y / (app.Height() / 2.0f) + length / (app.Height()) + viewport_y);

		for (int i = 0; i < 2; i++)
		{
			vertex[i] = CalculateRotation(app, vertex[i]);
		}
		if (is_bounded) CalculateBound(app);

		vertices[0] = (float)vertex[0].x;
		vertices[1] = (float)vertex[0].y;
		vertices[2] = 0.0f;
		vertices[3] = color.r;
		vertices[4] = color.g;
		vertices[5] = color.b;

		vertices[6] = (float)vertex[1].x;
		vertices[7] = (float)vertex[1].y;
		vertices[8] = 0.0f;
		vertices[9] = color.r;
		vertices[10] = color.g;
		vertices[11] = color.b;
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
		// If object is not visible then don't render
		if (!this->is_visible) return;

		// Perform initialization if not already
		if (!done_init) this->Init(app);

		if (draw_mode == DrawMode::Fill)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		Update(app);

		/* ----- Offload this part to initialization instead? ----- */
		// Bind buffer and vertex array
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// Ativate shader
		shader.Use();
		/* -------------------------------------------------------- */

		// Draw vertices
		glDrawArrays(GL_LINE_STRIP, 0, 2);
	}
} // namespace Solar