//
// Created by Nicolas Alvarez on 3/29/17.
//

#include "HelloWorldController.h"
using namespace Mongoose;

HelloWorldController::HelloWorldController() {

}

void HelloWorldController::hello(Request &request, StreamResponse &response) {

    response << "Hello Nico" << endl;

};

void HelloWorldController::setup(){
    addRoute("GET", "/hello", HelloWorldController, hello);

}


