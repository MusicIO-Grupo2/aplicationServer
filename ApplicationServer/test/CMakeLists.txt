add_executable(SongControllerTest ${MONGOOSE_SOURCES} main.cpp)

target_link_libraries(SongControllerTest mongoose model controllers utils ${LIBS_NAMES})

add_test(NAME "SongControllerTest" COMMAND SongControllerTest)
