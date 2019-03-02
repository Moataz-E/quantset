cmake_minimum_required(VERSION 3.0)
project(quantset)

file(GLOB_RECURSE SOURCES
    "./quantset/*.cpp"
)
file(GLOB_RECURSE HEADERS
    "/quantset/*.h"
)

set(Eigen3_DIR ./third_party/eigen3)
include_directories("${Eigen3_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})
