cmake_minimum_required(VERSION 3.7.2)
project(Session0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Session0 main.cpp)

# for link error like undefined reference to `pthread_getspecific'
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

target_link_libraries(Session0
    pthread
    gmock
    gtest
)
