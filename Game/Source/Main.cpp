#include "Engine.h"
#include "Framework/Scene.h"
#include "Components/PlayerComponent.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>



int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	


	File::SetFilePath("Assets");
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	res_t<Font> font = ResourceManager::Instance().Get<Font>("Finland.ttf", 12);
	std::unique_ptr<Text> text = std::make_unique<Text>(font);
	text->Create(engine->GetRenderer(), "Hello!", { 0, 0, 0, 1 });
	


	
	
	

	//Create Systems
	
	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();





	//main loop
	bool quit = false;
	while (!quit)
	{
		engine->Update();
		
		if (engine->GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		
		scene->Update(engine->GetTime().GetDeltaTime());


		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();
		////////////////////////

		scene->Draw(engine->GetRenderer());


		////////////////////////
		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();


	return 0;
}