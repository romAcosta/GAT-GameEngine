#include "Engine.h"
#include "Framework/Scene.h"
#include "Components/PlayerComponent.h"
#include "Components/RocketComponent.h"
#include "MyGame.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>



int main(int argc, char* argv[])
{
	File::SetFilePath("Assets");
	

	FACTORY_REGISTER(Actor);
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());
	Factory::Instance().Register<TextComponent>(TextComponent::GetTypeName());
	Factory::Instance().Register<CircleCollisionComponent>(CircleCollisionComponent::GetTypeName());
	Factory::Instance().Register<RocketComponent>(RocketComponent::GetTypeName());
	Factory::Instance().Register<AudioComponent>(AudioComponent::GetTypeName());



	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	std::unique_ptr<Game> game = std::make_unique<Game>(engine.get());
	game->Initialize();





	//main loop
	bool quit = false;
	while (!quit)
	{
		if (engine->GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}



		engine->Update();
		game->Update();



		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();
		////////////////////////

		game->Draw(engine->GetRenderer());


		////////////////////////
		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();


	return 0;
}