#include "Engine.h"
#include <crtdbg.h>


bool Engine::Initialize()
{


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	m_renderer =std::make_unique<Renderer>();
	m_input = std::make_unique<Input>();
	m_audio = std::make_unique<Audio>();

	m_time = std::make_unique<Time>();

	(*m_renderer).Initialize();
	m_renderer->CreateWindow("Game Engine", 800, 600);

	(*m_input).Initialize();

	(*m_audio).Initialize();

	return true;
}

void Engine::Shutdown()
{
	m_renderer->Shutdown();
	m_input->Shutdown();
	m_audio->Shutdown();

	_CrtMemDumpAllObjectsSince(NULL);
}

void Engine::Update()
{

	m_input->Update();
	m_audio->Update();
	m_time->Tick();


}
