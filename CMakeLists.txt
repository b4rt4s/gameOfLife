cmake_minimum_required(VERSION 3.12)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# Put Your .cpp files in line below
add_library(game_of_life_mvc
        src/GameOfLifeModel.cpp
        src/GameOfLifeView.cpp
        src/GameOfLifeController.cpp
        src/AlwaysNextTurn.cpp
        src/UserCommands.cpp
        src/Cylinder.cpp
        src/Torus.cpp)
# Connect "include" directory with .hpp files to library with.cpp files
target_include_directories(game_of_life_mvc PUBLIC include) 

add_executable(game_of_life src/main.cpp)
# Connect directory with .hpp files and library with.cpp files to executable file
target_link_libraries(game_of_life game_of_life_mvc)

# If You want to write some tests...
option(USE_GTEST "Download compile and provide gtest/gmock" OFF)

if(USE_GTEST)
        include(FetchContent)
        FetchContent_Declare(
                googletest
                GIT_REPOSITORY https://github.com/google/googletest.git
                GIT_TAG main
        )

        FetchContent_MakeAvailable(googletest)

        add_executable(sample_test src/testZero.cpp src/sampleTests.cpp)
        target_include_directories(sample_test PUBLIC include)
        target_link_libraries(sample_test gmock_main gtest gmock)

        add_custom_target(run_tests
                        COMMAND sample_test
                        DEPENDS sample_test)

        enable_testing()
        add_test(tests sample_test)
endif(USE_GTEST)
