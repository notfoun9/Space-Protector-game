add_library(animatedTexture animatedTexture.cpp animatedTexture.hpp)

set_property(TARGET animatedTexture PROPERTY CXX_STANDARD 20)
target_link_libraries(animatedTexture game ECS simpleTexture Vector2D)

target_include_directories(animatedTexture PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS animatedTexture)