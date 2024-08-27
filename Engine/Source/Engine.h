#pragma once


// **Event**
#include "Event/EventSystem.h"

// **Input**
#include "Input/Input.h"

// **Physics**
#include "Physics/Physics.h"

// **Core**
#include "Core/ETime.h"
#include "Core/EFile.h"
#include "Core/json.h"
#include "Core/Factory.h"
#include "Core/EString.h"

// **Framework**
#include "Framework/Particle.h"
#include "Framework/Color.h"
#include "Framework/Model.h"
#include "Framework/Transform.h"
#include "Framework/Actor.h"
#include "Framework/Scene.h"

// **Math**
#include "Math/MathUtils.h"
#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/Rect.h"


// **Audio**
#include "Audio/Audio.h"

// **Renderer**
#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

// **Resources**
#include "Resources/ResourceManager.h"


// **Components**
#include "Components/RenderComponent.h"
#include "Components/Component.h"
#include "Components/TextComponent.h"
#include "Components/TextureComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/EnginePhysicsComponent.h"
#include "Components/CircleCollisionComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/AudioComponent.h"
#include "Components/TileMapComponent.h"
#include "Components/TextureAnimationComponent.h"



#include <SDL.h>
#include <SDL_ttf.h>


class Engine {

public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Physics& GetPhysics()   { return *m_physics; }

	Renderer& GetRenderer() { return *m_renderer; }
	Audio& GetAudio()       { return *m_audio; }
	Input& GetInput()       { return *m_input; }
	Time& GetTime()         { return *m_time; }

private:

	std::unique_ptr<Physics>  m_physics;
	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input>	  m_input;
	std::unique_ptr<Audio>	  m_audio;
	std::unique_ptr<Time>	  m_time;

};





