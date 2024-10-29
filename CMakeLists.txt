cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(editor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("Make build output path is /bin")

# Describes all available state properties.
add_compile_definitions(AWAIT_INPUT_STATE=0)
add_compile_definitions(RECORD_INPUT_STATE=1)
add_compile_definitions(CONVERT_INPUT_STATE=2)

# Describes configuration for pipeline batch.
add_compile_definitions(PIPELINE_BATCH_SIZE=1)

# Describes configuration for logger functionality.
add_compile_definitions(LOG_FILE="logs/output.log")
add_compile_definitions(DEFAULT_LOG_TYPE="default")

file(GLOB INCLUDE_FILES ${PROJECT_SOURCE_DIR}/include/*)

include_directories(${INCLUDE_FILES})

link_directories(
    "lib/"
)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/**/*.cpp)

add_executable(
    ma

    ${SRC_FILES}
)

target_link_libraries(
    ma

    ${CMAKE_SOURCE_DIR}/lib/systemc/macos/arm/libsystemc.3.0.0.dylib
)

if(NOT WIN32)
    install(TARGETS ma DESTINATION /usr/local/bin)
endif()
