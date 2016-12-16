#ifndef _GENTITY_H_
#define _GENTITY_H_

#include <memory>
#include <string>
#include <map>

#include "gcomponent.h"
#include "gcomponents/g_camera.h"
#include "gcomponents/g_geometry.h"
#include "gcomponents/g_physics.h"
#include "gcomponents/g_user_input.h"
#include "math/vec3.h"
#include "math/mat4.h"

class GStage;

class GEntity
{
public:
	bool        active;
	std::string name;
	std::string type;
	Vec3        position;
	Vec3        forward;
	Vec3        up;
	
	GEntity(std::string n, std::string t);
	virtual ~GEntity();
	
	virtual void load();
	virtual void update();
	void loadGEntity();
	void updateGEntity();
	
	GGame&  getGGame() const;
	GStage& getGStage() const;
	Mat4   getReferenceFrame() const;
	void   placeAt(const float x, const float y, const float z);
	void   rotate(const float x, const float y, const float z);
	
	/* Deal With GComponents */
	void addGComponent(const GComponent::Type type);
	bool hasGComponent(const GComponent::Type type) const;
	void removeGComponent(const GComponent::Type type);
	
	GCameraComponent*    getGCamera()    const;
	GGeometryComponent*  getGGeometry()  const;
	GPhysicsComponent*   getGPhysics()   const;
	GUserInputComponent* getGUserInput() const;
	
protected:
	const static        std::string default_name;
	static int          n_gEntities;
	
	GGame&               gGame;
	GStage&              gStage;
	
	GCameraComponent*    gCamera;
	GGeometryComponent*  gGeometry;
	GPhysicsComponent*   gPhysics;
	GUserInputComponent* gUserInput;
};

#endif
