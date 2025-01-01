
cmake_minimum_required(VERSION 3.10) # Минимальная версия CMake
project(common_data)                  # Имя проекта


# Добавляем библиотеку
add_library(${PROJECT_NAME} STATIC
    src/common_data.cpp
)

# Указываем директорию заголовочных файлов
target_include_directories(${PROJECT_NAME} PUBLIC include)