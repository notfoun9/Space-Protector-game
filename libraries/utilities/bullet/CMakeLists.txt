add_library(bullet bullet.cpp bullet.hpp)

set_property(TARGET bullet PROPERTY CXX_STANDARD 20)
target_link_libraries(bullet game texture_manager)

target_include_directories(bullet PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS bullet)