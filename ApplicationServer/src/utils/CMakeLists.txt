project(${PROJECT_NAME} C CXX)

add_library(utils LoggerManager.cpp LoggerManager.h)
target_link_libraries(utils ${LIBS_NAMES})