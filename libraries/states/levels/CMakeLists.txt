add_library(levels levels.cpp levels.hpp)

set_property(TARGET levels PROPERTY CXX_STANDARD 20)
target_link_libraries(levels game)

target_include_directories(levels PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS levels)