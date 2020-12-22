#include "triangle.h"
#include "../mathf.h"
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

	void Triangle::Draw(App app, DrawMode draw_mode)
	{
		// If object is not visible then return
		if (!this->is_visible_) return;

		// Perform initialization if not already
		if (!done_init) this->Init(app);

		if (draw_mode == DrawMode::kFill)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		Update(app);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Triangle::SetColor(Color color)
	{
		this->color_ = color;

		shader_.Use();
		shader_.SetFloat("red", this->color_.r_);
		shader_.SetFloat("green", this->color_.g_);
		shader_.SetFloat("blue", this->color_.b_);
		shader_.SetFloat("alpha", this->color_.a_);
	}
	void Triangle::SetBounded(bool is_bounded)
	{
		this->is_bounded_ = is_bounded;
	}

	void Triangle::Init(App app)
	{
		// Initialize shader
		shader_.Init();

		Update(app);

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

		SetColor(this->color_);

		// Finish initialization
		done_init = true;
	}
	void Triangle::Update(App app)
	{
		// Triangle position
		double x = transform_.position_.x_;
		double y = transform_.position_.y_;

		// Triangle scale
		double width = transform_.scale_.x_;
		double height = transform_.scale_.y_;

		// Width & height scale factor
		double width_scale = (app.Width() / 2.0f * (double)scale_factor_);
		double height_scale = (app.Height() / 2.0f * (double)scale_factor_);

		// Left vertex
		vertex_[0] = Vector2(x / width_scale - width / 2.0f, y / height_scale - height / 2.0f) * scale_factor_;
		vertex_[0] = CalculateRotation(app, vertex_[0]);

		// Right vertex
		vertex_[1] = Vector2(x / width_scale + width / 2.0f, y / height_scale - height / 2.0f) * scale_factor_;
		vertex_[1] = CalculateRotation(app, vertex_[1]);

		// Up vertex
		vertex_[2] = Vector2(x / width_scale, y / height_scale + height / 2.0f) * scale_factor_;
		vertex_[2] = CalculateRotation(app, vertex_[2]);

		if (is_bounded_) Bound(app, width_scale, height_scale);

		vertices_[0] = (float)vertex_[0].x_;
		vertices_[1] = (float)vertex_[0].y_;
		vertices_[3] = (float)vertex_[1].x_;
		vertices_[4] = (float)vertex_[1].y_;
		vertices_[6] = (float)vertex_[2].x_;
		vertices_[7] = (float)vertex_[2].y_;

		// Buffer vertices
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_), vertices_, GL_DYNAMIC_DRAW);
	}

	void Triangle::Bound(App app, double width_scale, double height_scale)
	{
		double x_left_bound = -(app.Width() / 2.0f) + transform_.scale_.x_ / 2.0f * width_scale;
		double x_right_bound = (app.Width() / 2.0f) - transform_.scale_.x_ / 2.0f * width_scale;

		if (transform_.position_.x_ < x_left_bound) transform_.position_.x_ = x_left_bound;
		else if (transform_.position_.x_ > x_right_bound) transform_.position_.x_ = x_right_bound;

		double y_lower_bound = -(app.Height() / 2.0f) + transform_.scale_.y_ / 2.0f * height_scale;
		double y_upper_bound = (app.Height() / 2.0f) - transform_.scale_.y_ / 2.0f * height_scale;

		if (transform_.position_.y_ < y_lower_bound) transform_.position_.y_ = y_lower_bound;
		else if (transform_.position_.y_ > y_upper_bound) transform_.position_.y_ = y_upper_bound;

	}
	Vector2 Triangle::CalculateRotation(App app, Vector2 vertex)
	{
		// Sine & Cosine of current rotation
		double sin = Mathf::Sin(Mathf::DegreeToRadian(transform_.rotation_));
		double cos = Mathf::Cos(Mathf::DegreeToRadian(transform_.rotation_));

		// Scale factors
		double x_scale = transform_.position_.x_ / app.Width() * 2.0f;
		double y_scale = transform_.position_.y_ / app.Height() * 2.0f;

		// Rotate vertex vector to match with current rotation
		return Vector2(cos * (vertex.x_ - x_scale) - sin * (vertex.y_ - y_scale) + x_scale, sin * (vertex.x_ - x_scale) + cos * (vertex.y_ - y_scale) + y_scale);
	}
} // namespace solar
