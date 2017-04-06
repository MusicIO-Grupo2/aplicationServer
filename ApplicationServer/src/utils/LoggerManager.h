//
// Created by Nicolas Alvarez on 4/6/17.
//

#ifndef APPLICATIONSERVER_LOGGERMANAGER_H
#define APPLICATIONSERVER_LOGGERMANAGER_H

#include <spdlog/spdlog.h>
namespace spd = spdlog;
using  namespace std;

class LoggerManager {
    public:
        static LoggerManager* Instance();
        void logError(string message);
        void logWarning(string message);
        void logInfo(string message);

    virtual ~LoggerManager();

private:
    const string LOGGERNAME = "Application Server";
    LoggerManager(){
    };
    LoggerManager(LoggerManager const&){};
        static LoggerManager* m_pInstance;

};


#endif //APPLICATIONSERVER_LOGGERMANAGER_H
