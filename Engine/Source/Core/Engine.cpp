#include "Engine.h"

#include <format>
#include "Log/Log.h"

using namespace Mock;

Engine::Engine()
{
    Log::getInstance().log(LogVerbosity::Display, std::format("Initializing MockEngine-v{}", version()));
}
