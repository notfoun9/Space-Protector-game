add_library(game game.cpp game.hpp)

set_property(TARGET game PROPERTY CXX_STANDARD 20)
target_link_libraries(game ECS utilities components short_names time position 
      follower animatedTexture party mouse shooter bullet bulletsCollider bulletHitbox
      meteorHitbox spawner text levels button reusedTextures) 

target_include_directories(game PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game)