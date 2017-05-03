//
// Created by Nicolas Alvarez on 5/1/17.
//

#include "Song.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>


Song::Song(string songID, string songName, string file, string filePath ) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    ostringstream oss;
    std::stringstream date;
    date << ltm->tm_mday
         << "-"
         << 1 + ltm->tm_mon
         << "-"
         << 1900 + ltm->tm_year
         << "-"
         << 1 + ltm->tm_hour
         << ":"
         << 1 + ltm->tm_min
         << ":"
         << 1 + ltm->tm_sec;

    this->songName = date.str().append("_").append(songName);
    oss << filePath << "/" << this->songName;
    fstream aFile;
    aFile.open(oss.str().c_str(), fstream::out);
    aFile << file;
    aFile.close();

    this->file = file;
    this->songID = songID;
    this->filePath = filePath;
}

bool  Song::getSongFromDB() {
    if (this->songID == "")
        return false;
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    mongocxx::database db = client["TallerTest"];
    mongocxx::collection coll = db["collectionTest"];
    bsoncxx::oid myoid(this->songID.c_str());

    mongocxx::options::find opts{};
    mongocxx::stdx::optional<bsoncxx::document::value> maybe_result =
            coll.find_one(document{} << "_id" << myoid << finalize);
    if (maybe_result){
        string fileJson = bsoncxx::to_json(*maybe_result);
        return true;
    }
    return false;
}

string Song::storeSongInDB() {

    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    mongocxx::database db = client["songTest"];
    mongocxx::collection coll = db["collectionTest"];
    auto builder = bsoncxx::builder::stream::document{};

    bsoncxx::document::value doc_value = builder
            << "filePath" << filePath
            << "songName" << songName
            << bsoncxx::builder::stream::finalize;
    mongocxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value.view());
    return result->inserted_id().get_oid().value.to_string();


}

