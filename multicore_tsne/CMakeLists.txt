PROJECT(tsne_multicore CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)
CMAKE_POLICY(VERSION 2.8)

SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14 -g")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lm")

IF(MSVC)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /fp:fast /O2")
ELSE()
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -fPIC -ffast-math -funroll-loops")
ENDIF()

include(TBBGet.cmake)
tbb_get(TBB_ROOT tbb_root SOURCE_CODE)

include(${tbb_root}/cmake/TBBBuild.cmake)
tbb_build(TBB_ROOT ${tbb_root} CONFIG_DIR TBB_DIR)

find_package(TBB REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_TBB")

file(GLOB src *.cpp)
add_library(tsne_multicore SHARED ${src})
target_link_libraries(tsne_multicore ${TBB_IMPORTED_TARGETS})
