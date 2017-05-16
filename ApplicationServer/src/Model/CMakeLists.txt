project(${PROJECT_NAME} C CXX)

add_library(model Song.cpp Song.h)
target_link_libraries(model ${LIBS_NAMES})