//
// Created by Nicolas Alvarez on 5/3/17.
//

#include "SongControllerTest.h"
#include "../src/controllers/SongController.h"
#include <bsoncxx/json.hpp>
#include <mongoose/Server.h>
#include <json.h>

using namespace CPPUNIT_NS;
using namespace Mongoose;
using namespace Json;

CPPUNIT_TEST_SUITE_REGISTRATION(SongControllerTest);


SongControllerTest::SongControllerTest() {}

void SongControllerTest::runTest() {

}

Request buildBasicRequest(string method, string queryString)  {
    mg_connection connection;
    connection.request_method = method.c_str();
    connection.num_headers = 0;
    char content[] = "mock";
    connection.content = content;
    connection.content_len = 4;
    connection.uri = "http://localhost:8080/song";

    connection.query_string = queryString.c_str();

    Request request(&connection);
    return request;
}

void SongControllerTest::testUploadSong() {

//    Server server(8080);
//
//
//    SongController *songController = new SongController;
//
//    server.registerController(songController);
//
//    server.start();
    Request request = buildBasicRequest("POST", "");
//
//    Response *response =  server.handleRequest(request);
//
//    songController->setSessions(new Sessions);
//    songController->setup();
//
//    RequestHandler<SongController, JsonResponse> requestHandler(songController, &SongController::uploadSong);

   // Value value = response->get("success", "");

    SongController * songController = new SongController;
    JsonResponse *response = new JsonResponse;
    songController->uploadSong(request,*response);

    bool success = response->get("success", true).asBool();
    string errorMessage = response->get("error", true).asString();
    CPPUNIT_ASSERT(success == false);
    CPPUNIT_ASSERT(errorMessage == "No se encontro archivo");



}
