#include "geometry_component.h"

const std::vector<float> GeometryComponent::Cube = {
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

GeometryComponent::GeometryComponent(Entity& e) : Component(e)
{}

GeometryComponent::~GeometryComponent()
{}


GeometryComponent::Type GeometryComponent::getType()
{
	return type;
}


const std::vector<float>& GeometryComponent::getVertices()
{
	return vertices;
}


void GeometryComponent::loadVertices(const std::vector<float> verts)
{
	vertices = verts;
}


void GeometryComponent::setType(Type t)
{
	type = t;
}
