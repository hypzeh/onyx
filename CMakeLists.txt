cmake_minimum_required(VERSION 3.15)
project(Onyx
        VERSION 0.0.1
        LANGUAGES C CXX
        DESCRIPTION "Onyx Rendering Engine"
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ONYX_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(ONYX_ARTIFACTS_DIR ${ONYX_ROOT_DIR}/artifacts)
set(ONYX_LIB_DIR ${ONYX_ROOT_DIR}/lib)
set(ONYX_SRC_DIR ${ONYX_ROOT_DIR}/src)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ONYX_ARTIFACTS_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ONYX_ARTIFACTS_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ONYX_ARTIFACTS_DIR}/bin)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${ONYX_ROOT_DIR}/include)

add_subdirectory(${ONYX_LIB_DIR}/glfw)
include_directories(${ONYX_LIB_DIR}/glfw/include/)

add_subdirectory(${ONYX_SRC_DIR}/Onyx.Engine)
add_subdirectory(${ONYX_SRC_DIR}/Onyx.Sandbox)
