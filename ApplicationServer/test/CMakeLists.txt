
add_executable(SongControllerTest main.cpp SongControllerTest.cpp SongControllerTest.h)

set(LIBS_NAMES cppunit)
foreach (LIB ${LIBS_NAMES})
    find_library(LIB{LIB} NAMES ${LIB})
    if (LIB{LIB}) #False si es 0, OFF, NO, FALSE, N, IGNORE, NOTFOUND, vacio, o si termina en "-NOTFOUND". Caso contrario es TRUE.
        message(STATUS "Lib |${LIB}| found!")
    else (LIB${LIB})
        message(STATUS "|${LIB}| lib not found.")
    endif (LIB{LIB})
endforeach (LIB ${LIBS_NAMES})

set(MONGOOSE_CPP "../src/lib/mongoose")


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
        ${MONGOOSE_CPP}/WebController.h
        ${MONGOOSE_CPP}/WebSocket.cpp
        ${MONGOOSE_CPP}/WebSockets.cpp)

include_directories(${LIBs_PATH}/spdlog)
link_directories(${LIBs_PATH}/spdlog)

include_directories(../src)
include_directories(../src/lib)
include_directories(../src/lib/dist/json)
include_directories(../src/lib/dist)
include_directories(../src/lib/mongoose)
include_directories(${LIBS_PATH})

include_directories(/usr/local/include/mongocxx/v_noabi/)
include_directories(/usr/local/include/bsoncxx/v_noabi/)
include_directories(/usr/local/include/libmongoc-1.0)
include_directories(/usr/local/include/libbson-1.0)

target_link_libraries(SongControllerTest  ${LIBS_NAMES} cppunit ${MONGOOSE_SOURCES})

