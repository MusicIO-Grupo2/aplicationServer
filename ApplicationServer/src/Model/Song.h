//
// Created by Nicolas Alvarez on 5/1/17.
//

#ifndef APPLICATIONSERVER_SONG_H
#define APPLICATIONSERVER_SONG_H

#include "../utils/MongoManager.h"

using namespace std;

class Song {

public:
    Song();
    Song(string songID, string songName, string file, string filePath);
    bool  getSongFromDB();
    string storeSongInDB();
    string getSongFileName();
    string getSongData();
    void setSongID(string songID);

private:
    string songID;
    string songFileName;
    string file;
    string filePath;
};


#endif //APPLICATIONSERVER_SONG_H
