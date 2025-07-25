
set (CMAKE_PREFIX_PATH "../src/lib")

add_executable(main main.cpp)

target_link_libraries(main game)

link_directories(lib)
