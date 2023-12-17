#ifndef _SHADER_H_
#define _SHADER_H_
#include <map>
#include <string>

class Shader
{
private:
	Shader(const Shader&);
	Shader& operator = (const Shader&);

	unsigned int mHandle;
	std::map<std::string, unsigned int> mAttributes;
	std::map<std::string, unsigned int> mUniforms;

	std::string ReadFile(const std::string & path);

	unsigned int CompileVertexShader(const std::string& vertex);
	unsigned int CompileFragmentShader(const std::string& fragment);
	bool LinkShader(unsigned int vertex, unsigned int fragment);
	void PopulateAttributes();
	void PopulateUniforms();

public:
	Shader();
	Shader(const std::string& vertex, const std::string& fragment);
	~Shader();

	void Load(const std::string& vertex, const std::string& fragment);

	void Bind();
	void UnBind();
	unsigned int GetAttribute(const std::string& name);
	unsigned int GetUniform(const std::string& name);
	unsigned int GetHandle();
};

#endif // !_SHADER_H_
