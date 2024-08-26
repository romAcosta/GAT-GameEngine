#pragma once
#include "../Math/Vector2.h"
#include "../Core/Serializable.h"

struct Transform : public Serializable
{
	Vector2 position;
	float rotation;
	float scale;

	Transform() = default;
	Transform(Vector2 position, float rotation = 0, float scale = 1) :
		position(position),
		rotation(rotation),
		scale(scale)
	{}

	Vector2 Forward() { return Vector2{ 1,0 }.Rotate(Math::DegToRad(rotation)); }

	void Read(const json_t& value) override;
	void Write(json_t& value) override;
};