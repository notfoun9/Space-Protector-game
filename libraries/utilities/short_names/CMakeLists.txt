add_library(short_names short_names.hpp short_names.cpp)

set_property(TARGET short_names PROPERTY CXX_STANDARD 20)
target_link_libraries(short_names game)

target_include_directories(short_names PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS short_names)