cmake_minimum_required(VERSION 3.10) # Укажите минимальную версию CMake
project(flex_hand)                  # Название проекта

add_executable(${PROJECT_NAME} src/main.cpp) # Создание исполняемого файла из main.cpp

target_link_libraries(${PROJECT_NAME} PRIVATE common_data)