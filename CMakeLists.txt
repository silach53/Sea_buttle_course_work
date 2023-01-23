project(Sea_battle_course)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(prj.lab prj.thirdparty)
add_subdirectory(prj.lab)

install(TARGETS ${Sea_battle_course} DESTINATION Lamda)