#pragma once
#include "RenderComponent.h"

class TextComponent : public RenderComponent 
{
public:
	CLASS_DECLARATION(TextComponent);
	// Inherited via RenderComponent
	void Initialize() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;
	void SetText(const std::string& text);

public:
	std::string text;
	std::string fontName;
	int fontSize = 8;
	Color color{ 1,1,1,1 };

private:
	std::unique_ptr<class Text> m_text;
	bool textChanged = true;
};