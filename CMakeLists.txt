# general info
cmake_minimum_required(VERSION 4.2.0)

# common options
project(MockEngine 1.0.0 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_SUPPRESS_REGENERATION TRUE)


include(${CMAKE_SOURCE_DIR}/Automation/CMAKE/CMakeHelpers.cmake)

# common options
set(PROJECT_NAME CMakeLearning)
project(${PROJECT_NAME} VERSION 1.0.0)
message("------------------- Project files generaion for ${PROJECT_NAME} -------------------")

set(STARTUP_PROJECT_NAME FightClubGame)



set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${STARTUP_PROJECT_NAME})


# cpp options
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")

# find libs
find_package(nlohmann_json REQUIRED)
find_package(GTest CONFIG REQUIRED)
# find_package(cpr REQUIRED)
find_package(raylib REQUIRED)

include_directories(Source)

# add subdirectory
add_subdirectory(Source/RaylibTetris)
add_subdirectory(Source/ChuckNorrisJokes)
add_subdirectory(Source/Utils)
add_subdirectory(Source/FightClubGame)
add_subdirectory(Source/DoodleJumpGame)

system_info()