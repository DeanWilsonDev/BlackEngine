cmake_minimum_required(VERSION 3.25)
project(daemon_engine_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  daemon_engine_test
  src/logging/Logger_Test.cpp
)

target_link_libraries(
  daemon_engine_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(daemon_engine_test)

### End of Google Test

add_dependencies(daemon_engine_test CopyDllToDaemonEngineTest)

add_definitions(
  -DDE_PLATFORM_WINDOWS
  -DDE_PLATFORM_MACOS
  -DDE_BUILD_DLL
)

target_link_libraries(daemon_engine_test DaemonEngine)

target_compile_definitions(daemon_engine_test PRIVATE BUILDING_DAEMON_ENGINE_TEST)

add_custom_command(TARGET daemon_engine_test POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/DaemonEngine/Debug/DaemonEngine.dll"
  $<TARGET_FILE_DIR:daemon_engine_test>
  COMMENT "Copying DaemonEngine.dll to output directory"
)

add_custom_target(CopyDllToDaemonEngineTest DEPENDS DaemonEngine CopyDll)