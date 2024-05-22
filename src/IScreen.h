#pragma once

namespace Menu
{
	class IScreen
	{
	public:
		virtual ~IScreen();

		virtual void Open() = 0;

		virtual void Close() = 0;

	protected:
		IScreen();

	private:
		IScreen(const IScreen&) = delete;
		IScreen& operator=(const IScreen&) = delete;
	};
}
