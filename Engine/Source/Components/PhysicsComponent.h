#pragma once
#include "Component.h"

class PhysicsComponent : public Component
{

public:
	CLASS_DECLARATION(PhysicsComponent);

	virtual void ApplyForce(const Vector2& force)	  = 0;
	virtual void ApplyTorque(float angle)			  = 0;
	virtual void SetPosition(const Vector2& position) = 0;
	virtual void SetVelocity(const Vector2& velocity) = 0;

public:
	Vector2 velocity{ 0,0 };
	Vector2 acceleration{ 0,0 };
	float mass = 1;
	float damping = 0;

};