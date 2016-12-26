#ifndef _GEPPETTO_GEOMETRY_H_
#define _GEPPETTO_GEOMETRY_H_

#include <vector>

#include "component_base.h"

namespace Geppetto {
namespace Component {

class Geometry : public ComponentBase
{
public:
	enum class Type {
		Points, Lines, Triangles, Quads
	};
	static const std::vector<float> Cube;
	
	Geometry(Entity& e);
	~Geometry();
	
	Type                      GetType();
	const std::vector<float>& GetVertices();
	void                      LoadVertices(const std::vector<float> verts);
	void                      SetType(Type t);
private:
	Type type;
	std::vector<float> vertices;
};

} // namespace Component
} // namespace Geppetto

#endif
