#include "MyGame.h"
#include "Engine.h"
#include "Components/PlayerComponent.h"
#include "Components/RocketComponent.h"

void Game::Update()
{
	scene->Update(m_engine->GetTime().GetDeltaTime());
}

void Game::Initialize()
{
	
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);
	
	scene = std::make_unique<Scene>(m_engine);
	std::string sceneNames[] = {  "Scenes/tilemap.json","Scenes/scene.json" };
	for (std::string name : sceneNames) {
		rapidjson::Document document;
		Json::Load(name, document);
		scene->Read(document);
	}
	scene->Initialize();

	ADD_OBSERVER(PlayerDead, Game::OnPlayerDead);


}

void Game::Shutdown()
{
	scene->RemoveAll();
}

void Game::Draw(Renderer& renderer)
{
	scene->Draw(renderer);

}

void Game::OnPlayerDead(const Event& event)
{
	std::cout << "player dead\n";
}
