//
// Created by Nicolas Alvarez on 5/1/17.
//

#ifndef APPLICATIONSERVER_MONGOMANAGER_H
#define APPLICATIONSERVER_MONGOMANAGER_H

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>
using namespace std;
using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

class MongoManager {
public:
    MongoManager();

    mongocxx::database getMongoDB();
    mongocxx::collection getCollection(string collectionName);
private:
};


#endif //APPLICATIONSERVER_MONGOMANAGER_H
