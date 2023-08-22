
#pragma once
#include "Scene.h"
#include "GameScene.h"

class SceneWin :public Scene
{
public:
	SceneWin();
	~SceneWin();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;

private:
	//float m_fPlateSpawnTimer = 0.f;
	sf::Texture m_texturemenubackground;
	sf::Event ev;

	//float m_fTCurrentScene = 0;
	float m_scale = 1;

	//
	Scene *m_sCurrentScene;
	sf::Texture m_Texture_buttonReplay;
	sf::Texture m_Texture_buttonMenu;
	sf::Texture m_Texture_buttonPlay;
	sf::Texture m_Texture_MC;
	sf::Text m_Textwon;
	sf::Sprite m_spriteMC;
	sf::Sprite m_spritebuttonReplay;
	sf::Sprite m_spritebuttonMenu;
	sf::Sprite m_spritebuttonPlay;
	sf::Text m_SafeStation;
	bool m_isMousedown = false;
	bool m_isMouseup = true;
	//

};

