add_library(time time.hpp time.cpp)

set_property(TARGET time PROPERTY CXX_STANDARD 20)
target_link_libraries(time game)

target_include_directories(time PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS time)