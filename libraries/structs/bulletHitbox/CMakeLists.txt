add_library(bulletHitbox bulletHitbox.cpp bulletHitbox.hpp)

set_property(TARGET bulletHitbox PROPERTY CXX_STANDARD 20)
target_link_libraries(bulletHitbox game bullet)

target_include_directories(bulletHitbox PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS bulletHitbox)