cmake_minimum_required(VERSION 3.10) # Укажите минимальную версию CMake
project(servo_hand_emulator)                  # Название проекта

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(common_data)
add_subdirectory(flex_hand)
add_subdirectory(servo_hand)