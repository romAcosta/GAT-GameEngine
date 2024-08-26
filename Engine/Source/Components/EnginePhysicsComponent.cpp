#include "EnginePhysicsComponent.h"
#include "../Framework/Actor.h"


void EnginePhysicsComponent::Initialize()
{
}

void EnginePhysicsComponent::Update(float dt)
{
	velocity += acceleration * dt;
	owner->transform.position += velocity * dt;
	velocity *= 1 / (1 + damping * dt);

	acceleration = Vector2{ 0,0 };
}

void EnginePhysicsComponent::ApplyForce(const Vector2& force)
{
	this->acceleration += force / mass;
}

void EnginePhysicsComponent::SetPosition(const Vector2& position)
{
	owner->transform.position = position; 
}

void EnginePhysicsComponent::ApplyTorque(float angle)
{
	owner->transform.rotation += angle;
}



void EnginePhysicsComponent::Read(const json_t& value) {
	PhysicsComponent::Read(value);
}

void EnginePhysicsComponent::Write(json_t& value)
{

}