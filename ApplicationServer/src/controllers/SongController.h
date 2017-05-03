//
// Created by Nicolas Alvarez on 4/24/17.
//

#ifndef APPLICATIONSERVER_SONGCONTROLLER_H
#define APPLICATIONSERVER_SONGCONTROLLER_H
#include <mongoose/WebController.h>
#include <mongoose/JsonController.h>
#include <mongoose/JsonResponse.h>


using namespace Mongoose;


class SongController : public JsonController {

public:
    SongController();
    void setup();
    void returnSong(Request &request, JsonResponse &response);
    void uploadSong(Request &request, JsonResponse &response);


};


#endif //APPLICATIONSERVER_SONGCONTROLLER_H
