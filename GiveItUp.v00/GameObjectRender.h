#pragma once
#include "GameObject.h"
class GameObjectRender :public GameObject
{
public:
	GameObjectRender();
	~GameObjectRender();
	GameObjectRender(const char * textureName, int x, int y);
	void Init(const char * textureName, int x, int y)override;
	void Render(sf::RenderWindow &window);
	virtual void Update(float dt);
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u m_vecTextureSize;
	sf::Vector2u m_vecWindowSize;


};

