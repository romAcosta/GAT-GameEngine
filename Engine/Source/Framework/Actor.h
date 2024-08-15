#pragma once
#include "Transform.h"
#include <string>
#include "Model.h"
#include "Object.h"
#include "../Components/Component.h"
#include <memory>

class Scene;

class Renderer;

class Actor : public Object {




public:


	Actor() = default;
	
	Actor(const Transform& transform) : transform{ transform }{}

	CLASS_DECLARATION(Actor);
	
	

	//Actor(const Transform& transform, Model* model) : 
	//	m_transform{ transform },
	//	m_model{model}
	//	{}
	virtual void Initialize() override;
	virtual void Update(float dt);
	virtual void Draw( Renderer& renderer);

	void AddComponent(std::unique_ptr<Component> component);
	
	const std::string& GetTag() { return tag; }

	Transform& GetTransform() { return transform; }
	void SetTransform(const Transform& transform) { this->transform = transform; }
	virtual float GetRadius() { return 0; }

	template <typename T>
	T* GetComponent();
	template <typename T>
	std::vector<T*> GetComponents();
	//virtual void OnCollision(Actor* actor) = 0;
	

	friend class Scene;
	friend struct Actors;

public:
	std::string tag;
	float lifespan = -1;
	bool destroyed = false;
	Transform transform;
	Scene* scene{ nullptr };
protected:
	
	
	std::vector<std::unique_ptr<Component>> components;
};


template<typename T>
inline T* Actor::GetComponent()
{
	for (auto& component : components) {
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}
	return nullptr;
}

template<typename T>
inline std::vector<T*> Actor::GetComponents()
{
	std::vector<T*> results;
	for (auto& component : components) {
		T* result = dynamic_cast<T*>(component.get());
		if (result) results.push_back(result);
	}
	return results;
}
