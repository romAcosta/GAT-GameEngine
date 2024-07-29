#include "Engine.h"


#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char* argv[])
{
	g_engine.Initialize();


	//Create Systems
	Time time;



	//main loop
	bool quit = false;
	while (!quit)
	{
		if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
		}
		time.Tick();

		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		

		g_engine.GetRenderer().EndFrame();
	}
	g_engine.Shutdown();
	return 0;
}