#include "PlayerComponent.h"
#include "Engine.h"


void PlayerComponent::Initialize()
{
}

float firespeed = 0;
void PlayerComponent::Update(float dt)
{
	Vector2 direction{ 0,0 };
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) { direction.x = 1; }
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) { direction.x = -1; }
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) { direction.y = 1; }
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) { direction.y = -1; }

	
	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed);

	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE)  && firespeed <= 0) {
		auto rocket = Factory::Instance().Create<Actor>("rocket");
		rocket->transform.position = owner->transform.position;
		rocket->transform.rotation = owner->transform.rotation;
		owner->scene->AddActor(std::move(rocket), true);
		firespeed = 1;
	}
	firespeed -= dt;
}

void PlayerComponent::OnCollisionEnter(Actor* actor)
{
	EVENT_NOTIFY(PlayerDead);
}


void PlayerComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{
}