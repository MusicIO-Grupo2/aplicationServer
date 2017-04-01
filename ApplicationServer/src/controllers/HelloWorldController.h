//
// Created by Nicolas Alvarez on 3/29/17.
//

#ifndef APPLICATIONSERVER_HELLOWORLDCONTROLLER_H
#define APPLICATIONSERVER_HELLOWORLDCONTROLLER_H

#include "../../lib/mongoose/WebController.h"

using namespace Mongoose;

class HelloWorldController : public WebController {
public:
    HelloWorldController();
    void setup();
    void hello(Request &request, StreamResponse &response);
};


#endif //APPLICATIONSERVER_HELLOWORLDCONTROLLER_H
