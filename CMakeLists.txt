cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(editor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("Make build output path is /bin")

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

target_link_libraries(
    ma

    ${CMAKE_SOURCE_DIR}/lib/systemc/macos/arm/libsystemc.3.0.0.dylib
)

if(NOT WIN32)
    install(TARGETS ma DESTINATION /usr/local/bin)
endif()
