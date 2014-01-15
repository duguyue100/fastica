cmake_minimum_required (VERSION 2.8)

project (fastica)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package (OpenCV REQUIRED)

add_library (icalib include/sys_lib.h include/recursive_ica.h)
set_target_properties(icalib PROPERTIES LINKER_LANGUAGE CXX)
include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable (recursiveica src/recursiveica.cpp)
target_link_libraries(recursiveica ${OpenCV_LIBS})
target_link_libraries(recursiveica icalib)