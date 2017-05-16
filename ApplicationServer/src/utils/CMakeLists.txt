project(${PROJECT_NAME} C CXX)

add_library(utils base64.cpp base64.h LoggerManager.cpp LoggerManager.h MongoManager.cpp MongoManager.h)
target_link_libraries(utils ${LIBS_NAMES})