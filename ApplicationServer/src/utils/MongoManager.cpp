//
// Created by Nicolas Alvarez on 5/1/17.
//

#include "MongoManager.h"



mongocxx::database MongoManager::getMongoDB() {
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    return client["songTest"];
}

mongocxx::collection MongoManager::getCollection(string collectionName) {
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    mongocxx::database db = client["songTest"];
    return db[collectionName];
}

MongoManager::MongoManager() {}
