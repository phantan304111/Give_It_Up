#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "Plate.h"

class MenuScene :public Scene
{
public:
	MenuScene();
	~MenuScene();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;
private:

	sf::Texture m_texturemenubackground;
	sf::Texture m_texturePlate;
	sf::Texture m_Textureskin;
	sf::Texture m_Texture_buttonsetings;;
	sf::Texture m_Texture_buttonskin;
	sf::Texture m_TextureFlag;
	sf::Texture m_Texture_buttondaily;
	sf::Texture m_Texture_buttonplay;

	sf::Sprite m_spritebuttonplay;
	sf::Sprite m_spritebuttonskin;
	sf::Sprite m_spritebuttondaily;
	sf::Sprite m_spritebuttonbuttonsetings;
	sf::Sprite m_spriteskin;
	sf::Sprite m_spritelogo;
	//
	sf::Texture m_textturelogo;
	sf::Texture m_Texture_Goldbag;
	sf::Sprite m_spriteGoldbag;
	//
	std::vector<Plate> m_vPlate;
	sf::Text m_SafeStation;

	bool m_isMousedown = false;
	bool m_isMouseup = true;
	//
	
};

