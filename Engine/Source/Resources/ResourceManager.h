#pragma once
#include "Resource.h"
#include "../Engine.h"
#include "../Core/Singleton.h"
#include <map>
#include <iostream>

class ResourceManager : public Singleton<ResourceManager> {

public:
	template <typename T, typename ... TArgs>
	res_t<T> Get(const std::string& name, TArgs ... targs);
	friend class Singleton;

protected:
	ResourceManager() = default;

private:
	std::map<std::string, res_t<Resource>> m_resources;
};

template<typename T, typename ... TArgs>
inline res_t<T> ResourceManager::Get(const std::string& name, TArgs ... targs) {

	std::string lowerName = ToLower(name);

	if (m_resources.find(lowerName) != m_resources.end()) {

		//return resource
		return std::dynamic_pointer_cast<T>(m_resources[lowerName]);
	}

	//resource not found, create resource
	res_t<T> resource = std::make_shared<T>();
	if (!resource->Create(lowerName, targs...)) {
		std::cerr << "Could not create resource: " << name << std::endl;
		return res_t<T>();
	}

	m_resources[lowerName] = resource;

	return resource;
}