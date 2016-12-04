#ifndef _DEMO_STAGE_H_
#define _DEMO_STAGE_H_

#include <string>

#include "../geppetto/stage.h"

class DemoStage : public Stage
{
public:
	
	DemoStage(Game& parentGame, std::string name);
	~DemoStage();
	
	void load();
	void update();
};

#endif
