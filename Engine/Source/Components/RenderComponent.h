#pragma once
#include "Component.h"
#include "../Framework/Color.h"

class RenderComponent : public Component 
{
public:
	virtual void Draw(class Renderer& renderer) = 0;
};