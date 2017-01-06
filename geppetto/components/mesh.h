#ifndef _GEPPETTO_MESH_H_
#define _GEPPETTO_MESH_H_

#include <vector>
#include <string>

#include "component_base.h"
#include "../math/vec3.h"

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
    
    // The invert parameter specifies wether we should invert
    // vertex order on each faces (invert face orientation).
    void                      LoadOBJFile(const std::string& path,
                                          bool invert);
    void                      SetType(Type t);


private:
    Type type;
    unsigned int vertexCount;
    unsigned int indexBuffer;
    unsigned int vertexBuffer;
    unsigned int normalBuffer;


private:
    ////////////////////////////////// OBJMesh //////////////////////////////////
    // Internal in-memory representation of an obj file
    // This implementation can only represent meshs composed of triangles
    class OBJMesh {
    public:
        
        typedef struct {
            std::string vertexNames[3];
            int v[3];
            int t[3];
            int n[3];
        } Face;
        
        typedef struct {
            std::string action;
            std::vector<std::string> parameters;
        } Command;
        
        std::vector<Math::Vec3> vertices;
        std::vector<Math::Vec3> normals;
        std::vector<Face> faces;
        
        OBJMesh(const std::string& pathToFile);
        ~OBJMesh();
    
    private:
        Command                  LineToCommand(const std::string& line);
        void                     ExecuteCommand(const Command& command);
        void                     ExecV(const std::vector<std::string>& params);
        void                     ExecVN(const std::vector<std::string>& params);
        void                     ExecF(const std::vector<std::string>& params);
        std::vector<std::string> SplitString(const std::string& s,
                                             const char delim);
    };
};

} // namespace Component
} // namespace Geppetto

#endif
