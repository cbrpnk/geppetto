#include "engine/geppetto.h"
#include "lib/gmath.h"
#include "demo_scene.h"
#include "player.h"

DemoScene::DemoScene(Game& ParentGame) : Scene(ParentGame) {}


DemoScene::~DemoScene() {}

void DemoScene::load() {
	Scene::load();
	
	Entity* player = new Entity(this);
	player->name = "Player";
	player->addCustomClass(new Player());
	player->components.add("Physics");
	player->components.getPhysics()->setFrictionCoefficient(0.15f);
	player->components.add("Camera");
	player->components.getCamera()->setPosition(Vec3(0.0f, 2.0f, 0.0f));
	player->components.add("UserInput");
	addEntity(player);
	setCameraEntity(player);
	
	// Create cubes
	for(int i=0; i<100; ++i) {
		Entity* entity = new Entity(this);
		entity->name = "Cube" + std::to_string(i);
		entity->position.x = Gmath::randomFloat(-50.0f, 50.0f);
		entity->position.y = Gmath::randomFloat(-5.0f, 5.0f);
		entity->position.z = Gmath::randomFloat(-50.0f, 50.0f);
		entity->rotate(Gmath::randomFloat(0, 360), 0, Gmath::randomFloat(0, 360));
		entity->components.add("Physics");
		entity->components.getPhysics()->setFrictionCoefficient(0.15f);
		entity->components.add("Geometry");
		entity->components.getGeometry()->loadVertices(GeometryComponent::Cube);
		entity->components.getGeometry()->setType(GeometryComponent::Type::Quads);
		addEntity(entity);
	}
}
