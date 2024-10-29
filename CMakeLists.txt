cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(editor VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -D_XOPEN_SOURCE_EXTENDED")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
message("Make build output path is ./bin")

# Describes all available state properties.
add_compile_definitions(AWAIT_INPUT_STATE=0)
add_compile_definitions(RECORD_INPUT_STATE=1)
add_compile_definitions(CONVERT_INPUT_STATE=2)

# Describes configuration for pipeline batch.
add_compile_definitions(PIPELINE_BATCH_SIZE=1000)

# Describes configuration for logger functionality.
add_compile_definitions(LOG_FILE="logs/output.log")
add_compile_definitions(DEFAULT_LOG_TYPE="default")

# Describes configuration for signals management.
add_compile_definitions(HIGH_SIGNAL=1)

# Descrbies range of allowed input ASCII symbol codes.
add_compile_definitions(NUMBER_MIN_ASCII_RANGE=48)
add_compile_definitions(NUMBER_MAX_ASCII_RANGE=57)
add_compile_definitions(LETTER_MIN_ASCII_RANGE=65)
add_compile_definitions(LETTER_MAX_ASCII_RANGE=90)

enable_testing()

add_subdirectory(tests)
