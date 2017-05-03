#include "controllers/HelloWorldController.h"
#include <mongoose/Server.h>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <spdlog/spdlog.h>
#include "utils/LoggerManager.h"
#include "controllers/SongController.h"
using namespace std;
using namespace Mongoose;

namespace spd = spdlog;

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main() {

    const int dir_err = system("mkdir -p tallerSongs");
    if (-1 == dir_err)
    {
        printf("Error creating directory!n");
        exit(1);
    }

    LoggerManager::Instance()->logInfo("Conectando a la base mongo...");
    std::cout << "Connecting to mongo..." << std::endl;

    mongocxx::instance instance{}; // This should be done only once.
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);

    mongocxx::database db = client["TallerTest"];



    HelloWorldController myController;
    SongController songController;

    Server server(8080);
    server.registerController(&myController);
    server.registerController(&songController);

    server.start();
    std::cout << "Server UP!" << std::endl;
    while (1) {
        sleep(10);
    }
}