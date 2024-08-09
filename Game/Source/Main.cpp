#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>



int main(int argc, char* argv[])
{

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();
	File::SetFilePath("assets");
	std::string s;
	File::ReadFile("text.txt",s );

	std::cout << s << std::endl;

	rapidjson::Document document;
	Json::Load("text.txt", document);

	std::string name;
	int age;
	bool isAwake;
	float speed;
	Vector2 position;
	std::vector<int> list;

	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, isAwake);
	READ_DATA(document, speed);
	READ_DATA(document, position);
	READ_DATA(document, list);

	std::ostringstream strPosition ;
	strPosition << "(" << position.x << "," << position.y << ")";
	std::ostringstream liststr;
	for (int i = 0; i < list.size(); i++) {
		liststr << list[i] << " ";
	}
	
	std::cout << "name: " << name << std::endl;
	std::cout << "age: " << age << std::endl;
	std::cout << "isAwake: " << isAwake << std::endl;
	std::cout << "speed: " << speed << std::endl;
	std::cout << "position: " << strPosition.str() << std::endl;
	std::cout << "list: " << liststr.str() << std::endl;
	//ResourceManager rm = ResourceManager();


	res_t texture = ResourceManager::Instance().Get<Texture>("moleup.png", engine->GetRenderer());
	res_t<Font> font = ResourceManager::Instance().Get<Font>("Finland.ttf", 12);
	std::unique_ptr<Text> text = std::make_unique<Text>(font);
	text->Create(engine->GetRenderer(), "Hello!", { 0, 0, 0, 1 });

	std::cout << __FILE__ << std::endl;


	
	//actor->AddComponent(std::move(component));

	//Create Systems
	Time time;

	


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
		//actor->Draw(engine->GetRenderer());

		
		engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
		text->Draw(engine->GetRenderer(), 200, 200);
		engine->GetRenderer().EndFrame();
	}

	engine->Shutdown();


	return 0;
}