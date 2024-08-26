#pragma once
#include"Renderer/Renderer.h"
#include "Framework/Scene.h"
#include "Engine.h"

#include <memory>
class Game : public Observer{
public:

	Game(class Engine* engine) : m_engine{engine}{}

	void Update();
	void Initialize();
	void Shutdown();
	void Draw(Renderer& renderer);

	void OnPlayerDead(const Event& event);

	std::unique_ptr<Scene> scene;
	Engine* m_engine;
};