add_executable(SongControllerTest AccountControllerTest.cpp ${MONGOOSE_SOURCES} mainTest.cpp)

target_link_libraries(SongControllerTest mongoose model controllers utils ${LIBS_NAMES})

add_test(NAME "SongControllerTest" COMMAND SongControllerTest)
