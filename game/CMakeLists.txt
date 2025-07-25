add_library(game game.cpp game.hpp)

set_property(TARGET game PROPERTY CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "/opt/homebrew;${CMAKE_PREFIX_PATH}")

target_link_libraries(game
      ${SDL3_LIBRARIES}
      SDL3_ttf::SDL3_ttf
      SDL3_image::SDL3_image
      
      ECS utilities components short_names time position 
      follower animatedTexture party mouse shooter bullet bulletsCollider bulletHitbox meteorHitbox spawner text levels button reusedTextures
) 

target_include_directories(game PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game)
