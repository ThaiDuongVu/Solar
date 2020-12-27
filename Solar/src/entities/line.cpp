#include "line.h"
#include "../mathf.h"
#include "../core.h"
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
		glDrawArrays(GL_LINE_STRIP, 0, 2);
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

		Update(app);

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

		// Width & height scale factor
		double width_scale = (app.Width() / 2.0f * (double)scale_factor_);
		double height_scale = (app.Height() / 2.0f * (double)scale_factor_);

		// Down vertex
		vertex[0] = Vector2(x / width_scale, y / height_scale) * scale_factor_;
		vertex[0] = CalculateRotation(app, vertex[0]);
		vertex[0] *= Vector2(OBJECT_SCALER / app.Width(), OBJECT_SCALER / app.Height());

		// Up vertex
		vertex[1] = Vector2(x / width_scale, y / height_scale + length) * scale_factor_;
		vertex[1] = CalculateRotation(app, vertex[1]);
		vertex[1] *= Vector2(OBJECT_SCALER / app.Width(), OBJECT_SCALER / app.Height());

		if (is_bounded) Bound(app, width_scale, height_scale);

		vertices[0] = (float)vertex[0].x;
		vertices[1] = (float)vertex[0].y;
		vertices[3] = (float)vertex[1].x;
		vertices[4] = (float)vertex[1].y;

		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	}

	void Line::Bound(App app, double width_scale, double height_scale)
	{

	}

	Vector2 Line::CalculateRotation(App app, Vector2 vertex)
	{
		// Sine & Cosine of current rotation
		double sin = Mathf::Sin(Mathf::DegreeToRadian(transform.rotation));
		double cos = Mathf::Cos(Mathf::DegreeToRadian(transform.rotation));

		// Scale factors
		double x_scale = transform.position.x / app.Width() * 2.0f;
		double y_scale = transform.position.y / app.Height() * 2.0f;

		// Rotate vertex vector to match with current rotation
		return Vector2(cos * (vertex.x - x_scale) - sin * (vertex.y - y_scale) + x_scale, sin * (vertex.x - x_scale) + cos * (vertex.y - y_scale) + y_scale);
	}
} // namespace solar
