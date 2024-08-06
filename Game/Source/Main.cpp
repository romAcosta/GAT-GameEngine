#include "Engine.h"


#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char* argv[])
{

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	//ResourceManager rm = ResourceManager();


	res_t texture = ResourceManager::Instance().Get<Texture>("assets/moleup.png", engine->GetRenderer());
	res_t<Font> font = ResourceManager::Instance().Get<Font>("Finland.ttf", 12);
	std::unique_ptr<Text> text = std::make_unique<Text>(font);
	text->Create(engine->GetRenderer(), "Hello!", { 0, 0, 0, 1 });

	std::cout << __FILE__ << std::endl;

	

	//Create Systems
	Time time;

	int* p = new int(5);


	//main loop
	bool quit = false;
	while (!quit)

	{
		engine->Update();
		if (engine->GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		time.Tick();

		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();


		
		engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
		text->Draw(engine->GetRenderer(), 200, 200);
		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();


	return 0;
}