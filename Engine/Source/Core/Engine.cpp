#include "Engine.h"

#include <format>
#include "Log/Log.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogEngine);

Engine::Engine()
{
    Log::getInstance().log(LogEngine, LogVerbosity::Display, std::format("Initializing MockEngine-v{}", version()));
    // Log::getInstance().log(LogEngine, LogVerbosity::Fatal, std::format("Fatal!"));

    Log::getInstance().log(LogEngine, LogVerbosity::Log, std::format("Log file example"));
}
