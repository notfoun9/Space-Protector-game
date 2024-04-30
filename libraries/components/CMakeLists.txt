add_subdirectory(position)
add_subdirectory(shooter)
add_subdirectory(mouse)
add_subdirectory(follower)
add_subdirectory(simpleTexture)
add_subdirectory(animatedTexture)
add_subdirectory(bulletsCollider)
add_subdirectory(meteorHitbox)

add_library(components INTERFACE components.hpp)
set_property(TARGET components PROPERTY CXX_STANDARD 20)

target_include_directories(components INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)