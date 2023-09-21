cmake_minimum_required(VERSION 3.25)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

add_executable(Sandbox Source/main.cpp)
target_link_libraries(Sandbox DaemonEngine)

target_compile_definitions(Sandbox PRIVATE BUILDING_SANDBOX)
