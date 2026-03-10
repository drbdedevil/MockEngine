#pragma once

#include <string>
#include <string_view>
#include <memory>
#include <source_location>
#include <concepts>
#include <format>

#include "Core/Utility.h"

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
    const std::string m_name;
};

class Log final : public NonCopyable
{
public:
    static Log& getInstance()
    {
        static Log instance;
        return instance;
    }

    void log(const LogCategory& category, LogVerbosity verbosity, const std::string& message, bool showLocation = false,
        const std::source_location location = std::source_location::current()) const;

private:
    Log();
    ~Log();

    class Impl;
    std::unique_ptr<Impl> m_pImpl;
};

constexpr LogVerbosity c_minVerbosity = LogVerbosity::Display;
constexpr LogVerbosity c_maxVerbostiy = LogVerbosity::Fatal;

// Concepts
template <typename T>
concept ValidLogCategory = std::constructible_from<LogCategory, T>;

template <typename T>
concept LoggableMessage = std::convertible_to<T, std::string> || std::convertible_to<T, std::string_view>;

template <typename T>
concept ValidVerbosityType = std::same_as<T, LogVerbosity>;

template <LogVerbosity V>
concept ValidVerbosityLevel = V == LogVerbosity::NoLogging   //
                              || V == LogVerbosity::Display  //
                              || V == LogVerbosity::Warning  //
                              || V == LogVerbosity::Error    //
                              || V == LogVerbosity::Log      //
                              || V == LogVerbosity::Fatal;

}  // namespace Mock

#define DEFINE_LOG_CATEGORY_STATIC(logName)    \
    namespace                                  \
    {                                          \
    const Mock::LogCategory logName(#logName); \
    }

#define M_LOG_IMPL(categoryName, verbosity, showLocation, formatStr, ...)                                                                  \
    do                                                                                                                                     \
    {                                                                                                                                      \
        if constexpr (Mock::LogVerbosity::verbosity >= Mock::c_minVerbosity && Mock::LogVerbosity::verbosity <= Mock::c_maxVerbostiy)      \
        {                                                                                                                                  \
            static_assert(Mock::ValidVerbosityType<decltype(Mock::LogVerbosity::verbosity)>, "Verbosity must be type of LogVerbosity..."); \
            static_assert(Mock::ValidVerbosityLevel<Mock::LogVerbosity::verbosity>, "No such as LogVerbosity...");                         \
            static_assert(Mock::ValidLogCategory<decltype(categoryName)>, "Category must be of type LogCategory...");                      \
            static_assert(                                                                                                                 \
                Mock::LoggableMessage<decltype(formatStr)>, "Message must be convertible to std::string or std::string_view...");          \
            Mock::Log::getInstance().log(                                                                                                  \
                categoryName, Mock::LogVerbosity::verbosity, std::format(formatStr __VA_OPT__(, ) __VA_ARGS__), showLocation);             \
        }                                                                                                                                  \
    } while (0)

#define M_LOG(categoryName, verbosity, formatStr, ...) M_LOG_IMPL(categoryName, verbosity, false, formatStr, __VA_ARGS__);

#define M_LOG_DEBUG(categoryName, verbosity, formatStr, ...) M_LOG_IMPL(categoryName, verbosity, true, formatStr, __VA_ARGS__);