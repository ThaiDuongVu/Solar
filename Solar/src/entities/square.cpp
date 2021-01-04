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
	void Square::Update(App app)
	{
		// Square position
		double x = transform.position.x;
		double y = transform.position.y;

		// Square scale
		double width = transform.scale.x;
		double height = transform.scale.y;

		// Top left vertex
		vertex[0] = Vector2(x / (app.Width() / 2.0f) - width / app.Width(), y / (app.Height() / 2.0f) + height / app.Height());
		// Top right vertex
		vertex[1] = Vector2(x / (app.Width() / 2.0f) + width / app.Width(), y / (app.Height() / 2.0f) + height / app.Height());
		// Bottom left vertex
		vertex[2] = Vector2(x / (app.Width() / 2.0f) - width / app.Width(), y / (app.Height() / 2.0f) - height / app.Height());
		// Bottom right vertex
		vertex[3] = Vector2(x / (app.Width() / 2.0f) + width / app.Width(), y / (app.Height() / 2.0f) - height / app.Height());

		for (int i = 0; i < 4; i++)
		{
			vertex[i] = CalculateRotation(app, vertex[i]);
		}
		if (is_bounded) CalculateBound(app);

		vertices[0] = (float)vertex[0].x;
		vertices[1] = (float)vertex[0].y;
		vertices[3] = (float)vertex[1].x;
		vertices[4] = (float)vertex[1].y;
		vertices[6] = (float)vertex[2].x;
		vertices[7] = (float)vertex[2].y;
		vertices[9] = (float)vertex[3].x;
		vertices[10] = (float)vertex[3].y;
	}

	void Square::CalculateBound(App app)
	{
		// Bound horizontally
		double x_left_bound = (-(app.Width() / 2.0f) + transform.scale.x / 2.0f);
		double x_right_bound = -x_left_bound;
		if (transform.position.x < x_left_bound) transform.position.x = x_left_bound;
		else if (transform.position.x > x_right_bound) transform.position.x = x_right_bound;

		// Bound vertically
		double y_lower_bound = (-(app.Height() / 2.0f) + transform.scale.y / 2.0f);
		double y_upper_bound = -y_lower_bound;
		if (transform.position.y < y_lower_bound) transform.position.y = y_lower_bound;
		else if (transform.position.y > y_upper_bound) transform.position.y = y_upper_bound;
	}
	Vector2 Square::CalculateRotation(App app, Vector2 vertex)
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

	void Square::Draw(App app, DrawMode draw_mode)
	{
		// If object is not visible then return
		if (!this->is_visible) return;

		// Perform initialization if not already
		if (!done_init) Init(app);

		if (draw_mode == DrawMode::kFill)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		Update(app);

		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
		// Draw vertices
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 1, 4);
	}
} // namespace solar
