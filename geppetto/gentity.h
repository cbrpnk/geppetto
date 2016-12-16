#ifndef _GENTITY_H_
#define _GENTITY_H_

#include <memory>
#include <string>
#include <map>

#include "gcomponents/gcomponent.h"
#include "gcomponents/gcamera.h"
#include "gcomponents/ggeometry.h"
#include "gcomponents/gphysics.h"
#include "gcomponents/guserinput.h"
#include "gmath/gvec3.h"
#include "gmath/gmat4.h"

class GStage;

class GEntity
{
public:
	bool        active;
	std::string name;
	std::string type;
	GVec3        position;
	GVec3        forward;
	GVec3        up;
	
	GEntity(std::string n, std::string t);
	virtual ~GEntity();
	
	virtual void load();
	virtual void update();
	void loadGEntity();
	void updateGEntity();
	
	GGame&  getGGame() const;
	GStage& getGStage() const;
	GMat4   getReferenceFrame() const;
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
