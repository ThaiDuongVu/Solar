#include "triangle.h"
#include <glad.h>
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

	unsigned int VBO; // Vertex buffer objects
	unsigned int VAO; // Vertex array object

	// Vertex & fragment shader
	unsigned int vertex_shader;
	unsigned int fragment_shader;

	// Shader program
	unsigned int shader_program;

	Triangle::Triangle()
	{

	}
	Triangle::~Triangle()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(shader_program);
	}

	void Init()
	{
		// Vertex shader
		// Needed to calculate position of triangle
		vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);

		// Fragment shader
		// Needed to calculate color of triangle
		fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);

		// Shader program
		shader_program = glCreateProgram();

		glAttachShader(shader_program, vertex_shader);
		glAttachShader(shader_program, fragment_shader);
		glLinkProgram(shader_program);

		// Delete vertex and fragment shader when no longer needed
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		// Draw triangle
		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f
		};

		glGenBuffers(1, &VBO);
		glGenVertexArrays(1, &VAO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

		// How to interpret the vertex data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// Finish initialization
		done_init = true;
	}

	void Triangle::Render()
	{
		// Perform initialization if not already
		if (!done_init) Init();

		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
} // namespace solar
