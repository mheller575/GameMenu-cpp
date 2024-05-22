#pragma once

#include <functional>
#include <mutex>
#include <unordered_map>

namespace Menu
{
	class UnsubscribeHandler
	{
	public:
		UnsubscribeHandler(const std::function<void()>& unsubscribe);
		~UnsubscribeHandler();

		void Unsubscribe();

	private:
		std::function<void()> unsubscribe_;
	};

	class ISubscriptionManager
	{
	public:
		virtual ~ISubscriptionManager();

		virtual UnsubscribeHandler Subscribe(const std::function<void()>& callback) = 0;
		virtual void CallCallbacks() const = 0;

	protected:
		ISubscriptionManager();

	private:
		ISubscriptionManager(const ISubscriptionManager&) = delete;
		ISubscriptionManager& operator=(const ISubscriptionManager&) = delete;
	};

	class SubscriptionManager : public ISubscriptionManager
	{
	public:
		SubscriptionManager();
		virtual ~SubscriptionManager();

		UnsubscribeHandler Subscribe(const std::function<void()>& callback) override;
		virtual void CallCallbacks() const override;

	private:
		void Unsubscribe(const std::int32_t& subscriptionID);

		mutable std::mutex callbacksMutex_;
		std::unordered_map<std::int32_t, std::function<void()>> callbacks_;

		SubscriptionManager(const SubscriptionManager&) = delete;
		SubscriptionManager& operator=(const SubscriptionManager&) = delete;
	};

	std::shared_ptr<ISubscriptionManager> BuildSubscriptionManager();
}
