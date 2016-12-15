#ifndef _STAGE_H_
#define _STAGE_H_

#include <string>

#include "../geppetto/gstage.h"

class Stage : public GStage
{
public:
	static const size_t NCubes;
	
	Stage();
	~Stage();
	
	void load();
	void update();
};

#endif
