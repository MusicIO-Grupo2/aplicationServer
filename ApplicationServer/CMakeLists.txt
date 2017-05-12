project(ApplicationServer)
set(PROJECT_NAME "ApplicationServer")
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


cmake_minimum_required(VERSION 2.8)

set(ROOT_PATH "${${PROJECT_NAME}_SOURCE_DIR}")


set(SRC_PATH "${ROOT_PATH}/src")

set(SOURCE_FILES src/main.cpp src/controllers/HelloWorldController.cpp src/controllers/HelloWorldController.h src/utils/LoggerManager.cpp src/utils/LoggerManager.h src/controllers/SongController.cpp src/controllers/SongController.h src/Model/Song.cpp src/Model/Song.h src/utils/MongoManager.cpp src/utils/MongoManager.h src/utils/base64.cpp src/utils/base64.h test/SongControllerTest.cpp test/SongControllerTest.h test/mainTest.cpp)

message(STATUS "${CMAKE_LIBRARY_PATH}")

set(LIBS_PATH "${ROOT_PATH}/lib")
set(LIBS_NAMES mongoose json jsoncpp mongocxx bsoncxx cppunit libmongocxx libbsoncxx spdlog)
foreach (LIB ${LIBS_NAMES})
    find_library(LIB{LIB} NAMES ${LIB})
    if (LIB{LIB}) #False si es 0, OFF, NO, FALSE, N, IGNORE, NOTFOUND, vacio, o si termina en "-NOTFOUND". Caso contrario es TRUE.
        message(STATUS "Lib |${LIB}| found!")
    else (LIB${LIB})
        message(STATUS "|${LIB}| lib not found.")
    endif (LIB{LIB})
endforeach (LIB ${LIBS_NAMES})

set(JSON_CPP "${LIBS_PATH}/dist")
#set(JSON_SOURCES
#        ${JSON_CPP}/json/json.h
#        ${JSON_CPP}/json/json-forwads.h
#        ${JSON_CPP}/jsoncpp.cpp)


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
        ${MONGOOSE_CPP}/JsonResponse.cpp
        ${MONGOOSE_CPP}/JsonController.cpp
        ${MONGOOSE_CPP}/UploadFile.cpp
        ${MONGOOSE_CPP}/WebController.cpp
        ${MONGOOSE_CPP}/WebSocket.cpp
        ${MONGOOSE_CPP}/WebSockets.cpp src/utils/LoggerManager.cpp src/utils/LoggerManager.h src/controllers/SongController.cpp src/controllers/SongController.h src/Model/Song.cpp src/Model/Song.h src/utils/MongoManager.cpp src/utils/MongoManager.h src/utils/base64.cpp src/utils/base64.h test/SongControllerTest.cpp test/SongControllerTest.h test/mainTest.cpp)


set(JSON_SOURCES
        ${LIBS_PATH}/dist/json/json.h
        ${LIBS_PATH}/dist/jsoncpp.cpp
        ${LIBS_PATH}/dist/json/json-forwards.h
        src/utils/LoggerManager.cpp src/utils/LoggerManager.h src/controllers/SongController.cpp src/controllers/SongController.h src/Model/Song.cpp src/Model/Song.h src/utils/MongoManager.cpp src/utils/MongoManager.h src/utils/base64.cpp src/utils/base64.h test/SongControllerTest.cpp test/SongControllerTest.h test/mainTest.cpp)

include_directories(/usr/local/include/mongocxx/v_noabi/)
include_directories(/usr/local/include/bsoncxx/v_noabi/)
include_directories(/usr/local/include/libmongoc-1.0)
include_directories(/usr/local/include/libbson-1.0)


include_directories(${LIBs_PATH}/spdlog)
link_directories(${LIBs_PATH}/spdlog)

include_directories(src)
include_directories(lib)
include_directories(lib/dist/json)
include_directories(lib/dist)
include_directories(lib/mongoose)
include_directories(${LIBS_PATH})
include_directories("${MONGOOSE_CPP}")
include_directories("${JSON_CPP}")

message(STATUS "FIN!")


add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${MONGOOSE_SOURCES} ${JSON_SOURCES} src/utils/LoggerManager.cpp src/utils/LoggerManager.h src/controllers/SongController.cpp src/controllers/SongController.h src/Model/Song.cpp src/Model/Song.h src/utils/MongoManager.cpp src/utils/MongoManager.h src/utils/base64.cpp src/utils/base64.h test/SongControllerTest.cpp test/SongControllerTest.h test/mainTest.cpp)
target_link_libraries(${PROJECT_NAME} mongocxx bsoncxx cppunit)
target_link_libraries(${PROJECT_NAME} ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${LIBBSONCXX_LIBRARIES})
