#include "Particle.h"

void Particle::Update(float dt)
{
	if (lifespan != 0) {
		position = position + (velocity * dt);
		lifespan -= dt;
	}
	
}

void Particle::Draw(Renderer& renderer)
{
	renderer.SetColor(Color::ToInt(color.r), Color::ToInt(color.g), Color::ToInt(color.b), Color::ToInt(color.a));
	renderer.DrawRect(position.x, position.y, 1.0f, 2.0f);

}
