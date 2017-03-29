#include <iostream>
#include <signal.h>
#include "controllers/HelloWorldController.h"
#include "../lib/mongoose/Server.h"
#include "../lib/mongoose/WebController.h"

using namespace std;
using namespace Mongoose;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}