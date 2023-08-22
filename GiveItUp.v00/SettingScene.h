#pragma once
#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "Plate.h"
class SettingScene :public Scene
{
public:
	SettingScene();
	~SettingScene();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;
private:

	sf::Texture m_texturemenubackground;
	sf::Texture m_Texture_music;;
	sf::Texture m_Texture_buttonmenu;
	sf::Texture m_Texture_effect;
	sf::Sprite m_spritebuttoneffect;
	sf::Sprite m_spritebuttonmusic;
	sf::Sprite m_spritebuttonmenu;
	bool m_isMusicplay = 1;
	bool m_isSoundplay = 1;
	bool m_isMousedown = false;
	bool m_isMouseup = true;
	std::vector<Text> m_vText;
	//sf::Vector2f
	//

};

