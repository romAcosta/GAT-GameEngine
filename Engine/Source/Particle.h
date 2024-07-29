#pragma once
#include "Vector2.h"
#include "Renderer.h"
#include "Color.h"

struct Particle
{
	Vector2 position{ 0,0 };
	Vector2 velocity{ 0,0 };
	float lifespan = .05f;
	Color color{ 1,1,1 };

	Particle() = default;
	Particle(Vector2 position, Vector2 velocity) :
		position{ position }, 
		velocity{ velocity } 
	{}
	Particle(Vector2 position, Vector2 velocity, Color color, float ls) :
		lifespan{ls},
		position{ position },
		velocity{ velocity },
		color{ color }
	{}

	
	



	void Update(float dt);
	void Draw(Renderer& renderer);

};