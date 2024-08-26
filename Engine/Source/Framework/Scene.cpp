#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include "../Core/json.h"
#include "../Core/Factory.h"
#include "../Components/CollisionComponent.h"
#include "../Core/EAssert.h"
#include "Transform.h"
#include <algorithm>
Scene::Scene(const Scene& other)
{
	ASSERT(false);
}

void Scene::Initialize()
{
	for (auto& actor : actors) {
		actor->Initialize();
	}
}

void Scene::Update(float dt)
{

	
	for (auto& actor : actors) {
		if (actor->active) {
			actor->Update(dt);
		}
	}
	


	

	actors.erase(
		std::remove_if(actors.begin(), actors.end(), [](auto& actor) { return actor->destroyed; }), actors.end()
	);

	//collision
	//for (auto& actor1 : actors) {
	//	CollisionComponent* collision1 = actor1->GetComponent<CollisionComponent>();
	//	if (!collision1) continue;

	//	for (auto& actor2 : actors) {
	//		//dont check with self
	//		if (actor1 == actor2) continue;

	//		CollisionComponent* collision2 = actor2->GetComponent<CollisionComponent>();
	//		if (!collision2) continue;

	//		if (collision1->CheckCollision(collision2)) {
	//			//std::cout << "Hit!\n";
	//			if (actor1->OnCollisionEnter) actor1->OnCollisionEnter(actor2.get());
	//			if (actor2->OnCollisionEnter) actor2->OnCollisionEnter(actor1.get());
	//		}
	//	}
	//}

}

void Scene::Draw(Renderer& renderer)
{
	
	for (auto& actor : actors) {
		actor->Draw(renderer);
	}
	
}

void Scene::AddActor(std::unique_ptr < Actor> actor, bool initialize)
{
	actor-> scene = this;
	if (initialize) actor->Initialize();
	actors.push_back(std::move(actor));
}

void Scene::Read(const json_t& value) {
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray()) {
		for (auto& actorValue : GET_DATA(value, actors).GetArray()) {
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);

			bool prototype = false;
			READ_DATA(actorValue, prototype);
			if (prototype) {
				std::string name = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
			else {
				AddActor(std::move(actor));
			}

		}
	}
}


void Scene::Write(json_t& value)
{
}