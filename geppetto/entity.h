#ifndef _GEPPETTO_ENTITY_H_
#define _GEPPETTO_ENTITY_H_

#include <memory>
#include <string>
#include <map>

#include "components/component_base.h"
#include "components/camera.h"
#include "components/geometry.h"
#include "components/physics.h"
#include "components/shader.h"
#include "components/userinput.h"
#include "math/vec3.h"
#include "math/mat4.h"

namespace Geppetto {

class Stage;

class Entity
{
public:
	bool        active;
	std::string name;
	std::string type;
	Math::Vec3  position;
	Math::Vec3  forward;
	Math::Vec3  up;
	
	Entity(std::string n, std::string t);
	virtual ~Entity();
	
	virtual void Update();
	void UpdateEntity();
	
	Game&      GetGame() const;
	Stage&     GetStage() const;
	Math::Mat4 GetReferenceFrame() const;
	void       PlaceAt(const float x, const float y, const float z);
	void       Rotate(const float x, const float y, const float z);
	
	/* Deal With Components */
	void AddComponent(const Component::Type type);
	bool HasComponent(const Component::Type type) const;
	void RemoveComponent(const Component::Type type);
	
	Component::Camera*    GetCamera()    const;
	Component::Geometry*  GetGeometry()  const;
	Component::Physics*   GetPhysics()   const;
	Component::Shader*    GetShader()    const;
	Component::UserInput* GetUserInput() const;
	
protected:
	const static        std::string defaultName;
	static int          nGEntities;
	
	Game&               game;
	Stage&              stage;
	
	Component::Camera*    camera;
	Component::Geometry*  geometry;
	Component::Physics*   physics;
	Component::Shader*    shader;
	Component::UserInput* userInput;
};

} // namespace Geppetto

#endif
