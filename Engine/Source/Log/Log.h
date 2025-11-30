#pragma once

#include <string>
#include <memory.h>
#include <Core/Utility.h>

namespace Mock
{
enum class LogVerbosity : uint8_t
{
    NoLogging = 0,
    Display = 1,
    Warning = 2,
    Error = 3,
    Fatal = 4
};

class Log final : public NonCopyable
{
public:
    static Log& getInstance()
    {
        static Log instance;
        return instance;
    }

    void log(LogVerbosity verbosity, const std::string& message) const;

private:
    Log();
    ~Log();

    class Impl;
    std::unique_ptr<Impl> m_pImpl;
};

}  // namespace Mock