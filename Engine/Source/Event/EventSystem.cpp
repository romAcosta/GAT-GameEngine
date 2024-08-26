#include "EventSystem.h"

void EventSystem::AddObserver(const id_t& id, Observer* observer, EventHandler eventHandler)
{
	Dispatcher dispatcher;
	dispatcher.observer = observer;
	dispatcher.eventHandler = eventHandler;

	m_dispatchers[id].push_back(dispatcher);
}

void EventSystem::RemoveObserver(Observer* observer)
{
	for (auto& element : m_dispatchers) 
	{
		auto dispatchers = element.second;
		dispatchers.erase(
			std::remove_if(dispatchers.begin(), dispatchers.end(), [observer](auto& dispatcher) { return dispatcher.observer == observer; }), dispatchers.end()
		);
		

	}
}

void EventSystem::Notify(const Event& event)
{
	auto iter = m_dispatchers.find(event.id);
	if (iter != m_dispatchers.end())
	{
		auto dispatchers = iter->second;
		for (auto& dispatcher : dispatchers) 
		{
			dispatcher.eventHandler(event);
		}
	}
}
