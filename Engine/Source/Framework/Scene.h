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

	CLASS_DECLARATION(Scene);

	void Update(float dt);
	void Draw( Renderer& renderer);

	void AddActor(std::unique_ptr < Actor> actor);
	
	
	void Initialize() override;
	

	template<typename T>
	T* GetActor();

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
