#pragma once

#include <string>
#include <memory>
#include <Core/Utility.h>

namespace Mock
{
enum class LogVerbosity : uint8_t
{
    NoLogging = 0,
    Display = 1,
    Warning = 2,
    Error = 3,
    Log = 4,
    Fatal = 5
};

struct LogCategory
{
    explicit LogCategory(const std::string& name) : m_name(name) {}
    std::string name() const { return m_name; }

private:
    std::string m_name;
};

class Log final : public NonCopyable
{
public:
    static Log& getInstance()
    {
        static Log instance;
        return instance;
    }

    void log(const LogCategory& category, LogVerbosity verbosity, const std::string& message) const;

private:
    Log();
    ~Log();

    class Impl;
    std::unique_ptr<Impl> m_pImpl;
};

#define DEFINE_LOG_CATEGORY_STATIC(logName)    \
    namespace                                  \
    {                                          \
    const Mock::LogCategory logName(#logName); \
    }

}  // namespace Mock