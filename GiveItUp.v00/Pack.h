#pragma once
#include "GameObjectRender.h"
class Pack :public GameObjectRender
{
public:
	Pack();
	~Pack();
	//Pack(sf::Texture *texture, String text, String text2, float x, float y);
	Pack(sf::Texture *texture, float x, float y);
	sf::Sprite m_spritePack;
	sf::Text m_textCost;
	sf::Text m_textValue;
	sf::Font m_textfont;

};
