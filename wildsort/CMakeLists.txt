cmake_minimum_required(VERSION 3.20)
project(wildsort)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(COMMON_COMPILER_FLAGS "-pedantic -Wall -Werror")

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDES_DIR "${PROJECT_SOURCE_DIR}/include")

set(SRCS "${SOURCE_DIR}/wildsort.c")
set(INCLUDES "${INCLUDES_DIR}/wildsort.h")

add_library(wildsort SHARED ${SRCS})
set(wildsort
    PROPERTIES CMAKE_COMPILER_FLAGS "${CMAKE_COMPILER_FLAGS} ${COMMON_COMPILER_FLAGS}"
    )

install(TARGETS wildsort DESTINATION lib)
install(FILES ${INCLUDES} DESTINATION includes)

include(CTest)

set(TEST_SRCS_DIR "${PROJECT_SOURCE_DIR}/test")
set(TEST_SRCS "${TEST_SRCS_DIR}/wildsort_test.c")

find_package(Criterion REQUIRED)
get_target_property(CRITERION_INCLUDES Criterion::criterion INTERFACE_INCLUDE_DIRECTORIES)
if (CRITERION_INCLUDES-NOTFOUND)
    messgae(ERROR "Didn't find any includes path for criterion package")
else()
    message(STATUS "Found criterion includes path at ${CRITERION_INCLUDES}")
endif()

add_executable(wildsorttest ${TEST_SRCS})
set(wildsorttest
    PROPERTIES CMAKE_COMPILER_FLAGS "${CMAKE_COMPILER_FLAGS} ${COMMON_COMPILER_FLAGS}"
    )
target_link_libraries(wildsorttest PRIVATE wildsort Criterion::criterion)
target_include_directories(wildsorttest PRIVATE "${INCLUDES_DIR}"  "${CRITERION_INCLUDES}")

add_test(NAME "Wildsort Tests" COMMAND wildsorttest)
