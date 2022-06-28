# Creating and adding a static library
add_library(blah STATIC blah.cpp)
# source headers for the library
target_include_directories(blah PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)