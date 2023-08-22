#include "stdafx.h"
#include "Skin.h"


Skin::Skin()
{
}


Skin::~Skin()
{
}
Skin::Skin(sf::Texture texture) {
	m_spriteSkin.setTexture(texture);
	m_spriteSkin.setPosition(COLUMM_X, COLUMM_Y);
	//m_spritePlate.setScale(0.5f, 0.5f);
}
Skin::Skin(sf::Texture texture, float x, float y) {
	m_spriteSkin.setTexture(texture);
	m_spriteSkin.setPosition(x, y);
	//m_spritePlate.setScale(0.5f, 0.5f);
}
Skin::Skin(float x, float y) {
	m_spriteSkin.setPosition(x,y);
}
