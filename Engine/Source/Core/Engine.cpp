#include "Engine.h"

#include <format>
#include "Log/Log.h"

using namespace Mock;

DEFINE_LOG_CATEGORY_STATIC(LogEngine);

Engine::Engine()
{
    M_LOG(LogEngine, Display, "Initializing MockEngine-v{}", version());
    // M_LOG_DEBUG(LogEngine, Fatal, "Fatal!");

    M_LOG_DEBUG(LogEngine, Display, "Yooo...");
}
