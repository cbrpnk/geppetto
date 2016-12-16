#ifndef _GSTAGE_H_
#define _GSTAGE_H_

#include <string>
#include <map>
#include <iterator>

#include "gentity.h"

class GGame;

class GStage
{
public:
	GStage(std::string gStageName);
	virtual ~GStage();
	
	GGame&       getGGame() const;
	std::string getName() const;
	void        setName(const std::string name);
	
	
	//////////////////// Deal with GEntities /////////////////////
	
	
	void                                    addGEntity(GEntity* e);
	GEntity*                                getCameraGEntity() const;
	const std::map<std::string, GEntity*>&  getGEntities() const;
	std::vector<GEntity*>*                  getGEntitiesByType(const std::string type);
	GEntity*                                getGEntityByName(const std::string name);
	void                                    removeGEntity(const std::string name);
	void                                    setCameraGEntity(GEntity* const e);
	
	
	/////////////////// Load/Update //////////////////////////
	
	
	/* loadGStage() is called by GGame::loadGStage() */
	void loadGStage();
	/* Called on every frame by GGame::run() */
	void updateGStage();
	
	/* Methods meant to be defined by the derived class; are called by
     * loadGStage() and updateGStage() respectively
     */
	virtual void load();
	virtual void update();


protected:
	/* Reference to the current GGame */
	GGame& gGame;
	/* Unique identifier to a GStage */
	std::string name;
	/* All the GEntities in this GStage */
	std::map<std::string, GEntity*> gEntitiesByName;
	/* Maps a GUser defined GEntity type to the set of GEntities that are of
     * that type. Used by getGEntitiesByType().
     */
	std::map<std::string, std::vector<GEntity*>> gEntitiesByType;
	/* GEntity that possess a CameraGComponent used by GGame::render() */
	GEntity* cameraGEntity;
};

#endif
