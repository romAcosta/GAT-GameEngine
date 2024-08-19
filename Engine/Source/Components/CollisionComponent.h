#pragma once

#include "Component.h"

class CollisionComponent : public Component
{
public:
	virtual bool CheckCollision(const CollisionComponent const* collision) = 0;

	




};