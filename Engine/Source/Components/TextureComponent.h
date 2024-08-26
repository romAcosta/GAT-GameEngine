#pragma once
#include "RenderComponent.h"
#include "../Renderer/Texture.h"
#include"../Math/Rect.h"

class TextureComponent : public RenderComponent
{
public:
	

	CLASS_DECLARATION(TextureComponent);
	CLASS_PROTOTYPE(TextureComponent);

	void Initialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	

public:
	std::string textureName;
	res_t<Texture> texture;
	Rect source;

};