#pragma once
#include "GameObjectRender.h"
class Plate :public GameObjectRender
{
public:
	Plate();
	~Plate();
	Plate(sf::Texture* texture);
	Plate(sf::Texture* texture, float x, float y);
	Plate(sf::Texture* texture_1, sf::Texture* texture_2, float x);
	Plate(sf::Texture * texture_1, sf::Texture * texture_2, float x, float y_1, float y_2, int type);
	sf::Sprite m_spritePlate;
	sf::Sprite m_Col_1;
	sf::Sprite m_Col_2;
	int m_type = 0;
	bool is_colision = false;
	bool is_colision_2 = false;
	sf::Text m_textlevel;
};

