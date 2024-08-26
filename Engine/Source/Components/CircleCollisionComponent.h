#pragma once
#include "CollisionComponent.h"
class CircleCollisionComponent : public CollisionComponent

{
public:
	CLASS_DECLARATION(CircleCollisionComponent);
	CLASS_PROTOTYPE(CircleCollisionComponent);
	



public:

	float radius = 0.0f;


	// Inherited via CollisionComponent
	void Update(float dt) override;

	bool CheckCollision(const CollisionComponent* collision) override;


	// Inherited via CollisionComponent
	void Initialize() override;

};