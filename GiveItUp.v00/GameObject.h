#pragma once
#include "define.h"
class GameObject
{
public:
	virtual void Init(const char* textureName = "", int x = 0, int y = 0) = 0;
	virtual void Update(float dt) = 0;
	virtual void Render(sf::RenderWindow &window) = 0;
};

