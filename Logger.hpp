/*
*/

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <memory>
#include <fstream>

enum class LogLevel {
	NONE  = 0,
    FATAL = 1,
	ERROR = 2,
	WARN  = 3,
	INFO  = 4,
	DEBUG = 5
};

enum class LogOutput {
	CONSOLE,
	FILE
};

/**
* Logger Class Used to Output Details of Current Application Flow
*/
class Logger {
public:
	static std::shared_ptr<Logger> GetInstance();

	void SetLogPreferences(std::string logFileName,
						   LogLevel level,
						   LogOutput output);

	void Log(std::string codeFile, int codeLine, LogLevel messageLevel, std::string message);
	void LogVprintf(std::string codeFile, int codeLine, LogLevel messageLevel, char *fmt, ...);
    void LogVMsg(const char *fmt, ...);

	LogOutput GetLogOutput(const std::string& logOutput);
	LogLevel GetLogLevel(const std::string& logLevel);

private:
	LogLevel logLevel;
	LogOutput logOutput;
	std::ofstream logFile;

	static std::shared_ptr<Logger> loggerInstance;

	void LogMessage(const std::string& message);

};




/*
// example instance
    #include "Logger.hpp"

    auto logger = Logger::GetInstance();
    
    auto logLevelStr = "ERROR"; // or WARN, DEBUG, INFO
    auto logLevel = logger->GetLogLevel(logLevelStr);

    auto logFile = "/home/user/logs/applog.txt";

    auto logOutputStr = "FILE"; // or CONSOLE
    auto logOutput = logger->GetLogOutput(logOutputStr);

    // One time log preferences
    logger->SetLogPreferences(logFile, logLevel, logOutput);
 

auto logger = Logger:GetInstance();


#define LOG_DEBUG(args ...) if (DEBUG) logger->Log(__FILE__, __LINE__, "Wrong Input Type Valid Values: A Z", LogLevel::ERROR);


*/


#define LOG(fmt, args...) Logger::GetInstance()->LogVMsg(fmt, ##args)
#define LOG_DEBUG(args...) Logger::GetInstance()->LogVprintf(__FILE__, __LINE__, LogLevel::DEBUG, ##args )
#define LOG_INFO (args...) Logger::GetInstance()->LogVprintf(__FILE__, __LINE__, LogLevel::INFO, ##args)
#define LOG_ERROR(args...) Logger::GetInstance()->LogVprintf(__FILE__, __LINE__, LogLevel::ERROR, ##args)
#define LOG_WARN (args...) Logger::GetInstance()->LogVprintf(__FILE__, __LINE__, LogLevel::WARN, ##args)
#define LOG_FATAL(args...) Logger::GetInstance()->LogVprintf(__FILE__, __LINE__, LogLevel::FATAL, ##args)


#endif