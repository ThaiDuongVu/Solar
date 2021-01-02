#include "triangle.h"
#include "../mathf.h"
#include "../core.h"
#include <glad.h>
#include <glfw3.h>
#include <glm.hpp>

namespace solar
{
	Triangle::Triangle(Color color)
	{
		this->color = color;
	}
	Triangle::~Triangle()
	{
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		shader.Delete();
	}

	void Triangle::SetColor(Color color)
	{
		this->color = color;

		shader.Use();
		shader.SetFloat("red", this->color.r);
		shader.SetFloat("green", this->color.g);
		shader.SetFloat("blue", this->color.b);
		shader.SetFloat("alpha", this->color.a);
	}
	void Triangle::SetBounded(bool is_bounded)
	{
		this->is_bounded = is_bounded;
	}

	void Triangle::Init(App app)
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
	void Triangle::Update(App app)
	{
		// Triangle position
		double x = transform.position.x;
		double y = transform.position.y;

		// Triangle scale
		double width = transform.scale.x;
		double height = transform.scale.y;

		// Left vertex
		vertex[0] = Vector2(x / (app.Width() / 2.0f) - width / app.Width(), y / (app.Height() / 2.0f) - height / app.Height());
		// Right vertex
		vertex[1] = Vector2(x / (app.Width() / 2.0f) + width / app.Width(), y / (app.Height() / 2.0f) - height / app.Height());
		// Up vertex
		vertex[2] = Vector2(x / (app.Width() / 2.0f), y / (app.Height() / 2.0f) + height / app.Height());

		for (int i = 0; i < 3; i++)
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
	}

	void Triangle::CalculateBound(App app)
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
	Vector2 Triangle::CalculateRotation(App app, Vector2 vertex)
	{
		// Sine & Cosine of current rotation
		double sin = Mathf::Sin(Mathf::DegreeToRadian(transform.rotation));
		double cos = Mathf::Cos(Mathf::DegreeToRadian(transform.rotation));

		// Point of rotation
		double x_point = transform.position.x / (app.Width() / 2.0f);
		double y_point = transform.position.y / (app.Height() / 2.0f);

		// Rotate vertex vector to match with current rotation
		return Vector2(cos * (vertex.x - x_point) - sin * (vertex.y - y_point) + x_point, sin * (vertex.x - x_point) + cos * (vertex.y - y_point) + y_point);
	}

	void Triangle::Draw(App app, DrawMode draw_mode)
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
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
} // namespace solar