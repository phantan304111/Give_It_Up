#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Skin.h"
#include "GameObjectRender.h"
class SkinScene :public Scene
{
public:
	SkinScene();
	~SkinScene();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;
private:
	sf::Texture m_texturemenubackground;



	sf::Sprite m_spriteFlag;

	sf::Texture m_TextureFlag;
	sf::Texture m_Texture_buttonBuy;
	sf::Texture m_Texture_buttonSelect;
	sf::Texture m_Texture_skin;
	sf::Sprite m_spritebuttonBuy;
	sf::Sprite m_spritebuttonSelect;
	int m_iSkinnumber = 8;
	int m_iFlag_Skin = 0;
	int m_isMouseClick = 0;
	sf::Texture m_skintexture0;
	sf::Texture m_skintexture1;
	sf::Texture m_skintexture2;
	sf::Texture m_skintexture3;
	sf::Texture m_skintexture4;
	sf::Texture m_skintexture5;	
	sf::Texture m_skintexture6;
	std::vector<Skin> m_vSkin;
	std::vector<Texture> m_vTexture;
	sf::Text m_SafeStation;
	bool m_isMousedown = false;
	bool m_isMouseup = true;

	//

};

