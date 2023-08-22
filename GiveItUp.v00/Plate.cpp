#include "stdafx.h"
#include "Plate.h"


Plate::Plate()
{
}


Plate::~Plate()
{
}
Plate::Plate(sf::Texture* texture) {
	m_spritePlate.setTexture(*texture);
	m_spritePlate.setPosition(COLUMM_X, COLUMM_Y);
	//m_spritePlate.setScale(0.5f, 0.5f);
	m_type = 0;
	is_colision = false;
	is_colision_2 = false;
}
Plate::Plate(sf::Texture* texture, float x, float y) {
	m_spritePlate.setTexture(*texture);
	m_spritePlate.setPosition(x, y);
	m_type = 0;
	//m_spritePlate.setScale(0.5f, 0.5f);
	is_colision = false;
	is_colision_2 = false;
}
Plate::Plate(sf::Texture* texture_1, sf::Texture* texture_2, float x) {
	m_Col_1.setTexture(*texture_1);//dia
	m_Col_1.setPosition(x + 2, 290);
	m_Col_2.setTexture(*texture_2);//tru
	m_Col_2.setPosition(x, 335);
	m_type = 1;
	is_colision = false;
	is_colision_2 = false;
}

Plate::Plate(sf::Texture * texture_1, sf::Texture * texture_2, float x, float y_1,float y_2,int type)
{
	m_Col_1.setTexture(*texture_1);//dia
	m_Col_1.setPosition(x+2, y_1);
	m_Col_2.setTexture(*texture_2);//tru
	m_Col_2.setPosition(x, y_2);
	m_type = type ;
	is_colision = false;
	is_colision_2 = false;
}
