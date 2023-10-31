cmake_minimum_required(VERSION 3.25)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

target_include_directories(BlackEngine PUBLIC 
    ${CMAKE_SOURCE_DIR}/BlackEngine/src/
    )


add_executable(Sandbox
  src/Sandbox.cpp
  src/Sandbox.h
)

add_dependencies(Sandbox CopyDllToSandbox)

if(BLACK_ENGINE_PLATFORM_MACOS)
    set(BLACK_ENGINE_DYNAMIC_LIBARARY_FILE libBlackEngine.dylib)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_MACOS=1)
    target_link_libraries(Sandbox PRIVATE BlackEngine)
endif()

if(BLACK_ENGINE_PLATFORM_WINDOWS)
    set(BLACK_ENGINE_DYNAMIC_LIBARARY_FILE BlackEngine.dll)
    add_definitions(-DBLACK_ENGINE_BUILD_DLL)
    target_compile_definitions(BlackEngine PUBLIC BLACK_ENGINE_PLATFORM_WINDOWS=1)
    target_link_libraries(Sandbox PRIVATE BlackEngine.dll)
endif()


target_compile_definitions(Sandbox PRIVATE BUILDING_SANDBOX)

set(SOURCE_DLL "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/BlackEngine/${BLACK_ENGINE_DYNAMIC_LIBARARY_FILE}")

set(DESTINATION_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}")

add_custom_command(TARGET Sandbox POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${SOURCE_DLL}
  ${DESTINATION_DIR}
  COMMENT "Copying BlackEngine library to output directory"
)

add_custom_target(CopyDllToSandbox DEPENDS BlackEngine)

