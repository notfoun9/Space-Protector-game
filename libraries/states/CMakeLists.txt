add_subdirectory(levels)
add_subdirectory(party)

add_library(states INTERFACE states.hpp)

set_property(TARGET states PROPERTY CXX_STANDARD 20)

target_include_directories(states INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)