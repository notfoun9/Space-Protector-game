add_subdirectory(position)
add_subdirectory(simpleTexture)

add_library(components INTERFACE components.hpp)

set_property(TARGET components PROPERTY CXX_STANDARD 20)

target_include_directories(components INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)