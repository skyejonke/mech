cmake_minimum_required(VERSION 3.5)
project (dog LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CXX,"g++")
include_directories ("skyelib")
include_directories ("include")
add_subdirectory (skyelib)


SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_library(mechlib STATIC src/item.cpp)
target_link_libraries(mechlib skyelib)
#add_executable(dog src/main.cpp)
#target_link_libraries(dog doglib)
add_executable(mechtests test/test.cpp test/catch.hpp)
target_link_libraries(mechtests mechlib)
install(TARGETS mechlib
	RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
enable_testing()
add_test(NAME MainTest COMMAND mechtests)
