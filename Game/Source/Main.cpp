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
	Factory::Instance().Register<TextComponent>(TextComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	


	File::SetFilePath("Assets");
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	
	


	
	
	

	//Create Systems
	
	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();





	//main loop
	bool quit = false;
	while (!quit)
	{
		if (engine->GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		
		
		
		engine->Update();
		scene->Update(engine->GetTime().GetDeltaTime());

		/*auto* actor = scene->GetActor<Actor>();
		if (actor) {
			actor->transform.rotation += 0.1f;
		}*/

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