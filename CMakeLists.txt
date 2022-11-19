cmake_minimum_required(VERSION 3.23)
project(chore-chart)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        main.cpp Helper.cpp Chore.cpp Schedule.cpp Activity.cpp Errand.cpp)
add_executable(testing
        testing.cpp Helper.cpp Chore.cpp Schedule.cpp Activity.cpp Errand.cpp)
