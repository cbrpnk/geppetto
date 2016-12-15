#ifndef _DEMO_STAGE_H_
#define _DEMO_STAGE_H_

#include <string>

#include "../geppetto/stage.h"

class DemoStage : public Stage
{
public:
	static const size_t NCubes;
	
	DemoStage();
	~DemoStage();
	
	void load();
	void update();
};

#endif
