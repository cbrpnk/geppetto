#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <map>

#include "mesh.h"


namespace Geppetto {
namespace Component {


const std::vector<unsigned short> Mesh::CubeIndex = {
//  |  Tri 1  |   Tri 2  |
    0,  1,  2,  2,  3,  0,  // Front
    4,  5,  6,  6,  7,  4,  // Back
    8,  9,  10, 10, 11, 8,  // Right
    12, 13, 14, 14, 15, 12, // Left
    16, 17, 18, 18, 19, 16, // Top
    20, 21, 22, 22, 23, 20  // Bottom
};


const std::vector<float> Mesh::CubeVertices = {
//    X     Y     Z
    -0.5,  0.5,  0.5, // Front
    -0.5, -0.5,  0.5,
     0.5, -0.5,  0.5,
     0.5,  0.5,  0.5,
     0.5,  0.5, -0.5, // Back
     0.5, -0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,
     0.5, -0.5,  0.5, // Right
     0.5, -0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5,  0.5,  0.5,
    -0.5,  0.5,  0.5, // Left
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5, -0.5,  0.5,
    -0.5,  0.5,  0.5, // Top
     0.5,  0.5,  0.5,
     0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5, // Bottom
     0.5, -0.5, -0.5,
     0.5, -0.5,  0.5,
    -0.5, -0.5,  0.5,
};


const std::vector<float> Mesh::CubeNormals = {
//    X      Y      Z
     0.0f,  0.0f,  1.0f, // Front
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f, -1.0f, // Back
     0.0f,  0.0f, -1.0f,
     0.0f,  0.0f, -1.0f,
     0.0f,  0.0f, -1.0f,
     1.0f,  0.0f,  0.0f, // Right
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f, // Left
    -1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,
     0.0f,  1.0f,  0.0f, // Top
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f, -1.0f,  0.0f, // Bottom
     0.0f, -1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,
};


const std::vector<float> Mesh::CubeColors = {
//    R      G      B  
     1.0f,  0.0f,  0.0f, // Front
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
     0.0f,  1.0f,  0.0f, // Back
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f,  0.0f,  1.0f, // Right
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     1.0f,  1.0f,  0.0f, // Left
     1.0f,  1.0f,  0.0f,
     1.0f,  1.0f,  0.0f,
     1.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  1.0f, // Top
     0.0f,  1.0f,  1.0f,
     0.0f,  1.0f,  1.0f,
     0.0f,  1.0f,  1.0f,
     1.0f,  0.0f,  1.0f, // Bottom
     1.0f,  0.0f,  1.0f,
     1.0f,  0.0f,  1.0f,
     1.0f,  0.0f,  1.0f,
};


// Static
std::map<std::string, Mesh::ObjectInfo> Mesh::objectCache;


Mesh::Mesh(Entity& e) : ComponentBase(e)
    , type(Type::Triangles)
{}


Mesh::~Mesh()
{}


Mesh::Type Mesh::GetType() const
{
    return type;
}


unsigned int Mesh::GetVertexCount() const
{
    return objectInfo.vertexCount;
}


unsigned int Mesh::GetIndexBuffer() const
{
    return objectInfo.indexBuffer;
}


unsigned int Mesh::GetVertexBuffer() const
{
    return objectInfo.vertexBuffer;
}


unsigned int Mesh::GetNormalBuffer() const
{
    return objectInfo.normalBuffer;
}


unsigned int Mesh::GetColorBuffer() const
{
    return objectInfo.colorBuffer;
}


void Mesh::Load(const std::vector<unsigned short> index,
                const std::vector<float> vertices,
                const std::vector<float> normals,
                const std::vector<float> colors)
{
    objectInfo.vertexCount = index.size();
    
    // Vertex Index
    glGenBuffers(1, (GLuint*) &(objectInfo.indexBuffer));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (GLuint) objectInfo.indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(unsigned short),                 &index[0], GL_STATIC_DRAW);
    
    // Vertex Buffer
    glGenBuffers(1, (GLuint*) &(objectInfo.vertexBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) objectInfo.vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 &vertices[0], GL_STATIC_DRAW);
    
    // Normal Buffer
    glGenBuffers(1, (GLuint*) &(objectInfo.normalBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) objectInfo.normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float),
                 &normals[0], GL_STATIC_DRAW);
    
    
    // Color Buffer
    glGenBuffers(1, (GLuint*) &(objectInfo.colorBuffer));
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) objectInfo.colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(float),
                 &colors[0], GL_STATIC_DRAW);
}


void Mesh::LoadOBJFile(const std::string& pathToFile,
                       const std::string& filename, bool invert)
{
    // Check if objects is in cahce
    if(objectCache.find(pathToFile + filename) != objectCache.end()) {
        objectInfo = objectCache[pathToFile + filename];    
    } else {
        OBJMesh objMesh = OBJMesh(pathToFile, filename);
        // This cache stores vertex id's from vertices whose name
        // we've already seen
        std::map<std::string, int> cache;
        int currentIndex = 0;
        
        std::vector<unsigned short> index;
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> colors;
        
        // Load the vertex and normals
        for(size_t i=0; i<objMesh.faces.size(); ++i) {
            for(size_t j=0; j<3; ++j) {
                std::string vertexName = objMesh.faces[i].vertexNames[j];
                auto targetIndex = cache.find(vertexName);
                
                if(targetIndex != cache.end()) {
                    // We already have a reference to that vertex
                    index.push_back(targetIndex->second);
                } else {
                    // New vertex
                    index.push_back(currentIndex);
                    
                    vertices.push_back(objMesh.vertices[objMesh.faces[i].v[j]].x);
                    vertices.push_back(objMesh.vertices[objMesh.faces[i].v[j]].y);
                    vertices.push_back(objMesh.vertices[objMesh.faces[i].v[j]].z);
                    
                    normals.push_back(objMesh.normals[objMesh.faces[i].n[j]].x);
                    normals.push_back(objMesh.normals[objMesh.faces[i].n[j]].y);
                    normals.push_back(objMesh.normals[objMesh.faces[i].n[j]].z);
                    
                    colors.push_back(objMesh.materials[objMesh.faces[i].materialName].kd[0]);
                    colors.push_back(objMesh.materials[objMesh.faces[i].materialName].kd[1]);
                    colors.push_back(objMesh.materials[objMesh.faces[i].materialName].kd[2]);
                    
                    cache.insert(std::pair<std::string, int>(vertexName,
                                                             currentIndex));
                    ++currentIndex;
                }
            }
        }
        
        
        Load(index, vertices, normals, colors);
        // Add to cache
        objectCache.insert(std::pair<std::string,
                                    ObjectInfo>(pathToFile + filename,
                                                objectInfo));
    }
}


void Mesh::SetType(Type t)
{
    type = t;
}









//////////////////////////////////// OBJMesh //////////////////////////////////

Mesh::OBJMesh::OBJMesh(const std::string& pathToFile, const std::string& filename) {
    currentWorkingPath = pathToFile;
    ReadFile(pathToFile + filename);
}

void Mesh::OBJMesh::ReadFile(const std::string& pathToFile)
{
    std::ifstream file(pathToFile);
    std::string line;
    
    if(file.is_open()) {
        while(getline(file, line)) {
            ExecuteCommand(LineToCommand(line));
        }
        file.close();
    }
}


Mesh::OBJMesh::~OBJMesh()
{}


Mesh::OBJMesh::Command Mesh::OBJMesh::LineToCommand(const std::string& line)
{
    Command command;
    
    if(line.length() > 2 && line[0] != '#') {
        std::vector<std::string> split = SplitString(line, ' ');
        command.action = split[0];
        for(size_t i=1; i<split.size(); ++i) {
            command.parameters.push_back(split[i]);
        }
    }
    
    return command;
}


void Mesh::OBJMesh::ExecuteCommand(const Command& command)
{
    if(command.action == "v") {
        ExecV(command.parameters);
    } else if(command.action == "vn") {
        ExecVN(command.parameters);
    } else if(command.action == "f") {
        ExecF(command.parameters);
    } else if(command.action == "mtllib") {
        ExecMTLLIB(command.parameters);
    } else if(command.action == "usemtl") {
        ExecUSEMTL(command.parameters);
    } else if(command.action == "newmtl") {
        ExecNEWMTL(command.parameters);
    } else if(command.action == "Kd") {
        ExecKD(command.parameters);
    }
}


// Vertex
void Mesh::OBJMesh::ExecV(const std::vector<std::string>& params)
{
    vertices.push_back(Math::Vec3(std::atof(params[0].c_str()),
                                  std::atof(params[1].c_str()),
                                  std::atof(params[2].c_str())));
}


// Normal
void Mesh::OBJMesh::ExecVN(const std::vector<std::string>& params)
{
    normals.push_back(Math::Vec3(std::atof(params[0].c_str()),
                                 std::atof(params[1].c_str()),
                                 std::atof(params[2].c_str())));
}


// Face
void Mesh::OBJMesh::ExecF(const std::vector<std::string>& params)
{
    Face face;
    
    for(int i=0; i<3; ++i) {
        std::vector<std::string> split = SplitString(params[i], '/');
        face.vertexNames[i] = params[i];
        // The obj file specs says that face indexes start at 1
        // but our interal representation starts at 0, thus the -1
       
        if(split[0].size()) {
            face.v[i] = std::atoi(split[0].c_str())-1;
        }
        
        if(split[0].size()) {
            face.t[i] = std::atoi(split[1].c_str())-1;
        }
        
        if(split[0].size()) {
            face.n[i] = std::atoi(split[2].c_str())-1;
        }
    }
    face.materialName = activeMaterial;
    
    faces.push_back(face);
}


// Include material file
void Mesh::OBJMesh::ExecMTLLIB(const std::vector<std::string>& params)
{
    std::string path = currentWorkingPath + params[0];
    ReadFile(path);
}


// Use material
void Mesh::OBJMesh::ExecUSEMTL(const std::vector<std::string>& params)
{
    activeMaterial = params[0];
}


// Define a new material
void Mesh::OBJMesh::ExecNEWMTL(const std::vector<std::string>& params)
{
    Material m;
    materials.insert(std::pair<std::string, Material>(params[0], m));
    activeMaterial = params[0];
}


// Material diffuse
void Mesh::OBJMesh::ExecKD(const std::vector<std::string>& params)
{
    for(size_t i=0; i<3; ++i) {
        materials[activeMaterial].kd[i] = std::atof(params[i].c_str());
    }
}


std::vector<std::string> Mesh::OBJMesh::SplitString(const std::string& s,
                                                    const char delim)
{
    std::vector<std::string> result;
    std::string buf = "";
    
    for(size_t i=0; i<s.length(); ++i) {
        if(s[i] == delim) {
            result.push_back(buf);
            buf = "";
        } else {
            buf += s[i];
        }
    }
    if(buf.size() > 0) {
        result.push_back(buf);
    }
    
    return result;
}



} // namespace Component
} // namespace Geppetto
