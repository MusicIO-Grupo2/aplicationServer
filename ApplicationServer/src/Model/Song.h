//
// Created by Nicolas Alvarez on 5/1/17.
//

#ifndef APPLICATIONSERVER_SONG_H
#define APPLICATIONSERVER_SONG_H

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

using namespace std;

class Song {

public:
    Song();
    Song(string songID, string songName, string file, string filePath);
    bool  getSongFromDB();
    string storeSongInDB();
    string getSongFileName();
    string getSongData();
    string getFilePath();
    void setSongID(string songID);

private:
    string songID;
    string songFileName;
    string file;
    string filePath;
};


#endif //APPLICATIONSERVER_SONG_H
