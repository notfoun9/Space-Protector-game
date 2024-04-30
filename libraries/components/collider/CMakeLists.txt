add_library(collider collider.cpp collider.hpp)

set_property(TARGET collider PROPERTY CXX_STANDARD 20)
target_link_libraries(collider game texture_manager)

target_include_directories(collider PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS collider)