add_library(meteorHitbox meteorHitbox.cpp meteorHitbox.hpp)

set_property(TARGET meteorHitbox PROPERTY CXX_STANDARD 20)
target_link_libraries(meteorHitbox game texture_manager)

target_include_directories(meteorHitbox PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS meteorHitbox)