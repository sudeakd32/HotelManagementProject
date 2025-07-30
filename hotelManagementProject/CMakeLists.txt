cmake_minimum_required(VERSION 3.30)
project(hotelManagementProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(hotelManagementProject main.cpp
        Customer.h
        Customer.cpp
        Room.h
        Room.cpp
        HotelManagement.h
        HotelManagement.cpp
        HotelGlobals.h)
