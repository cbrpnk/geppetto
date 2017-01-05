#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#include "mesh.h"


namespace Geppetto {
namespace Component {


const std::vector<unsigned short> Mesh::CubeIndex = {
    // Front
    0, 1, 2, 2, 3, 0,
    // Back
    4, 5, 6, 6, 7, 4,
    // Right
    8, 9, 10, 10, 11, 8,
    // Left
    12, 13, 14, 14, 15, 12,
    // Top
    16, 17, 18, 18, 19, 16,
    // Bottom
    20, 21, 22, 22, 23, 20
};


const std::vector<float> Mesh::CubeVertices = {
    // Front
    -0.5,  0.5,  0.5,
    -0.5, -0.5,  0.5,
     0.5, -0.5,  0.5,
     0.5,  0.5,  0.5,

    // Back
     0.5,  0.5, -0.5,
     0.5, -0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5,  0.5, -0.5,

    // Right
     0.5, -0.5,  0.5,
     0.5, -0.5, -0.5,
     0.5,  0.5, -0.5,
     0.5,  0.5,  0.5,

    // Left
    -0.5,  0.5,  0.5,
    -0.5,  0.5, -0.5,
    -0.5, -0.5, -0.5,
    -0.5, -0.5,  0.5,

    // Top
    -0.5,  0.5,  0.5,
     0.5,  0.5,  0.5,
     0.5,  0.5, -0.5,
    -0.5,  0.5, -0.5,

    // Bottom
    -0.5, -0.5, -0.5,
     0.5, -0.5, -0.5,
     0.5, -0.5,  0.5,
    -0.5, -0.5,  0.5,
};


const std::vector<float> Mesh::CubeNormals = {
    // Front
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
     0.0f,  0.0f,  1.0f,
    
    // Back
     0.0f,  0.0f, -1.0f,
     0.0f,  0.0f, -1.0f,
     0.0f,  0.0f, -1.0f,
     0.0f,  0.0f, -1.0f,
    
    // Right
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
     1.0f,  0.0f,  0.0f,
    
    // Left
    -1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,
    -1.0f,  0.0f,  0.0f,
    
    // Top
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
     0.0f,  1.0f,  0.0f,
    
    // Bottom
     0.0f, -1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,
     0.0f, -1.0f,  0.0f,
};


Mesh::Mesh(Entity& e) : ComponentBase(e)
{}


Mesh::~Mesh()
{}


Mesh::Type Mesh::GetType() const
{
    return type;
}


unsigned int Mesh::GetVertexCount() const
{
    return vertexCount;
}


unsigned int Mesh::GetIndexBuffer() const
{
    return indexBuffer;
}


unsigned int Mesh::GetVertexBuffer() const
{
    return vertexBuffer;
}


unsigned int Mesh::GetNormalBuffer() const
{
    return normalBuffer;
}


void Mesh::Load(const std::vector<unsigned short> index,
                const std::vector<float> vertices,
                const std::vector<float> normals)
{
    vertexCount = index.size();
    
    // Vertex Index
    glGenBuffers(1, (GLuint*) &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, (GLuint) indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(unsigned short),                 &index[0], GL_STATIC_DRAW);
    
    // Vertex Buffer
    glGenBuffers(1, (GLuint*) &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float),
                 &vertices[0], GL_STATIC_DRAW);
    
    // Normal Buffer
    glGenBuffers(1, (GLuint*) &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, (GLuint) normalBuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(float),
                 &normals[0], GL_STATIC_DRAW);
}


void Mesh::SetType(Type t)
{
    type = t;
}


} // namespace Component
} // namespace Geppetto
