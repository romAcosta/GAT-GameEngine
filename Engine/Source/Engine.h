#pragma once

#include "Renderer/Renderer.h"
#include "Math/Vector2.h"
#include "Input/Input.h"
#include "Framework/Particle.h"
#include "Math/Random.h"
#include "Core/ETime.h"
#include "Framework/Color.h"
#include "Math/MathUtils.h"
#include "Framework/Model.h"
#include "Framework/Transform.h"
#include "Audio/Audio.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include <SDL.h>
#include <SDL_ttf.h>


class Engine {

public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();


	Renderer& GetRenderer() { return *m_renderer; }
	Audio& GetAudio() { return *m_audio; }
	Input& GetInput() { return *m_input; }
	Time& GetTime() { return *m_time; }

private:

	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input>	  m_input;
	std::unique_ptr<Audio>	  m_audio;
	std::unique_ptr<Time>	  m_time;

};





