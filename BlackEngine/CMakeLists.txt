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
set(PCH_FILE_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/${PCH_FILE}")
set(PCH_FILE_HEADER
    "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/${PCH_FILE}.pch"
)

add_custom_command(
  OUTPUT ${PCH_FILE_HEADER}
  COMMAND
    /user/bin/clang++ -x c++-header ${PCH_FILE_SOURCE} -o ${PCH_FILE_HEADER}
  DEPENDS ${PCH_FILE_SOURCE}
  COMMENT
    "Creating Precompiled Header for ${ENGINE_NAME} library to output directory: ${PCH_FILE_HEADER}"
)

message("HEADER LOCATION: ${PCH_FILE_HEADER}")
message("SOURCE LOCATION: ${PCH_FILE_SOURCE}")
message("COMPILER: ${CMAKE_CXX_COMPILER}")

add_custom_target(GeneratePrecompiledHeader  DEPENDS ${PCH_FILE_HEADER})

# Generate .dll file
add_library(
  ${PROJECT_NAME} SHARED
  "src/BlackEngine.h"
  "src/${PROJECT_NAME}/Core.h"
  "src/${PROJECT_NAME}/Application.h"
  "src/${PROJECT_NAME}/Application.cpp"
  "src/${PROJECT_NAME}/EntryPoint.h"
  "src/${PROJECT_NAME}/Logging/Log.h"
  "src/${PROJECT_NAME}/Logging/Log.cpp"
  "src/${PROJECT_NAME}/Logging/Logger.cpp"
  "src/${PROJECT_NAME}/Logging/Logger.h"
  "src/${PROJECT_NAME}/Events/Event.h"
  "src/${PROJECT_NAME}/Events/MouseEvent.h"
  "src/${PROJECT_NAME}/Events/KeyEvent.h"
  "src/${PROJECT_NAME}/Events/ApplicationEvent.h"
  "src/${PROJECT_NAME}/Math/Vector3D.h"
  "src/${PROJECT_NAME}/Mesh.h")

add_dependencies(${PROJECT_NAME} GeneratePrecompiledHeader)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/"
    )

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/"
)
# Specify that the precompiled header should be used
target_precompile_headers(${PROJECT_NAME} PRIVATE "${PCH_FILE_SOURCE}")

target_compile_definitions(${PROJECT_NAME} PUBLIC BUILDING_BLACK_ENGINE)

# Compile Mac Platform Definitions
if(-DBLACK_ENGINE_PLATFORM_MACOS)
  target_compile_definitions(${PROJECT_NAME}
                             PUBLIC BLACK_ENGINE_PLATFORM_MACOS=1)
endif()

# Compile Windows Platform Definitions
if(-DBLACK_ENGINE_PLATFORM_WINDOWS)
  add_definitions(-DBLACK_ENGINE_PLATFORM_WINDOWS)
  add_definitions(-DBLACK_ENGINE_BUILD_DLL)
  target_compile_definitions(${PROJECT_NAME}
                             PUBLIC BLACK_ENGINE_PLATFORM_WINDOWS=1)
endif()
