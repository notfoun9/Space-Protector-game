add_library(spawner spawner.cpp spawner.hpp)

set_property(TARGET spawner PROPERTY CXX_STANDARD 20)
target_link_libraries(spawner game ECS simpleTexture Vector2D)

target_include_directories(spawner PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS spawner)