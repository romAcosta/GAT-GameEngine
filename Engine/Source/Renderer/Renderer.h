#pragma once
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <memory>
#include "../Math/Vector2.h"
#include "Texture.h"


class Renderer {

public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();
	
	bool CreateWindow(std::string title, int width, int height);
	void BeginFrame();
	void EndFrame();


	void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawPoint(int x, int y);
	void DrawRect(int x, int y, int w, int h);
	void DrawRect(float x, float y,float w,float h);
	
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }

	void DrawTexture(std::weak_ptr<class Texture> texture, float x, float y, float angle = 0.0f);
	void DrawTexture(std::weak_ptr<class Texture> texture, const struct Transform& transform, bool hflip = false);

	friend class Text;
	friend class Texture;

protected:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };

	int m_width{ 0 };
	int m_height{ 0 };

};
