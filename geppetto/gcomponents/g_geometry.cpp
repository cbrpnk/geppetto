#include "g_geometry.h"

const std::vector<float> GGeometryComponent::Cube = {
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

GGeometryComponent::GGeometryComponent(GEntity& e) : GComponent(e)
{}

GGeometryComponent::~GGeometryComponent()
{}


GGeometryComponent::Type GGeometryComponent::getType()
{
	return type;
}


const std::vector<float>& GGeometryComponent::getVertices()
{
	return vertices;
}


void GGeometryComponent::loadVertices(const std::vector<float> verts)
{
	vertices = verts;
}


void GGeometryComponent::setType(Type t)
{
	type = t;
}
