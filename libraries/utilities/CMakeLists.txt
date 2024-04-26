add_subdirectory(texture_manager)
add_subdirectory(time)
add_subdirectory(keyboardController)
add_subdirectory(short_names)
add_subdirectory(mouse)

add_library(utilities INTERFACE utilities.hpp)

set_property(TARGET utilities PROPERTY CXX_STANDARD 20)

target_include_directories(utilities INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)