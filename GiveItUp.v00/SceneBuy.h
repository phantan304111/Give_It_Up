#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Pack.h"

#include "GameObjectRender.h"
class SceneBuy :public Scene
{
public:
	SceneBuy();
	~SceneBuy();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;
private:
	sf::Texture m_texturemenubackground;



	sf::Sprite m_spriteFlag;
	sf::Texture m_Texture_buttonBuy;
	sf::Texture m_Texture_buttonSelect;
	sf::Texture m_textture_pack;
	sf::Sprite m_spritebuttonBuy;
	sf::Sprite m_spritebuttonSelect;
	std::vector<Pack> m_vPack;
	bool m_isMousedown = false;
	bool m_isMouseup = true;
	sf::Font m_font;

	//

};

#pragma once
