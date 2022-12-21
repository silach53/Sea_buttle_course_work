add_library(UUU UUU.hpp ClikeUUU.h UUU.cpp ClikeUUU.cpp)
add_library(Lamda SHARED UUU.hpp ClikeUUU.h UUU.cpp ClikeUUU.cpp)

add_executable(UUU_main UUU_main.cpp)
add_executable(UUU_main_C UUU_main.c)

target_link_libraries(UUU_main UUU)
target_link_libraries(UUU_main_C UUU)
