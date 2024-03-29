cmake_minimum_required(VERSION 3.0)
project(lucene++-demo)

file(GLOB_RECURSE
  demo_headers
  "${lucene++-demo_SOURCE_DIR}/../include/*.h"
)

add_definitions(-DLPP_HAVE_DLL)
find_package(Boost 1.61.0 COMPONENTS system REQUIRED)

include_directories(
  ${Boost_INCLUDE_DIRS}
)

include_directories(
  "${lucene++_SOURCE_DIR}/include"
)

add_executable(indexfiles
  "${lucene++-demo_SOURCE_DIR}/indexfiles/main.cpp"
  ${demo_headers}
)
target_link_libraries(indexfiles
  lucene++ ${Boost_SYSTEM_LIBRARIES}
)

add_executable(searchfiles
  "${lucene++-demo_SOURCE_DIR}/searchfiles/main.cpp"
  ${demo_headers}
)
target_link_libraries(searchfiles
  lucene++ ${Boost_SYSTEM_LIBRARIES}
)

add_executable(deletefiles
  "${lucene++-demo_SOURCE_DIR}/deletefiles/main.cpp"
  ${demo_headers}
)
target_link_libraries(deletefiles
  lucene++ ${Boost_SYSTEM_LIBRARIES}
)
