#pragma once

#include <mutex>
#include <thread>
#include <vector>

#include "ILogger.h"

namespace Menu
{
	class LoggerImpl : public ILogger
	{
	public:
		LoggerImpl();
		virtual ~LoggerImpl() override;

		virtual void LogInformation(const std::string& message) override;

	private:
		void LogWorker();

		std::mutex _logListMutex;
		std::vector<std::string> _logList;
		std::thread _logWorker;

		bool _shutDown = false;
	};
}