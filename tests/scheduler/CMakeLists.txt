file(GLOB INCLUDE_FILES ${CMAKE_SOURCE_DIR}/include/*)

include_directories(${INCLUDE_FILES})

link_directories(
    ${CMAKE_SOURCE_DIR}/lib
)

file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/**/*.cpp)

add_executable(
    scheduler 
    
    scheduler_tb.cpp
    ${SRC_FILES}
)

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
    target_link_libraries(
        scheduler 
        
        ${CMAKE_SOURCE_DIR}/lib/systemc/linux/x86/libsystemc.a)
elseif(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    target_link_libraries(
        scheduler

        ${CMAKE_SOURCE_DIR}/lib/systemc/macos/arm/libsystemc.3.0.0.dylib
    )
endif()

add_test(NAME scheduler COMMAND scheduler)