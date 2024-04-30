add_library(bulletsCollider bulletsCollider.cpp bulletsCollider.hpp)

set_property(TARGET bulletsCollider PROPERTY CXX_STANDARD 20)
target_link_libraries(bulletsCollider game texture_manager)

target_include_directories(bulletsCollider PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS bulletsCollider)