#pragma once
#include "define.h"
#include "GameManagerState.h"
class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update(float deltime, E &e);
	virtual void Render(sf::RenderWindow &window);
	virtual void Init();
	void ScalespriteOut(sf::Sprite &s);
	void ScalespriteIn(sf::Sprite &s);
	virtual void Mouseup();
	virtual void Mousedown();

	void ShowCoin();

	//
	State m_st = GameManagerState::getInstance()->getState();
	//
	int Flag_skin = 0;
	int Flag_level = 0;
	int Coin = 0;
	bool Flag_Music = true;
	bool Flag_Sound = true;
	bool m_IsSwitch = false;
	sf::Text m_textcoin;
	sf::Texture m_texttureCoin;
	sf::Sprite m_spriteCoin;
	sf::Texture m_Texture_Goldbag;
	sf::Sprite m_spriteGoldbag;
	//
protected:
	char* bacgroundPath;
	sf::Texture m_textureBackground;
	sf::Sprite m_spriteBackground;
	sf::Font font;
	sf::Vector2u m_vecTextureSize;
	sf::Vector2u m_vecWindowSize;

	sf::Music m_music_Scene;
	sf::Sound m_SoundEffect;
	sf::SoundBuffer m_SoundBufferEffect;
	sf::Vector2i m_mousePos;
	sf::Vector2u m_mouseSize;
	sf::Font m_fontScene;
	sf::Text m_textScene;
	float t = 0;
	bool is_start = false;
	bool is_click = false;
	bool is_end = false;
};	

