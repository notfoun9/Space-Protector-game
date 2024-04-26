add_library(keyboardController keyboardController.cpp keyboardController.hpp)

set_property(TARGET keyboardController PROPERTY CXX_STANDARD 20)
target_link_libraries(keyboardController game)

target_include_directories(keyboardController PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS keyboardController)