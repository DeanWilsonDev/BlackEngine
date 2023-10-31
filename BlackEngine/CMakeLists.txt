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
  src/BlackEngine.h
  src/BlackEngine/Core.h
  src/BlackEngine/Application.h
  src/BlackEngine/Application.cpp
  src/BlackEngine/EntryPoint.h
  src/BlackEngine/Logging/Log.h
  src/BlackEngine/Logging/Log.cpp
  src/BlackEngine/Logging/Logger.cpp
  src/BlackEngine/Logging/Logger.h
  src/BlackEngine/Events/Event.h
  src/BlackEngine/Events/MouseEvent.h
  src/BlackEngine/Events/KeyEvent.h
  src/BlackEngine/Math/Vector3D.h
  src/BlackEngine/Mesh.h)


target_compile_definitions(BlackEngine PUBLIC BUILDING_BLACK_ENGINE)

if(BLACK_ENGINE_PLATFORM_MACOS)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_MACOS=1)
endif()

if(BLACK_ENGINE_PLATFORM_WINDOWS)
    add_definitions(-DBLACK_ENGINE_BUILD_DLL)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_WINDOWS=1)
endif()
