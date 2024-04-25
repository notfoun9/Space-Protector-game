add_library(Vector2D Vector2D.cpp Vector2D.hpp)

set_property(TARGET Vector2D PROPERTY CXX_STANDARD 20)
target_link_libraries(Vector2D game)

target_include_directories(Vector2D PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS Vector2D)