add_library(animation animation.cpp animation.hpp)

set_property(TARGET animation PROPERTY CXX_STANDARD 20)
target_link_libraries(animation game)

target_include_directories(animation PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS animation)