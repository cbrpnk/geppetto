#ifndef _GEPPETTO_MESH_H_
#define _GEPPETTO_MESH_H_

#include <vector>
#include <string>
#include <map>

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
    static const std::vector<float> CubeColors;
    
    // This structure encapuslate information about the mesh
    // so is can easily be cached in a map.
    struct ObjectInfo {
        unsigned int vertexCount;
        unsigned int indexBuffer;
        unsigned int vertexBuffer;
        unsigned int normalBuffer;
        unsigned int colorBuffer;
    };
    static std::map<std::string, Mesh::ObjectInfo> objectCache;
    
    Mesh(Entity& e);
    ~Mesh();
    
    Type                      GetType() const;
    unsigned int              GetVertexCount() const;
    unsigned int              GetIndexBuffer() const;
    unsigned int              GetVertexBuffer() const;
    unsigned int              GetNormalBuffer() const;
    unsigned int              GetColorBuffer() const;
    void                      Load(const std::vector<unsigned short> index,
                                   const std::vector<float> vertices,
                                   const std::vector<float> normals,
                                   const std::vector<float> colors);
    
    // The invert parameter specifies wether we should invert
    // vertex order on each faces (invert face orientation).
    void                      LoadOBJFile(const std::string& pathToFile,
                                          const std::string& filename,
                                          bool invert);
    void                      SetType(Type t);


private:
    
    Type type;
    ObjectInfo objectInfo;

private:
    ///////////////////////////////// OBJMesh //////////////////////////////////
    
    // Internal in-memory representation of an obj file
    // This implementation can only represent meshs composed of triangles
    class OBJMesh {
    public:
        struct Material {
            float ns;
            float ka[3];
            float kd[3];
            float ks[3];
            float ke[3];
            float ni;
            float d;
            int illum;
        };
        
        struct Face {
            std::string vertexNames[3];
            std::string materialName;
            int v[3];
            int t[3];
            int n[3];
        };
        
        struct Command {
            std::string action;
            std::vector<std::string> parameters;
        };
        
        
        std::vector<Math::Vec3> vertices;
        std::vector<Math::Vec3> normals;
        std::vector<Face> faces;
        std::map<std::string, Material> materials;
        std::string activeMaterial;
        std::string currentWorkingPath;
        
        OBJMesh(const std::string& pathToFile,
                const std::string& filename);
        ~OBJMesh();
    
    private:
        void    ReadFile(const std::string& pathToFile);
        Command LineToCommand(const std::string& line);
        void    ExecuteCommand(const Command& command);
        void    ExecV(const std::vector<std::string>& params);
        void    ExecVN(const std::vector<std::string>& params);
        void    ExecF(const std::vector<std::string>& params);
        void    ExecMTLLIB(const std::vector<std::string>& params);
        void    ExecUSEMTL(const std::vector<std::string>& params);
        void    ExecNEWMTL(const std::vector<std::string>& params);
        void    ExecKD(const std::vector<std::string>& params);
        std::vector<std::string> SplitString(const std::string& s,
                                             const char delim);
    };
};

} // namespace Component
} // namespace Geppetto

#endif
