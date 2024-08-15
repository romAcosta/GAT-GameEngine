#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include "../Core/json.h"
#include "../Core/Factory.h"
#include "Transform.h"
#include <algorithm>

void Scene::Initialize()
{
	for (auto& actor : actors) {
		actor->Initialize();
	}
}

void Scene::Update(float dt)
{

	
		for (auto& actor : actors) {
			actor->Update(dt);
		}
	


	

	/*m_actors.erase(
		std::remove_if(m_actors.begin(), m_actors.end(), [](auto& actor) { return actor->m_destroyed; }), m_actors.end()
	);*/

	//collision

	/*for (auto& actor1 : m_actors) {
		for (auto& actor2 : m_actors) {
			if (actor1 == actor2) continue;
			
			Vector2 direction = actor1->GetTransform().position - actor2->GetTransform().position;
			float distance = direction.Length();

			float radius = actor1->GetRadius() + actor2->GetRadius();

			if (distance <= radius) {
				actor1->OnCollision(actor2.get());
				actor2->OnCollision(actor1.get());
			}
		}
	}*/

}

void Scene::Draw(Renderer& renderer)
{
	
	for (auto& actor : actors) {
		actor->Draw(renderer);
	}
	
}

void Scene::AddActor(std::unique_ptr < Actor> actor)
{
	actor-> scene = this;
	
	actors.push_back(std::move(actor));
}

void Scene::Read(const json_t& value) {
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray()) {
		for (auto& actorValue : GET_DATA(value, actors).GetArray()) {
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypeName());
			actor->Read(actorValue);
			AddActor(std::move(actor));
		}
	}
}

void Scene::Write(json_t& value)
{
}