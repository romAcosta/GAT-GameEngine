#include "Actor.h"
#include "Model.h"


void Actor::Update(float dt)
{	
	if (m_lifespan != -1) {
		m_lifespan -= dt;
		if (m_lifespan <= 0) {
			m_destroyed = true;
		}
	}

	m_transform.position += (m_velocity * dt );
	
}

void Actor::Draw(Renderer& renderer)
{
	

	if (m_model) {

		m_model->Draw(renderer, m_transform);


	}



}
