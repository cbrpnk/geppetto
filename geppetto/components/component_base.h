#ifndef _GEPPETTO_COMPONENT_BASE_H_
#define _GEPPETTO_COMPONENT_BASE_H_

#include <vector>


namespace Geppetto {

class Entity;
class Game;
class Stage;

namespace Component {

enum class Type
{
	Camera, Geometry, Physics, Shader, UserInput
};


class ComponentBase
{
public:
	
	Game&   game;
	Stage&  stage;
	Entity& entity;
	
	ComponentBase(Geppetto::Entity& e);
	virtual ~ComponentBase();
	virtual void Update();
};

} // namespace Component
} // namespace Geppetto

#endif
