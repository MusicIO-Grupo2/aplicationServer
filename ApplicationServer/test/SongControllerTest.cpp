//
// Created by Nicolas Alvarez on 5/3/17.
//

#include "SongControllerTest.h"
#include <mongoose/Request.h>
#include <json.h>

using namespace CPPUNIT_NS;
using namespace Mongoose;

void SongControllerTest::runTest() {

}

//Request buildBasicRequest(string method, string queryString) const {
//    mg_connection connection;
//    //Only mock data, method it´s not important
//    connection.request_method = method.c_str();
//    connection.num_headers = 0;
//    char content[] = "mock";
//    connection.content = content;
//    connection.content_len = 4;
//    connection.uri = "mock";
//
//    connection.query_string = queryString.c_str();
//
//    Request request(&connection);
//    return request;
//}
//
//void SongControllerTest::testUploadSong() {
//
//    Request request = buildBasicRequest("POST", "");
//
//}
