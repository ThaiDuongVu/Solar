#pragma once

#ifndef SOLAR_SHADER_H_
#define SOLAR_SHADER_H_

#include "../core.h"
#include "../debug.h"

namespace solar
{
	class SOLAR_API Shader
	{
	public:
		// Constructor & destructor
		Shader(const char* vertex_path, const char* fragment_path);
		~Shader();

		const char* vertex_path_ = NULL;
		const char* fragment_path_ = NULL;

		// Shader initialization
		void Init();

		// Shader program
		unsigned int program_ = NULL;

		// Activate the shader
		void Use();
		// Delete shader program
		void Delete();

		// Utility uniform functions
		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
	};
} // namespace solar


#endif // !SOLAR_SHADER_H_
