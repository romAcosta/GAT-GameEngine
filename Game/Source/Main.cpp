#include "Engine.h"


#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char* argv[])
{

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

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

		

		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();


	return 0;
}