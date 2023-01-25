project(Sea_battle_course)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 14)

enable_testing()

include_directories(prj.lab prj.thirdparty)
add_subdirectory(prj.lab)


if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install" CACHE PATH "..." FORCE)
endif()

install(TARGETS Lamda RUNTIME DESTINATION .)
install(FILES main.py DESTINATION .)
install(FILES sea.py DESTINATION .)
install(FILES config.txt DESTINATION .)