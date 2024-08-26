#include "TextureComponent.h"
#include "../Renderer/Renderer.h"
#include "../Framework/Actor.h"
#include "../Engine.h"
#include "../Resources/ResourceManager.h"

FACTORY_REGISTER(TextureComponent);
void TextureComponent::Initialize()
{
	if (!textureName.empty()) {
		texture = ResourceManager::Instance().Get<Texture>(textureName, owner->scene->engine->GetRenderer());
	}
	if (texture && source.w == 0 && source.h == 0) {
		source.x = 0;
		source.y = 0;	
		source.w = (int)texture->GetSize().x;
		source.h = (int)texture->GetSize().y;
	}
}

void TextureComponent::Update(float dt)
{
	// This may be used if a texture has an animation
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->GetTransform();
	renderer.DrawTexture(texture, transform);
}

void TextureComponent::Write(json_t& value)
{
}

void TextureComponent::Read(const json_t& value)
{
	READ_DATA_REQUIRED(value, textureName);
	READ_DATA(value, source);
}
