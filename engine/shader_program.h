#include "string"

class ShaderProgram {
public:
	ShaderProgram(std::string vert_shader_path, std::string frag_shader_path) {};
	~ShaderProgram() {};
	
private:
	std::string vertexShaderPath;
	std::string fragmentShaderPath;
}
