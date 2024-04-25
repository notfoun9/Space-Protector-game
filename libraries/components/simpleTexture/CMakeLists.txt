add_library(simpleTexture simpleTexture.cpp simpleTexture.hpp)

set_property(TARGET simpleTexture PROPERTY CXX_STANDARD 20)
target_link_libraries(simpleTexture game texture_manager ECS)

target_include_directories(simpleTexture PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS simpleTexture)