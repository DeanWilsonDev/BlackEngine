cmake_minimum_required(VERSION 3.25)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)


include_directories(
  ${CMAKE_SOURCE_DIR}/BlackEngine/Source
  ${CMAKE_SOURCE_DIR}/BlackEngine/Packages/spdlog/include
)

add_executable(Sandbox
  Source/Sandbox.cpp
  Source/Sandbox.h
)

add_dependencies(Sandbox CopyDllToSandbox)

add_definitions(
  -DDE_PLATFORM_WINDOWS
  -DDE_PLATFORM_MACOS
  -DDE_BUILD_DLL
)

target_link_libraries(Sandbox BlackEngine)

target_compile_definitions(Sandbox PRIVATE BUILDING_SANDBOX)

add_custom_command(TARGET Sandbox POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/BlackEngine/Debug/BlackEngine.dll"
  $<TARGET_FILE_DIR:Sandbox>
  COMMENT "Copying BlackEngine.dll to output directory"
)

add_custom_target(CopyDllToSandbox DEPENDS BlackEngine CopyDll)