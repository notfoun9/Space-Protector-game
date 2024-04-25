add_library(mouse mouse.cpp mouse.hpp)

set_property(TARGET mouse PROPERTY CXX_STANDARD 20)
target_link_libraries(mouse game texture_manager)

target_include_directories(mouse PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS mouse)