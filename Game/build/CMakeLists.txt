cmake_minimum_required(VERSION 3.0.0)

project(Game VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs -s")  
## If you want to link SFML statically


## In most cases better set in the CMake cache

if(WIN32) 
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "./SFML/lib/cmake/SFML")
elseif()
    
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(SFML 2.5 COMPONENTS graphics window system network REQUIRED)

include_directories(./thorinclude ../include)
link_directories(./thorlib)

add_executable(Game ../src/main.cpp ../src/Game.cpp ../src/GameEngine/gameengine.cpp ../src/scenes/scenes.cpp ../src/gui/GUI.cpp ../src/realm/realm.cpp ../src/realm/tilemap.cpp)
target_link_libraries(Game sfml-graphics sfml-window sfml-system sfml-network ${CMAKE_THREAD_LIBS_INIT} thor-s -static)
set_target_properties(Game PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")
