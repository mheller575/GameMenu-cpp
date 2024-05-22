#pragma once

#include <memory>
#include <string>

namespace Menu
{
	class ILogger
	{
	public:
		virtual ~ILogger();

		virtual void LogInformation(const std::string& message) = 0;

	protected:
		ILogger();
	};

	std::shared_ptr<ILogger> BuildLogger();
}