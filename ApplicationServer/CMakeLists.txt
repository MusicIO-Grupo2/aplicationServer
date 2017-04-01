cmake_minimum_required(VERSION 3.7)
project(ApplicationServer)
set(PROJECT_NAME "ApplicationServer")
set(CMAKE_CXX_STANDARD 11)

set(ROOT_PATH "${${PROJECT_NAME}_SOURCE_DIR}")


set(SRC_PATH "${ROOT_PATH}/src")

set(SOURCE_FILES src/main.cpp src/controllers/HelloWorldController.cpp src/controllers/HelloWorldController.h)



set(LIBS_PATH "${ROOT_PATH}/lib")
set(LIBS_NAMES mongoose jsoncpp)

set(MONGOOSE_CPP "${LIBS_PATH}/mongoose")

set(MONGOOSE_SOURCES
        ${MONGOOSE_SOURCES}
        ${MONGOOSE_CPP}/Utils.cpp
        ${MONGOOSE_CPP}/Controller.cpp
        ${MONGOOSE_CPP}/Mutex.cpp
        ${MONGOOSE_CPP}/mongoose.c
        ${MONGOOSE_CPP}/Request.cpp
        ${MONGOOSE_CPP}/Response.cpp
        ${MONGOOSE_CPP}/Server.cpp
        ${MONGOOSE_CPP}/Session.cpp
        ${MONGOOSE_CPP}/Sessions.cpp
        ${MONGOOSE_CPP}/StreamResponse.cpp
        ${MONGOOSE_CPP}/UploadFile.cpp
        ${MONGOOSE_CPP}/WebController.cpp
        ${MONGOOSE_CPP}/JsonResponse.cpp
        ${MONGOOSE_CPP}/JsonController.cpp
        ${MONGOOSE_CPP}/WebSocket.cpp
        ${MONGOOSE_CPP}/WebSockets.cpp)



include_directories(src)
include_directories(lib)
include_directories(lib/json)
include_directories(lib/mongoose)
include_directories(${LIBS_PATH})
include_directories("${MONGOOSE_CPP}")



add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${MONGOOSE_SOURCES} )
