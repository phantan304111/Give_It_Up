#include "stdafx.h"
#include "Scene.h"

Scene::Scene() {

}
Scene::~Scene() {

}
void Scene::Init() {}
void Scene::Update(float dt, E &e) {};
void Scene::Render(RenderWindow &window) {};
//void Scene::ScalespriteOut(float dt, sf::Sprite & s)
void Scene::ScalespriteOut(sf::Sprite & s)

{
	//float t = 0;
	//float m_scale = 0.955;
	//t += dt;
	//	s.scale(sf::Vector2f(m_scale, m_scale));

	//if (t >= 4) {
	//		t = 0;
	//}

		s.scale(sf::Vector2f(0.8f, 0.8f));
		Vector2f pos = s.getScale();
		s.move(pos.x * 15, pos.y * 15);
}

void Scene::ScalespriteIn(sf::Sprite & s)
{
		s.scale(sf::Vector2f(1.2f, 1.2f));
		Vector2f pos = s.getScale();
		s.move(-pos.x *10, -pos.y * 10);
}

void Scene::Mouseup()
{
}

void Scene::Mousedown()
{
}

void Scene::ShowCoin()
{
	m_texttureCoin.loadFromFile(TEXTURE_COIN);
	m_spriteCoin.setTexture(m_texttureCoin);
	m_spriteCoin.setPosition(0, 0);
	m_textcoin.setFont(m_fontScene);
	m_textcoin.setString(to_string(Coin));
	m_textcoin.setFillColor(sf::Color::Black);
	m_textcoin.setCharacterSize(40);
	m_textcoin.setPosition(55, 0);
}





