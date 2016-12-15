#ifndef _GEPPETTO_GEOMETRY_COMPONENT
#define _GEPPETTO_GEOMETRY_COMPONENT

#include <vector>

#include "../component.h"


class GeometryComponent : public Component
{
public:
	enum class Type {
		Points, Lines, Triangles, Quads
	};
	static const std::vector<float> Cube;
	
	GeometryComponent(Entity& e);
	~GeometryComponent();
	
	Type                      getType();
	const std::vector<float>& getVertices();
	void                      loadVertices(const std::vector<float> verts);
	void                      setType(Type t);
private:
	Type type;
	std::vector<float> vertices;
};

#endif
