#include "Engine.h"
#include <iostream>

using namespace Mock;

Engine::Engine() 
{
    std::cout << "Initializing Mock Engine " << version() << std::endl;
}
