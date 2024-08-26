#include "Box2DPhysicsComponent.h"
#include "../Engine.h"

FACTORY_REGISTER(Box2DPhysicsComponent)

Box2DPhysicsComponent::Box2DPhysicsComponent(const Box2DPhysicsComponent& other)
{
	rigidBodyDef = other.rigidBodyDef;
	size = other.size;

	//if (other.m_rigidBody)
	//{
	//	m_rigidBody = std::make_unique<RigidBody>(*other.m_rigidBody.get());
	//}
}

void Box2DPhysicsComponent::Initialize()
{
	rigidBodyDef.actor = owner;
	if (size.x == 0 && size.y == 0)
	{
		auto textureComponent = owner->GetComponent<TextureComponent>();
		size = Vector2{ textureComponent->source.w,textureComponent->source.h };
	}
	m_rigidBody = std::make_unique<RigidBody>(owner->transform, size, rigidBodyDef, owner->scene->engine->GetPhysics());

}

void Box2DPhysicsComponent::Update(float dt)
{
	owner->transform.position = m_rigidBody->GetPosition();
	owner->transform.rotation = m_rigidBody->GetAngle();
	velocity = m_rigidBody->GetVelocity();
}

void Box2DPhysicsComponent::ApplyForce(const Vector2& force)
{
	m_rigidBody->ApplyForce(force);
}

void Box2DPhysicsComponent::ApplyTorque(float torque)
{
	m_rigidBody->ApplyTorque(torque);
}

void Box2DPhysicsComponent::SetPosition(const Vector2& position)
{
	m_rigidBody->SetTransform(position, m_rigidBody->GetAngle());
}

void Box2DPhysicsComponent::SetVelocity(const Vector2& velocity)
{
	m_rigidBody->SetVelocity(velocity);
}

void Box2DPhysicsComponent::Read(const json_t& value)
{
	READ_DATA_NAME(value, "gravityScale", rigidBodyDef.gravityScale);
	READ_DATA_NAME(value, "damping", rigidBodyDef.damping);
	READ_DATA_NAME(value, "angularDamping", rigidBodyDef.angularDamping);
	READ_DATA_NAME(value, "constrainAngle", rigidBodyDef.constrainAngle);
	READ_DATA_NAME(value, "isDynamic", rigidBodyDef.isDynamic);
	READ_DATA_NAME(value, "friction", rigidBodyDef.friction);
	READ_DATA_NAME(value, "restitution", rigidBodyDef.restitution);
	READ_DATA_NAME(value, "density", rigidBodyDef.density);
	READ_DATA_NAME(value, "isSensor", rigidBodyDef.isSensor);

	READ_DATA_STRUCT(value, gravityScale, rigidBodyDef);

	READ_DATA(value, size);
}

void Box2DPhysicsComponent::Write(json_t& value)
{
	//
}