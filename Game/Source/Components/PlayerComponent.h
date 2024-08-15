#pragma once
#include "Components/Component.h"

class PlayerComponent : public Component {
public:

	CLASS_DECLARATION(PlayerComponent)
	// Inherited via Component
	void Initialize() override;

	void Update(float dt) override;

public:
	float speed = 0;
};