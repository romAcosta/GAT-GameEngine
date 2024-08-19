#include "CircleCollisionComponent.h"
#include "../Framework/Actor.h"
void CircleCollisionComponent::Read(const json_t& value)
{
    READ_DATA(value, radius);
}

void CircleCollisionComponent::Write(json_t& value)
{
}

void CircleCollisionComponent::Update(float dt)
{
}

bool CircleCollisionComponent::CheckCollision(const CollisionComponent const* collision)
{


    float r1 = radius;
    float r2 = (dynamic_cast<const CircleCollisionComponent*>(collision))->radius;
    float distance = owner->transform.position.Distance(collision->owner->transform.position);


    return (distance <= (r1 + r2));
}

void CircleCollisionComponent::Initialize()
{
}
