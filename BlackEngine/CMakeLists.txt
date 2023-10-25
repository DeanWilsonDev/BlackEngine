cmake_minimum_required(VERSION 3.25)
project(BlackEngine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

# Generate .dll file
add_library(
  BlackEngine SHARED
  Source/BlackEngine.h
  Source/BlackEngine/Core.h
  Source/BlackEngine/Core.cpp
  Source/BlackEngine/Application.h
  Source/BlackEngine/Application.cpp
  Source/BlackEngine/EntryPoint.h
  Source/BlackEngine/Logging/Log.h
  Source/BlackEngine/Logging/Log.cpp
  Source/BlackEngine/Logging/Logger.cpp
  Source/BlackEngine/Logging/Logger.h
  Source/BlackEngine/Math/Vector3D.h
  Source/BlackEngine/Mesh.h)

add_definitions(# -DBLACK_ENGINE_PLATFORM_WINDOWS
                -DBLACK_ENGINE_PLATFORM_MACOS -DBLACK_ENGINE_BUILD_DLL)

target_include_directories(
  BlackEngine PUBLIC "${CMAKE_SOURCE_DIR}/BlackEngine/Packages/spdlog/include")

target_compile_definitions(BlackEngine PUBLIC BUILDING_DAEMON_ENGINE)
