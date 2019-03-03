cmake_minimum_required(VERSION 3.0)
project(quantset)

find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES
    "./quantset/*.cpp"
)
file(GLOB_RECURSE HEADERS
    "/quantset/*.h"
)

set(Eigen3_DIR "./third_party/eigen3")
include_directories("${Eigen3_DIR}")

set(GoogleTest_DIR "./third_party/googletest")
set(GTestSrc ${GoogleTest_DIR}/googletest)
set(GMockSrc ${GoogleTest_DIR}/googlemock)
include_directories("${GoogleTest_DIR}")
include_directories(${GTestSrc} ${GTestSrc}/include ${GMockSrc} ${GMockSrc}/include)

# Uncomment this and comment the next three calls to build this as a library.
#add_library(${PROJECT_NAME} SHARED ${SOURCES})
#install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})
#install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp ${HEADERS} ${SOURCES}
               ${GTestSrc}/src/gtest-all.cc
               ${GMockSrc}/src/gmock-all.cc)
add_test(${PROJECT_NAME} COMMAND ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)
