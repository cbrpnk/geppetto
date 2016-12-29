#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <iostream>
#include <fstream>

#include "shader.h"

namespace Geppetto {
namespace Component {


// Static
std::unordered_map<std::string, unsigned int> Shader::shaderDB;
std::unordered_map<unsigned int, unsigned int> Shader::refCount;


Shader::Shader(Entity& e) : ComponentBase(e)
{}


Shader::~Shader()
{
	DestroyShader();
}


bool Shader::CreateShader(const std::string& vertexPath,
                  const std::string& fragmentPath)
{
	
	// Check if shader program is not alread in the DB
	// We know that based on the path of the vertex and 
	// fragment shaders.
	
	std::string key = vertexPath + fragmentPath;
	if(isInDB(key)) {
		shaderName = vertexPath + fragmentPath;
		shader = shaderDB[key];
		refCount[shader]++;
	} else {
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			
		if(!vertexShader || !CompileShader(ShaderPart::Vertex, vertexShader,
										   vertexPath)) {
			return false;
		}
		
		if(!fragmentShader || !CompileShader(ShaderPart::Fragment, fragmentShader,
											 fragmentPath)) {
			return false;
		}
		
		GLuint program = glCreateProgram();
		if(!LinkProgram(program, vertexShader, fragmentShader)) {
			return false;
		}
		
		if(!ValidateProgram(program)) {
			return false;
		}
		
		shaderName = key;
		shader = program;
		addToDB(key, program);
		refCount.insert({program, 1});
		
		// Cleanup
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	
	return true;
}


bool Shader::DestroyShader()
{
	// The shader DB is reference counted, so when this 
	// method is called, decrement the reference counter.
	// If the ref counter is 0, then go on and delete
	// the Shader remove the entry from the shaderDB
	
	if(isInDB(shaderName)) {
		if(refCount[shader] == 1) {
			glDeleteProgram(shader);
		} else {
			refCount[shader]--;
		}
		return true;
	}
	
	return false;
}


unsigned int Shader::GetShader()
{
	return shader;
}


void Shader::Update()
{}



bool Shader::isInDB(std::string& key)
{
	if(shaderDB.find(key) != shaderDB.end()) {
		return true;
	}
	return false;
}


bool Shader::addToDB(std::string& key,
             unsigned int shaderProgram)
{
	if(!isInDB(key)) {
		shaderDB.insert({key, shaderProgram});
		return true;
	}
	
	return false;
}


bool Shader::removeFromDB(std::string& vertexPath,
                  std::string& fragmentPath)
{
	std::string key = vertexPath + fragmentPath;
	if(isInDB(key)) {
		shaderDB.erase(key);
		return true;
	}
	return false;
}


bool Shader::CompileShader(ShaderPart part, unsigned int shader,
                           const std::string filePath)
{
	std::string fileContent = LoadFile(filePath);
	const GLchar* shaderString = fileContent.c_str();
	glShaderSource(shader, 1, &shaderString, NULL);
	
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		ReportError(shader, part, &filePath);
		return false;
	}
	
	return true;
}


std::string Shader::LoadFile(const std::string& path)
{
	std::ifstream file(path);
	std::string line;
	std::string content;
	
	if(file.is_open()) {
		while(getline(file, line)) {
			content += line;
		}
		file.close();
	}
	
	return content;
}


bool Shader::LinkProgram(unsigned int program, unsigned int vertexShader,
                         unsigned int fragmentShader)
{
	int success;
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success) {
		ReportError(program, ShaderPart::Program, nullptr);
		return false;
	}
	return true;
}


bool Shader::ValidateProgram(unsigned int program)
{
	int success;
	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
	if(!success) {
		ReportError(program, ShaderPart::Program, nullptr);
		return false;
	}
	return true;
}


void Shader::ReportError(unsigned int inspectee, ShaderPart part,
                         const std::string* filePath)
{
	std::string msg = "Error in ";
	if(part == ShaderPart::Vertex) {
		msg += "Vertex Shader";
	} else if(part == ShaderPart::Fragment) {
		msg += "Fragment Shader";
	} else if(part == ShaderPart::Program) {
		msg += "Program";
	}
	
	GLchar infoLog[2048];
	glGetShaderInfoLog(inspectee, 2048, NULL, infoLog);
	std::cout << msg << std::endl;
	if(filePath != nullptr) {
		std::cout << "In " << *filePath << std::endl;
	}
	std::cout << infoLog << std::endl;
}


} // namespace Component
} // namespace Geppetto
