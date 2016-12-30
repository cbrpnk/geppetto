#ifndef _STAGE_H_
#define _STAGE_H_

#include <string>

#include "../geppetto/geppetto.h"

class Stage : public Geppetto::Stage
{
public:
    static const size_t NCubes;

    Stage();
    ~Stage();
    
    void Update();
};

#endif
