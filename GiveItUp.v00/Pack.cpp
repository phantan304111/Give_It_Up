#include "stdafx.h"
#include "Pack.h"


Pack::Pack()
{
}


Pack::~Pack()
{
}
//Pack::Pack(sf::Texture texture, String text, String text2, float x, float y)
//{
//}
//Pack::Pack(sf::Texture texture,String text, String text2, float x, float y) {
//	m_spritePack.setTexture(texture);
//	m_spritePack.setPosition(x, y);

//	m_textfont.loadFromFile(Fonttext);
//	m_textCost.setFont(m_textfont);
//	m_textCost.setString(text);
//	m_textCost.setFillColor(sf::Color::Black);
//	m_textCost.setCharacterSize(40);
//	m_textCost.setPosition(x,y+110);
//
//	m_textValue.setFont(m_textfont);
//	m_textValue.setString(text2);
//	m_textValue.setFillColor(sf::Color::Black);
//	m_textValue.setCharacterSize(40);
//	m_textValue.setPosition(x, y + 150);
	//m_spritePlate.setScale(0.5f, 0.5f);
Pack::Pack(sf::Texture *texture, float x, float y)
{
	m_spritePack.setTexture(*texture);
	m_spritePack.setPosition(x, y);

	m_textValue.setPosition(x, y + 110);
	m_textValue.setFillColor(sf::Color::Black);
	m_textValue.setCharacterSize(40);

	m_textValue.setPosition(x, y + 150);
	m_textValue.setFillColor(sf::Color::Black);
	m_textValue.setCharacterSize(40);
	m_spritePack.setScale(0.2f, 0.2f);
}
