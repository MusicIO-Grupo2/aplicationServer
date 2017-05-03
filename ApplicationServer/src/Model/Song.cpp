//
// Created by Nicolas Alvarez on 5/1/17.
//

#include "Song.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <json.h>

Song::Song() {}

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

    this->songFileName = date.str().append("_").append(songName);
    oss << filePath << "/" << this->songFileName;
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
    mongocxx::database db = client["songTest"];
    mongocxx::collection coll = db["collectionTest"];
    bsoncxx::oid myoid(this->songID.c_str());

    mongocxx::options::find opts{};
    mongocxx::stdx::optional<bsoncxx::document::value> maybe_result =
            coll.find_one(document{} << "_id" << myoid << finalize);
    if (maybe_result){
        string fileJson = bsoncxx::to_json(*maybe_result);
        Json::Value root;
        Json::Reader reader;
        reader.parse( fileJson.c_str(), root );
        this->filePath = root.get("filePath","").asString();
        this->songFileName = root.get("songFileName","").asString();
        ostringstream oss;
        oss << filePath << "/" << songFileName;
        fstream aFile;
        aFile.open(oss.str().c_str(), fstream::out);
        this->file = "";
        if (aFile.is_open()){
            while (!aFile.eof()){
                char buffer [100];
                aFile >> buffer;
                this->file.append(buffer);
            }
        }


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
            << "songFileName" << songFileName
            << bsoncxx::builder::stream::finalize;
    mongocxx::stdx::optional<mongocxx::result::insert_one> result = coll.insert_one(doc_value.view());
    return result->inserted_id().get_oid().value.to_string();


}

string Song::getSongFileName() {
    return songFileName;
}

void Song::setSongID(string songID) {
    this->songID = songID;
}

string Song::getSongData() {
    return this->file;
}

