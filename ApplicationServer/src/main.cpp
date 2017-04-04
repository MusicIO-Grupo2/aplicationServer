#include <iostream>
#include <zconf.h>
#include "controllers/HelloWorldController.h"
#include <mongoose/Server.h>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using namespace std;
using namespace Mongoose;



int main() {
    HelloWorldController myController;
    Server server(8080);
    server.registerController(&myController);

    server.start();

    while (1) {
        sleep(10);
    }
}