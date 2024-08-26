#pragma once
#include "PhysicsComponent.h"
#include"../Framework/Actor.h"

class EnginePhysicsComponent : public PhysicsComponent {
	
public:
	CLASS_DECLARATION(EnginePhysicsComponent);
	CLASS_PROTOTYPE(EnginePhysicsComponent);

	void Initialize() override;
	void Update(float dt) override;
	void ApplyForce(const Vector2& force) override;
	
	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }



	// Inherited via PhysicsComponent
	void ApplyTorque(float angle) override;

};