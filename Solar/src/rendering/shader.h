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
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="vertex_path">Initial path to vertex shader file</param>
		/// <param name="fragment_path">Initial path to fragment shader file</param>
		Shader(const char* vertex_path, const char* fragment_path);
		/// <summary>
		/// Destructor.
		/// </summary>
		~Shader();

		/// <summary>
		/// Path to vertex shader file.
		/// </summary>
		const char* vertex_path = NULL;
		/// <summary>
		/// Path to fragment shader file.
		/// </summary>
		const char* fragment_path = NULL;

		/// <summary>
		/// Initialize shader.
		/// </summary>
		void Init();

		/// <summary>
		/// Shader program.
		/// </summary>
		unsigned int program = NULL;

		/// <summary>
		/// Activate the shader.
		/// </summary>
		void Use();
		/// <summary>
		/// Delete shader program.
		/// </summary>
		void Delete();

		// Utility uniform functions

		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
	};
} // namespace solar

#endif // !SOLAR_SHADER_H_

