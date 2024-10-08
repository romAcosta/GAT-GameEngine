#include "Text.h"
#include "../Framework/Color.h"
#include "Renderer.h"
#include "Font.h"
#include <iostream>
#include<SDL.h>
#include <assert.h>




bool Text::Create(Renderer& renderer, const std::string& text, const Color& color)
{
	// create a surface using the font, text string and color
	SDL_Color c{ Color::ToInt(color.r), Color::ToInt(color.g), Color::ToInt(color.b), Color::ToInt(color.a) };
	SDL_Surface* surface = TTF_RenderText_Solid(m_font->m_ttfFont, text.c_str(), c);
	if (surface == nullptr)
	{
		std::cerr << "Could not create surface.\n";
		return false;
	}

	// create a texture from the surface, only textures can render to the renderer
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
	if (texture == nullptr)
	{
		SDL_FreeSurface(surface);
		std::cerr << "Could not create texture" << SDL_GetError() << std::endl;
		return false;
	}


	// free the surface, no longer needed after creating the texture
	SDL_FreeSurface(surface);

	m_texture = std::make_shared<Texture>(texture);

	return true;
}

void Text::Draw(Renderer& renderer, float x, float y, float angle)
{
	assert(m_texture);

	renderer.DrawTexture(m_texture, x, y, angle);


	//// query the texture for the texture width and height
	//int width, height;
	//SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

	//// copy the texture onto the renderer
	//SDL_Rect rect{ x, y, width, height };
	//SDL_RenderCopy(renderer.m_renderer, m_texture, NULL, &rect);
}
