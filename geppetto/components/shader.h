#ifndef _G_SHADER_
#define _G_SHADER_
#include <string>
#include <unordered_map>

#include "component_base.h"

namespace Geppetto {
namespace Component {

class Shader : public ComponentBase
{
public:
	Shader(Entity& e);
	~Shader();
	
	bool CreateShader(const std::string& vertexPath,
                      const std::string& fragmentPath);
	bool DestroyShader();
	unsigned int GetShader();
	void Update();

private:
	enum class ShaderPart { Vertex, Fragment, Program };
	// Shader database shared by every instance of a shader component
	// The key is a concatenation of the vertex and frament shaders 
	// file paths
	static std::unordered_map<std::string, unsigned int> shaderDB;
	// Maps a shader program to a reference count, indicating
	// how many shader components refere to that shader program
	static std::unordered_map<unsigned int, unsigned int> refCount;
	std::string shaderName;
	// Reference to the shader program
	unsigned int shader;

private:
	bool        isInDB(std::string& key);
	bool        addToDB(std::string& key, unsigned int shaderProgram);
	bool        removeFromDB(std::string& vertexPath,
                             std::string& fragmentPath);
	
	std::string LoadFile(const std::string& path);
	bool        CompileShader(ShaderPart part, unsigned int shader,
                              const std::string filePath);
	bool        LinkProgram(unsigned int program, unsigned int vertexShader,
                            unsigned int fragmentShader);
	bool        ValidateProgram(unsigned int program);
	void        ReportError(unsigned int inspectee, ShaderPart part,
                            const std::string* filePath);
};


} // namespace Component
} // namespace Geppetto

#endif
