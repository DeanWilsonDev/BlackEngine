cmake_minimum_required(VERSION 3.25)
project(DaemonEngine)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

# Generate .dll file
add_library(
  DaemonEngine SHARED
  Source/DaemonEngine/Core.cpp
  Source/DaemonEngine/Math.h
  Source/DaemonEngine/Core.h
  Source/DaemonEngine/Mesh.h
  Source/DaemonEngine/Log.h
  Source/DaemonEngine/Log.cpp
  Source/DaemonEngine/Application.h
  Source/DaemonEngine/Application.cpp
  Source/DaemonEngine.h
  Source/DaemonEngine/EntryPoint.h
  Source/DaemonEngine/Logging/Logger.cpp
  Source/DaemonEngine/Logging/Logger.h
  Packages/DocTest/doctest.h
  Source/DaemonEngine/Logging/Logger.test.h
)

target_include_directories(
  DaemonEngine PUBLIC
  "${CMAKE_SOURCE_DIR}/DaemonEngine/Packages/spdlog/include"
  "${CMAKE_SOURCE_DIR}/DaemonEngine/Packages/DocTest"
)

add_definitions(
  # -DDE_PLATFORM_WINDOWS
  -DDE_PLATFORM_MACOS
  -DDE_BUILD_DLL
)


target_compile_definitions(DaemonEngine PUBLIC BUILDING_DAEMON_ENGINE)
