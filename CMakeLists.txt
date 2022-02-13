cmake_minimum_required(VERSION 3.11)
project(TrafficSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS " -O0 -Wall -g")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/config)
include_directories(${PROJECT_SOURCE_DIR}/db)
include_directories(${PROJECT_SOURCE_DIR}/io)
include_directories(${PROJECT_SOURCE_DIR}/manager)
include_directories(${PROJECT_SOURCE_DIR}/random)

message(${PROJECT_SOURCE_DIR})

add_library(traffic  STATIC
db/Graph.cc
db/Map.cc
db/Person.cc
db/Bicycle.cc
db/Tricycle.cc
db/Electrocar.cc
db/Transport.cc

io/Log.cc
manager/Manager.cc

random/Random.cc

Simulator.cc
)

add_executable(TestTraffic test/traffic_main.cc)
target_link_libraries(TestTraffic   
    traffic  
)

add_executable(GTest test/gtest_main.cc)
target_link_libraries(GTest   
    traffic 
    libgtest.a libgtest_main.a pthread
)

