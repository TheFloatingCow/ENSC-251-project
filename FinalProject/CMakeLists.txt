cmake_minimum_required(VERSION 3.23)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject main.cpp student.cpp stu_sort.cpp list.cpp toeflscore.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/domestic-stu.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/international-stu.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})