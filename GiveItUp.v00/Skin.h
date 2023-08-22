#pragma once
#include "GameObjectRender.h"
class Skin :public GameObjectRender
{
public:
	Skin();
	~Skin();
	Skin(sf::Texture texture);
	Skin(sf::Texture texture, float x, float y);


	Skin (float x, float y);
	sf::Sprite m_spriteSkin;
	sf::Texture m_skintexture;
	sf::Text m_textskin;
};

