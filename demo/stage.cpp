#include <string>
#include <vector>
#include "../geppetto/geppetto.h"
#include "stage.h"
#include "player.h"
#include "planet.h"


const size_t Stage::NCubes = 1;


Stage::Stage() : Geppetto::Stage("Stage")
{
    new Player();
    
    // Create cubes
    //for(size_t i=0; i<Stage::NCubes; ++i) {
    new Planet("Panet");
    //}
}


Stage::~Stage()
{}


void Stage::Update()
{}
