#ifndef _DEMO_STAGE_H_
#define _DEMO_STAGE_H_

#include "../geppetto/stage.h"

class DemoStage : public Stage {
public:
	
	DemoStage(Game& parentGame);
	~DemoStage();
	
	void load();
};

#endif
