//
// Created by Nicolas Alvarez on 4/6/17.
//

#include "LoggerManager.h"
#include <stddef.h>

LoggerManager* LoggerManager::m_pInstance = NULL;


LoggerManager* LoggerManager::Instance() {
    if (!m_pInstance)
       m_pInstance = new LoggerManager;
    return m_pInstance;

}

LoggerManager::~LoggerManager() {
    spd::drop_all();
}

void LoggerManager::logWarning(string message) {
    auto async_file = spd::daily_logger_st(LOGGERNAME, "applicationServerLog");
    spd::get(LOGGERNAME)->warn(message);
    spd::drop_all();
}

void LoggerManager::logError(string message) {
    auto async_file = spd::daily_logger_st(LOGGERNAME, "applicationServerLog");
    spd::get(LOGGERNAME)->error(message);
    spd::drop_all();
}

void LoggerManager::logInfo(string message) {
    auto async_file = spd::daily_logger_st(LOGGERNAME, "applicationServerLog");
    spd::get(LOGGERNAME)->info(message);
    spd::drop_all();
}

