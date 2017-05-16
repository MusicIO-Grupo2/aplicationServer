project(${PROJECT_NAME} C CXX)

add_library(controllers HelloWorldController.cpp HelloWorldController.h SongController.cpp SongController.h)
target_link_libraries(Model utils ${LIBS_NAMES})