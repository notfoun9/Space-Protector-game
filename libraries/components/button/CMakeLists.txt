add_library(button button.cpp button.hpp)

set_property(TARGET button PROPERTY CXX_STANDARD 20)
target_link_libraries(button game)

target_include_directories(button PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS button)
