cmake_minimum_required(VERSION 3.25)
project(Sandbox)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}/)

set(ENGINE_NAME "BlackEngine")

add_executable(${PROJECT_NAME}
  src/Sandbox.cpp
  src/Sandbox.h
)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_SOURCE_DIR}/${ENGINE_NAME}/src/
    )

target_link_libraries(${PROJECT_NAME} PUBLIC ${ENGINE_NAME})

add_dependencies(${PROJECT_NAME} "CopyDllTo${PROJECT_NAME}")

if(BLACK_ENGINE_PLATFORM_MACOS)
    set(ENGINE_LIBRARY_NAME "lib${ENGINE_NAME}.dylib")
    target_compile_definitions(${PROJECT_NAME} PUBLIC BLACK_ENGINE_PLATFORM_MACOS=1)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ENGINE_LIBRARY_NAME})
endif()

if(BLACK_ENGINE_PLATFORM_WINDOWS)
    set(ENGINE_LIBRARY_NAME "${ENGINE_NAME}.dll")
    add_definitions(-DBLACK_ENGINE_BUILD_DLL)
    target_compile_definitions(${PROJECT_NAME} PUBLIC BLACK_ENGINE_PLATFORM_WINDOWS=1)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ENGINE_LIBRARY_NAME})
endif()


target_compile_definitions(${PROJECT_NAME} PRIVATE "BUILDING_${PROJECT_NAME}")

set(SOURCE_DLL "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${ENGINE_NAME}/${ENGINE_LIBRARY_NAME}")

set(DESTINATION_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/bin/${CMAKE_SYSTEM_PROCESSOR}/${PROJECT_NAME}")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${SOURCE_DLL}
  ${DESTINATION_DIR}
  COMMENT "Copying ${ENGINE_NAME} library to output directory"
)

add_custom_target("CopyDllTo${PROJECT_NAME}" DEPENDS ${ENGINE_NAME})

