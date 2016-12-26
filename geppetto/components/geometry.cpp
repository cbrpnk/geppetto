#include "geometry.h"


namespace Geppetto {
namespace Component {

const std::vector<float> Geometry::Cube = {
	// Front
	-0.5f,  0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f,  0.5f,
	
	// Back;
	 0.5f,  0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,

	// Right;
	 0.5f, -0.5f,  0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f, 	0.5f, -0.5f,
	 0.5f,  0.5f,  0.5f,
	
	// Left;
	-0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f,  0.5f,
	
	// Top;
	-0.5f, 0.5f, 0.5f,
	 0.5f, 0.5f, 0.5f,
	 0.5f, 0.5f, -0.5f,
	-0.5f, 0.5f, -0.5f,
	
	// Bottom;
	-0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, 0.5f,
	-0.5f, -0.5f, 0.5f,
};


Geometry::Geometry(Entity& e) : ComponentBase(e)
{}


Geometry::~Geometry()
{}


Geometry::Type Geometry::GetType()
{
	return type;
}


const std::vector<float>& Geometry::GetVertices()
{
	return vertices;
}


void Geometry::LoadVertices(const std::vector<float> verts)
{
	vertices = verts;
}


void Geometry::SetType(Type t)
{
	type = t;
}


} // namespace Component
} // namespace Geppetto
