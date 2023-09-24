cmake_minimum_required(VERSION 3.25)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

include_directories(
        ${CMAKE_SOURCE_DIR}/DaemonEngine/Source
        ${CMAKE_SOURCE_DIR}/DaemonEngine/Packages/spdlog/include
)

add_executable(Sandbox
        Source/Sandbox.cpp
        Source/Sandbox.h
)

add_definitions(
        -DDE_PLATFORM_WINDOWS
        -DDE_BUILD_DLL
)


target_link_libraries(Sandbox DaemonEngine)

target_compile_definitions(Sandbox PRIVATE BUILDING_SANDBOX)

