cmake_minimum_required(VERSION 3.25)
project(BlackEngine)

set(CMAKE_CXX_STANDARD 17)

# Set Directory Variables
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

# Generate .pch file
set(PCH_FILE "blkpch.h")
set(PCH_FILE_SOURCE ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/${PCH_FILE})
set(PCH_FILE_HEADER ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${PCH_FILE}.gch)

# include guards in PCH file
configure_file(${PCH_FILE_SOURCE} ${PCH_FILE_SOURCE} COPYONLY)

add_custom_command(
  OUTPUT ${PCH_FILE_HEADER}
  COMMAND ${CMAKE_CXX_COMPILER} -x c++-header ${PCH_FILE_SOURCE} -o
          ${PCH_FILE_HEADER}
  DEPENDS ${PCH_FILE_SOURCE})

add_custom_target(${PCH_FILE} DEPENDS ${PCH_FILE_HEADER})

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

# Link the precompiled header to the library
add_dependencies(BlackEngine ${PCH_FILE})
target_include_directories(BlackEngine
                           PRIVATE ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
target_sources(BlackEngine PRIVATE ${PCH_FILE_HEADER})

# Specify that the precompiled header should be used
target_precompile_headers(BlackEngine PRIVATE
                          ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${PCH_FILE}.gch)

target_compile_definitions(BlackEngine PUBLIC BUILDING_BLACK_ENGINE)

# Compile Mac Platform Definitions
if(BLACK_ENGINE_PLATFORM_MACOS)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_MACOS=1)
endif()

# Compile Windows Platform Definitions
if(BLACK_ENGINE_PLATFORM_WINDOWS)
    add_definitions(-DBLACK_ENGINE_BUILD_DLL)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_WINDOWS=1)
endif()
