#include "shader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad.h>
#include <glfw3.h>

namespace solar
{
	Shader::Shader(const char* vertex_path, const char* fragment_path)
	{
		this->vertex_path_ = vertex_path;
		this->fragment_path_ = fragment_path;
	}
	Shader::~Shader()
	{

	}

	void Shader::Init()
	{
		// Retrieve the vertex/fragment source code from path
		std::string vertex_source;
		std::string fragment_source;
		std::ifstream vertex_shader_file;
		std::ifstream fragment_shader_file;

		// Open files
		vertex_shader_file.open(vertex_path_);
		fragment_shader_file.open(fragment_path_);

		std::stringstream vertex_shader_stream;
		std::stringstream fragment_shader_stream;

		// Read file's buffer contents into streams
		vertex_shader_stream << vertex_shader_file.rdbuf();
		fragment_shader_stream << fragment_shader_file.rdbuf();

		// Close file handlers
		vertex_shader_file.close();
		fragment_shader_file.close();

		// Convert stream into string
		vertex_source = vertex_shader_stream.str();
		fragment_source = fragment_shader_stream.str();

		const char* vertex_shader_source = vertex_source.c_str();
		const char* fragment_shader_source = fragment_source.c_str();

		// Compile shaders
		unsigned int vertex;
		unsigned int fragment;

		// Vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex);

		// Fragment Shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment);

		// Shader program
		program_ = glCreateProgram();
		glAttachShader(program_, vertex);
		glAttachShader(program_, fragment);
		glLinkProgram(program_);

		// Delete the shaders as they're no longer necessary
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void Shader::Use()
	{
		glUseProgram(this->program_);
	}
	void Shader::Delete()
	{
		glDeleteProgram(this->program_);
	}

	void Shader::SetBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(this->program_, name.c_str()), (int)value);
	}
	void Shader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(this->program_, name.c_str()), value);
	}
	void Shader::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(this->program_, name.c_str()), value);
	}
} // namespace solar