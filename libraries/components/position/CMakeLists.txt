add_library(position position.cpp position.hpp)

set_property(TARGET position PROPERTY CXX_STANDARD 20)
target_link_libraries(position game ECS simpleTexture)

target_include_directories(position PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS position)