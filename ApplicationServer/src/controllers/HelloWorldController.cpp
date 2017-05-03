//
// Created by Nicolas Alvarez on 3/29/17.
//

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include "HelloWorldController.h"
#include "../utils/LoggerManager.h"

using namespace Mongoose;

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

HelloWorldController::HelloWorldController() {

}

void HelloWorldController::hello(Request &request, StreamResponse &response) {
    LoggerManager::Instance()->logInfo("Service /hello");
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    mongocxx::database db = client["TallerTest2"];
    mongocxx::collection coll = db["users"];

    string username = htmlEntities(request.get("name", "... what is your name ?"));

    mongocxx::stdx::optional<bsoncxx::document::value> maybe_result =
            coll.find_one(document{} << "username" << username << finalize);

    if (maybe_result){
        response << "This is you: " << bsoncxx::to_json(*maybe_result) << endl;

    } else {
        response << "Hello " << username << ", you are not registered yet." << endl;
        auto builder = bsoncxx::builder::stream::document{};
        bsoncxx::document::value doc_value = builder
                << "name" << username
                << "username" << username
                << "lastName" << "Natalia"
                << bsoncxx::builder::stream::finalize;
        mongocxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value.view());

    }



};

void HelloWorldController::setup(){
    addRoute("GET", "/hello", HelloWorldController, hello);

}


