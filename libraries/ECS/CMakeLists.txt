add_library(ECS ECS.cpp ECS.hpp)

set_property(TARGET ECS PROPERTY CXX_STANDARD 20)
target_link_libraries(ECS game position simpleTexture)

target_include_directories(ECS PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS ECS)