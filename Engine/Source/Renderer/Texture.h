#pragma once
#include "../Resources/Resource.h"
#include <string>
#include "../Math/Vector2.h"
#include "Renderer.h"

struct SDL_Texture;

class Texture : public Resource
{
public:
	Texture() = default;
	Texture(SDL_Texture* texture) : m_texture{texture}{}
	~Texture() = default;

	bool Load(const std::string& filename, class Renderer& renderer);

	// Inherited via Resource
	bool Create(std::string name, ...) override;

	Vector2 GetSize();

	friend class Renderer;

private:
	SDL_Texture* m_texture{ nullptr };

	
};