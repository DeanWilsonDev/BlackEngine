cmake_minimum_required(VERSION 3.25)
project(BlackEngineTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(BlackEngineTest src/logging/Logger_Test.cpp)

target_link_libraries(BlackEngineTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(BlackEngineTest)

# End of Google Test

add_dependencies(BlackEngineTest CopyDllToBlackEngineTest)

add_definitions(-DDE_PLATFORM_WINDOWS -DDE_PLATFORM_MACOS -DDE_BUILD_DLL)

set(SOURCE_DLL "${CMAKE_SOURCE_DIR}/BlackEngine/Source/BlackEngine.dll")

set(DESTINATION_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}")

target_link_libraries(BlackEngineTest BlackEngine)

target_compile_definitions(BlackEngineTest PRIVATE BUILDING_DAEMON_ENGINE_TEST)

add_custom_command(
  TARGET BlackEngineTest
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${SOURCE_DLL}
    ${DESTINATION_DIR}
  COMMENT "Copying BlackEngine.dll to output directory")

add_custom_target(CopyDllToBlackEngineTest DEPENDS BlackEngine)
