
#include <limits>
#include <random>

#include "RandomNumberGenerator.h"
#include "SubscriptionManager.h"

namespace Menu
{
	ISubscriptionManager::~ISubscriptionManager() {}

	ISubscriptionManager::ISubscriptionManager() {}

	SubscriptionManager::SubscriptionManager() {}

	SubscriptionManager::~SubscriptionManager() {}

	UnsubscribeHandler SubscriptionManager::Subscribe(const std::function<void()>& callback)
	{
		std::scoped_lock scopedLock(callbacksMutex_);

		const auto subscriptionID = GetRandomNumber(std::numeric_limits<std::int32_t>::min(), std::numeric_limits<std::int32_t>::max());

		callbacks_.insert(std::make_pair(subscriptionID, callback));

		const auto unsubscribeFunc = std::bind(&SubscriptionManager::Unsubscribe, this, subscriptionID);
		UnsubscribeHandler handler(unsubscribeFunc);

		return handler;
	}

	void SubscriptionManager::Unsubscribe(const std::int32_t& subscriptionID)
	{
		std::scoped_lock scopedLock(callbacksMutex_);

		if (callbacks_.contains(subscriptionID))
		{
			callbacks_.erase(subscriptionID);
		}
	}

	void SubscriptionManager::CallCallbacks() const
	{
		std::scoped_lock scopedLock(callbacksMutex_);

		for (const auto& callbackRecord : callbacks_)
		{
			callbackRecord.second();
		}
	}

	UnsubscribeHandler::UnsubscribeHandler(const std::function<void()>& unsubscribe)
	{
		unsubscribe_ = unsubscribe;
	}

	UnsubscribeHandler::~UnsubscribeHandler()
	{
		Unsubscribe();
	}

	void UnsubscribeHandler::Unsubscribe()
	{
		if (unsubscribe_)
		{
			unsubscribe_();
			unsubscribe_ = nullptr;
		}
	}

	std::shared_ptr<ISubscriptionManager> BuildSubscriptionManager()
	{
		return std::make_shared<SubscriptionManager>();
	}
}
