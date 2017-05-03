//
// Created by Nicolas Alvarez on 4/24/17.
//

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include "../utils/LoggerManager.h"
#include "SongController.h"
#include "../Model/Song.h"

using namespace Mongoose;

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

SongController::SongController() {}

void SongController::returnSong(Request &request, JsonResponse &response) {
    string songID = htmlEntities(request.get("songID", ""));
    Song *possibleSong = new Song(songID,"","","");
    response["success"] = possibleSong->getSongFromDB();



}

void SongController::uploadSong(Request &request, JsonResponse &response) {

    std::cout << "POST /song" << std::endl;
    string requestBody = request.getPostBody();
    request.handleUploads();
    std::vector<Mongoose::UploadFile>::iterator it = request.uploadFiles.begin();

    Song* aSong = new Song("",it->getName(),it->getData(),"tallerSongs");
    response["songName"] = it->getName();
    response["songID"] = aSong->storeSongInDB();

}

void SongController::setup() {

    addRouteResponse("GET", "/song", SongController, returnSong,JsonResponse);
    addRouteResponse("POST", "/song", SongController, uploadSong,JsonResponse);


}
