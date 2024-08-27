#pragma once
#include "Object.h"
#include <memory>
#include <list>

class Renderer;
class Actor;
class Engine;


class Scene : public Object
{
public:
	Scene() = default;
	Scene(Engine* engine) {
		this->engine = engine;
	}

	Scene(const Scene& other);

	CLASS_DECLARATION(Scene);
	CLASS_PROTOTYPE(Scene);

	void Update(float dt);
	void Draw( Renderer& renderer);

	void AddActor(std::unique_ptr < Actor> actor, bool initialize = false);
	void RemoveAll();
	
	void Initialize() override;
	

	template<typename T> T* GetActor();
	template<typename T> T* GetActor(const std::string& name);
public:
	Engine* engine{ nullptr };

protected:

	std::list<std::unique_ptr<Actor>> actors;

};

template<typename T>
T* Scene::GetActor() 
{

	for (Actor* actor : actors) {
		T* result = dynamic_cast<T*> (actor);
		if (result) {return result;}
	}



	return nullptr;


}

template<typename T>
inline T* Scene::GetActor(const std::string& name)
{
	for (Actor* actor : actors) {
		T* result = dynamic_cast<T*> (actor);
		if (result  && IsEqualIgnoreCase(result->name , name)) { return result; }
	}
	return nullptr;
}
