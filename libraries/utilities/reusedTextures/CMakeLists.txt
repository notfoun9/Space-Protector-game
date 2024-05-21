add_library(reusedTextures reusedTextures.hpp reusedTextures.cpp)

set_property(TARGET reusedTextures PROPERTY CXX_STANDARD 20)
target_link_libraries(reusedTextures game)

target_include_directories(reusedTextures PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS reusedTextures)