cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(editor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("Make build output path is /bin")

# Describes all available state properties.
add_compile_definitions(AWAIT_INPUT_STATE=0)
add_compile_definitions(START_INPUT_STATE=1)
add_compile_definitions(END_INPUT_STATE=2)
add_compile_definitions(CONVERT_INPUT_STATE=3)

file(GLOB INCLUDE_FILES ${PROJECT_SOURCE_DIR}/include/*)

include_directories(${INCLUDE_FILES})

link_directories(
    "lib/"
)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/**/*.cpp)

add_executable(
    ma

    ${SRC_FILES}
)

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
    target_link_libraries(ma ${PROJECT_SOURCE_DIR}/lib/systemc/linux/x86_64/libsystemc-3.0.0.so)
elseif (${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    target_link_libraries(ma ${CMAKE_SOURCE_DIR}/lib/systemc/macos/arm/libsystemc.3.0.0.dylib)
endif()

if(NOT WIN32)
    install(TARGETS ma DESTINATION /usr/local/bin)
endif()
