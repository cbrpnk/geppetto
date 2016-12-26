#include <string>
#include <vector>

#include "component_base.h"
#include "../entity.h"

namespace Geppetto {
namespace Component {

ComponentBase::ComponentBase(Geppetto::Entity& e) :
game(e.GetGame()),
stage(e.GetStage()),
entity(e)
{}


ComponentBase::~ComponentBase()
{}


void ComponentBase::Update()
{}

} // namespace Component
} // namespace Geppetto
