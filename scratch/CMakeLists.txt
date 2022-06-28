cmake_minimum_required(VERSION 3.0.0)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZLIB_INCLUDE_DIR /usr/include)
include(CPack)

project(scratch VERSION 0.1.0)

include(CTest)
enable_testing()

# # Creating and adding a static library
# add_library(blah STATIC src/blah.cpp)
# # source headers for the library
target_include_directories(scratch PUBLIC ${ZLIB_INCLUDE_DIR})
add_subdirectory(blah)


# Add a library already installed in the system
find_library(ZLIB libz.a REQUIRED)
# Including the source files
# recursively search for files in the src directory
# file(GLOB_RECURSE SRC_FILES src/*.cpp)
# add_executable(scratch main.cpp ${SRC_FILES})
add_executable(scratch main.cpp)

# Including the header files
# include directories
# target_include_directories(scratch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# Instead of adding the source and the headers to the target, we can addthe libraries to the target
target_link_libraries(scratch PUBLIC blah ${zlib})
