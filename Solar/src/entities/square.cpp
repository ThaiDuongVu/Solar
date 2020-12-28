#include "square.h"
#include "../mathf.h"
#include "../core.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

namespace solar
{
	Square::Square(Color color)
	{
		this->color = color;
	}
	Square::~Square()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		shader.Delete();
	}

	void Square::SetColor(Color color)
	{
		this->color = color;

		shader.Use();
		shader.SetFloat("red", this->color.r);
		shader.SetFloat("green", this->color.g);
		shader.SetFloat("blue", this->color.b);
		shader.SetFloat("alpha", this->color.a);
	}
	void Square::SetBounded(bool is_bounded)
	{
		this->is_bounded = is_bounded;
	}

	void Square::Init(App app)
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
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		SetColor(this->color);

		// Finish initialization
		done_init = true;
	}
	void Square::Update(App app)
	{
		// Square position
		double x = transform.position.x;
		double y = transform.position.y;

		// Square scale
		double width = transform.scale.x;
		double height = transform.scale.y;

		// Width & height scale factor
		double width_scale = (app.Width() / 2.0f * (double)scale_factor_);
		double height_scale = (app.Height() / 2.0f * (double)scale_factor_);

		// Top left vertex
		vertex[0] = Vector2(x / width_scale - width / 2.0f, y / height_scale + height / 2.0f) * scale_factor_;
		// Top right vertex
		vertex[1] = Vector2(x / width_scale + width / 2.0f, y / height_scale + height / 2.0f) * scale_factor_;
		// Bottom left vertex
		vertex[2] = Vector2(x / width_scale - width / 2.0f, y / height_scale - height / 2.0f) * scale_factor_;
		// Bottom right vertex
		vertex[3] = Vector2(x / width_scale + width / 2.0f, y / height_scale - height / 2.0f) * scale_factor_;

		for (int i = 0; i < 4; i++)
		{
			vertex[i] = CalculateRotation(app, vertex[i]);
			vertex[i] *= Vector2(OBJECT_SCALER / app.Width(), OBJECT_SCALER / app.Height());
		}
		if (is_bounded) Bound(app, width_scale, height_scale);

		vertices[0] = (float)vertex[0].x;
		vertices[1] = (float)vertex[0].y;
		vertices[3] = (float)vertex[1].x;
		vertices[4] = (float)vertex[1].y;
		vertices[6] = (float)vertex[2].x;
		vertices[7] = (float)vertex[2].y;
		vertices[9] = (float)vertex[3].x;
		vertices[10] = (float)vertex[3].y;

		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	}

	void Square::Bound(App app, double width_scale, double height_scale)
	{
		double x_left_bound = (-(app.Width() / 2.0f) + transform.scale.x / 2.0f * width_scale) / (OBJECT_SCALER / app.Width());
		double x_right_bound = ((app.Width() / 2.0f) - transform.scale.x / 2.0f * width_scale) / (OBJECT_SCALER / app.Width());

		if (transform.position.x < x_left_bound) transform.position.x = x_left_bound;
		else if (transform.position.x > x_right_bound) transform.position.x = x_right_bound;

		double y_lower_bound = (-(app.Height() / 2.0f) + transform.scale.y / 2.0f * height_scale) / (OBJECT_SCALER / app.Height());
		double y_upper_bound = ((app.Height() / 2.0f) - transform.scale.y / 2.0f * height_scale) / (OBJECT_SCALER / app.Height());

		if (transform.position.y < y_lower_bound) transform.position.y = y_lower_bound;
		else if (transform.position.y > y_upper_bound) transform.position.y = y_upper_bound;
	}
	Vector2 Square::CalculateRotation(App app, Vector2 vertex)
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

	void Square::Draw(App app, DrawMode draw_mode)
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
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
} // namespace solar
