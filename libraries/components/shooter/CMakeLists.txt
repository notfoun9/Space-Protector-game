add_library(shooter shooter.cpp shooter.hpp)

set_property(TARGET shooter PROPERTY CXX_STANDARD 20)
target_link_libraries(shooter game ECS simpleTexture Vector2D)

target_include_directories(shooter PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS shooter)