#pragma once

#include <string>
#include <functional>

namespace Mock
{

struct WindowId
{
    unsigned int value{0};
    constexpr explicit WindowId(unsigned int inId) : value(inId) {}

    constexpr WindowId operator++(int)
    {
        WindowId idCopy = *this;
        ++this->value;
        return idCopy;
    }

    constexpr auto operator<=>(const WindowId& Other) const = default;
};

struct WindowSettings
{
    std::string title{};
    int width{800};
    int height{600};
    int x{50};
    int y{50};
};

class IWindow
{
public:
    virtual ~IWindow() = default;

    virtual void setTitle(const std::string& title) = 0;
    virtual bool isValid() const = 0;
    virtual bool shouldClose() const = 0;
};

}  // namespace Mock

namespace std
{
template <>  // To do this, because WindowId now can using in unordered_map
struct hash<Mock::WindowId>
{
    size_t operator()(const Mock::WindowId& id) const noexcept { return std::hash<unsigned int>{}(id.value); }
};
}  // namespace std