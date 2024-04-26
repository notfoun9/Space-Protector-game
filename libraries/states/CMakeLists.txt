add_subdirectory(menu)
# add_subdirectory(texture_manager)
# add_subdirectory(keyboardController)
# add_subdirectory(short_names)
# add_subdirectory(mouse)

add_library(states INTERFACE states.hpp)

set_property(TARGET states PROPERTY CXX_STANDARD 20)

target_include_directories(states INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)