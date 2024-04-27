add_library(follower follower.cpp follower.hpp)

set_property(TARGET follower PROPERTY CXX_STANDARD 20)
target_link_libraries(follower game texture_manager)

target_include_directories(follower PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS follower)