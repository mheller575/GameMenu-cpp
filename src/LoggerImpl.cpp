
#include <functional>
#include <iostream>

#include "LoggerImpl.h"

namespace Menu
{
	ILogger::ILogger() {}

	ILogger::~ILogger() {}

	LoggerImpl::LoggerImpl()
		: _logWorker(std::bind(&LoggerImpl::LogWorker, this))
	{}

	LoggerImpl::~LoggerImpl() 
	{
		_shutDown = true;

		if (_logWorker.joinable())
		{
			_logWorker.join();
		}
	}

	void LoggerImpl::LogInformation(const std::string& message)
	{
		std::scoped_lock lock(_logListMutex);

		_logList.push_back(message);
	}

	void LoggerImpl::LogWorker()
	{
		std::vector<std::string> localLogs;

		while (!_shutDown)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(250));

			{
				std::scoped_lock lock(_logListMutex);

				if (_logList.empty())
				{
					continue;
				}

				for (const auto message : _logList)
				{
					localLogs.push_back(message);
				}

				_logList.clear();
			}
			
			for (const auto& message : localLogs)
			{
				std::cout << message << std::endl;
			}

			localLogs.clear();
		}
	}

	std::shared_ptr<ILogger> BuildLogger()
	{
		return std::make_shared<LoggerImpl>();
	}
}