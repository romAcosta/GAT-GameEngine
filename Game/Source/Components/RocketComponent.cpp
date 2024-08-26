#include "RocketComponent.h"
#include "Engine.h"


void RocketComponent::Initialize()
{
}

void RocketComponent::Update(float dt)
{

	
	owner->GetComponent<PhysicsComponent>()->ApplyForce(owner->transform.Forward() * speed);

}

void RocketComponent::OnCollisionEnter(Actor* actor)
{
}

void RocketComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void RocketComponent::Write(json_t& value)
{
}