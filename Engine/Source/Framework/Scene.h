#pragma once

#include <memory>
#include <list>

class Renderer;
class Actor;


class Scene
{
public:
	Scene() = default;

	void Update(float dt);
	void Draw( Renderer& renderer);

	void AddActor(std::unique_ptr < Actor> actor);
	int GetScore() { return score; }
	void AddScore(int score) { this->score += score; }
	void GameOver() { game_over = true; }
	void GameOn() { game_over = false; }
	bool GetGame() { return game_over; }
	void Day() { day = true; }
	void Night() { day = false; }
	bool GetDay() { return day; }
	

	template<typename T>
	T* GetActor();

protected:

	std::list<std::unique_ptr<Actor>> m_actors;
	int score = 0;
	bool game_over = false;
	bool day = false;


};

template<typename T>
T* Scene::GetActor() 
{

	for (Actor* actor : m_actors) {
		T* result = dynamic_cast<T*> (actor);
		if (result) {return result;}
	}



	return nullptr;


}
