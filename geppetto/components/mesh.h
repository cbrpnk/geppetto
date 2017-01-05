#ifndef _GEPPETTO_MESH_H_
#define _GEPPETTO_MESH_H_

#include <vector>

#include "component_base.h"

namespace Geppetto {
namespace Component {

class Mesh : public ComponentBase
{
public:
    enum class Type {
        Points, Lines, Triangles, Quads
    };
    static const std::vector<unsigned short> CubeIndex;
    static const std::vector<float> CubeVertices;
    static const std::vector<float> CubeNormals;
    
    Mesh(Entity& e);
    ~Mesh();
    
    Type                      GetType() const;
    unsigned int              GetVertexCount() const;
    unsigned int              GetIndexBuffer() const;
    unsigned int              GetVertexBuffer() const;
    unsigned int              GetNormalBuffer() const;
    void                      Load(const std::vector<unsigned short> index,
                                   const std::vector<float> vertices,
                                   const std::vector<float> normals);
    void                      SetType(Type t);
private:
    Type type;
    unsigned int vertexCount;
    unsigned int indexBuffer;
    unsigned int vertexBuffer;
    unsigned int normalBuffer;
};

} // namespace Component
} // namespace Geppetto

#endif
