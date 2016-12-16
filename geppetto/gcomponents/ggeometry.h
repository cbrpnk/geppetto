#ifndef _G_GEOMETRY_H_
#define _G_GEOMETRY_H_

#include <vector>

#include "gcomponent.h"


class GGeometryComponent : public GComponent
{
public:
	enum class Type {
		Points, Lines, Triangles, Quads
	};
	static const std::vector<float> Cube;
	
	GGeometryComponent(GEntity& e);
	~GGeometryComponent();
	
	Type                      getType();
	const std::vector<float>& getVertices();
	void                      loadVertices(const std::vector<float> verts);
	void                      setType(Type t);
private:
	Type type;
	std::vector<float> vertices;
};

#endif
