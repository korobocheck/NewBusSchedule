cmake_minimum_required(VERSION 3.28)
project(labVika)

set(CMAKE_CXX_STANDARD 20)

add_executable(labVika main.cpp
        Schedule.cpp
        Schedule.h
        Trip.cpp
        Trip.h
        BusTrip.cpp
        BusTrip.h
        Vechile.h
)
