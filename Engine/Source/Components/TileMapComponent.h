#pragma once
#include "Component.h"
#include "../Math/Vector2.h"
#include <vector>

class TileMapComponent : public Component {

public:
	TileMapComponent() = default;

	CLASS_DECLARATION(TileMapComponent);
	

	void Initialize() override;
	void Update(float dt) override;
	

public:
	int numColumns;
	int numRows;
	Vector2 tileSize{ 0,0 };

	std::vector<std::string> tileNames;
	std::vector<int> tiles;


	// Inherited via Component
	std::unique_ptr<Object> Clone() override;

};
