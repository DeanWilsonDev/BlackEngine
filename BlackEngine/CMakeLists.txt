cmake_minimum_required(VERSION 3.25)
project(BlackEngine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

# Generate .dll file
add_library(
  BlackEngine SHARED
  Source/BlackEngine/Core.cpp
  Source/BlackEngine/Math.h
  Source/BlackEngine/Core.h
  Source/BlackEngine/Mesh.h
  Source/BlackEngine/Log.h
  Source/BlackEngine/Log.cpp
  Source/BlackEngine/Application.h
  Source/BlackEngine/Application.cpp
  Source/BlackEngine.h
  Source/BlackEngine/EntryPoint.h
  Source/BlackEngine/Logging/Logger.cpp
  Source/BlackEngine/Logging/Logger.h
)

add_definitions(
  # -DDE_PLATFORM_WINDOWS
  -DDE_PLATFORM_MACOS
  -DDE_BUILD_DLL
)


target_include_directories(
  BlackEngine PUBLIC
  "${CMAKE_SOURCE_DIR}/BlackEngine/Packages/spdlog/include"
)

target_compile_definitions(BlackEngine PUBLIC BUILDING_DAEMON_ENGINE)
