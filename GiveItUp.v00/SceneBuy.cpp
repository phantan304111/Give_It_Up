#include "stdafx.h"
#include "SceneBuy.h"
SceneBuy::SceneBuy()
{
}


SceneBuy::~SceneBuy()
{
}
void SceneBuy::Init() {
	is_start = true;
	m_IsSwitch = false;
	ShowCoin();


	if (!m_SoundBufferEffect.loadFromFile(SoundButton) || !m_fontScene.loadFromFile(Fonttext) || !m_music_Scene.openFromFile(MusicSceneSkin))
	{
		std::cout << "ERROR" << std::endl;
	}
	else {

		m_SoundEffect.setBuffer(m_SoundBufferEffect);
		if (Flag_Sound)
			m_SoundEffect.setVolume(100);
		else
			m_SoundEffect.setVolume(0);
		if (Flag_Music)
			m_music_Scene.setVolume(70);
		else
			m_music_Scene.setVolume(0);
		m_textScene.setFont(m_fontScene);
		m_textScene.setString("Choice your Pack!!");
		m_textScene.setFillColor(sf::Color::Black);
		m_textScene.setCharacterSize(50);
		m_textScene.setPosition(WINDOWS_W / 3, 10);
		m_music_Scene.play();
		m_music_Scene.setLoop(true);
	}

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU))
	{
		cout << "error" << endl;
	}
	else {


		m_font.loadFromFile(Fonttext);


		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU);
		m_Texture_buttonBuy.loadFromFile(TEXTURE_BACKGROUNDBTNBuy);
		m_Texture_buttonSelect.loadFromFile(TEXTURE_BTNSelect);
		m_textture_pack.loadFromFile(TEXTURE_Pack);

		//m_textureminiMC.loadFromFile(TEXTURE_MC);
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);

	
		m_texttureCoin.loadFromFile("../resources/texture/Coin.png");
		//m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 4 - play.x / 2, WINDOWS_H / 6 * 5 - play.y / 2);
		m_spritebuttonBuy.setPosition(WINDOWS_W / 9 * 3 - 25, WINDOWS_H / 6 * 5);
		m_spritebuttonSelect.setPosition(WINDOWS_W / 9 * 6 - 25, WINDOWS_H / 6 * 5 - 30);

		
		m_spritebuttonBuy.setTexture(m_Texture_buttonBuy);
		m_spritebuttonSelect.setTexture(m_Texture_buttonSelect);
		m_spriteBackground.setScale(ScaleX, ScaleY);
		m_spritebuttonSelect.scale(sf::Vector2f(0.0015f, 0.0015f));
		m_spritebuttonBuy.scale(sf::Vector2f(0.0015f, 0.0015f));


	}
		for (int i = 0; i < 6; i++) {
			/*
			m_vPack[i].m_textCost.setFont(m_font);*/
			
	
				m_vPack.push_back(Pack(&m_textture_pack, 100 + i * 120.f, 70.f));
				m_vPack[i].m_textValue.setFont(m_font);
				m_vPack[i].m_textValue.setString(to_string((i+1)*50+i*10));
				m_vPack[i].m_textValue.setFillColor(sf::Color::Yellow);
				m_vPack[i].m_textValue.setCharacterSize(20);
				m_vPack[i].m_textValue.setPosition(140 + i * 120.f, 160.f);

				m_vPack[i].m_textCost.setFont(m_font);
				m_vPack[i].m_textCost.setString(to_string((i + 1) * 10000)+"vnd");
				m_vPack[i].m_textCost.setFillColor(sf::Color::White);
				m_vPack[i].m_textCost.setCharacterSize(15);
				m_vPack[i].m_textCost.setPosition(120 + i * 120.f, 185.f);

			}

	}


void SceneBuy::Render(RenderWindow &window) {
	//Background
	window.draw(m_spriteBackground);
	window.draw(m_spritebuttonBuy);
	window.draw(m_spritebuttonSelect);
	window.draw(m_textScene);
//	window.draw(m_spriteFlag);
	window.draw(m_spriteCoin);
	window.draw(m_textcoin);
	for (size_t i = 0; i < 6; i++)
	{
	window.draw(m_vPack[i].m_spritePack);
		window.draw(m_vPack[i].m_textCost);
		window.draw(m_vPack[i].m_textValue);
	}
	m_mousePos = sf::Mouse::getPosition(window);


}
void SceneBuy::Update(float dt, E & e) {

	if (e == MOUSE_LEFT)
		Mousedown();
	if (e == MOUSE_LEFT_RELEASE) {
		Mouseup();

	}
	if (is_start) {
		if (m_spritebuttonBuy.getScale().x < 1)
		{
			ScalespriteIn(m_spritebuttonBuy);
			ScalespriteIn(m_spritebuttonSelect);
		}
		else
		{
			is_start = false;
		}
	}
	if (is_end) {
		t += dt;
		is_start = false;
		ScalespriteOut(m_spritebuttonBuy);
		ScalespriteOut(m_spritebuttonSelect);
		if (t > 2)
		{
			m_music_Scene.stop();
			m_IsSwitch = true;
		}
	}
}

void SceneBuy::Mouseup()
{
	m_isMouseup = true;

	if (m_isMousedown)
	{
		sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		if (m_spritebuttonBuy.getGlobalBounds().contains(mousePosF))
		{
			is_end = true;
			m_st = MENU;
			m_SoundEffect.play();

		}
		else if (m_spritebuttonSelect.getGlobalBounds().contains(mousePosF))
		{
			is_end = true;
			m_st = MENU;
			m_SoundEffect.play();



		}
		for (int i = 0; i < 6; i++)
		{
			if (m_vPack[i].m_spritePack.getGlobalBounds().contains(mousePosF))
			{
				sf::Vector2f pos = m_vPack[i].m_spritePack.getPosition();
				Coin += (i+1) * 50 + i*10;
				m_textcoin.setString(to_string(Coin));
				/*m_spriteFlag.setTexture(m_TextureFlag);
				m_spriteFlag.setPosition(pos.x + 10, 20);
				m_spriteFlag.setScale(0.08, 0.08);
				for (int i = 0; i < m_iSkinnumber; i++)
				{
					m_vSkin[i].m_spriteSkin.setColor(sf::Color::White);
				}
				m_vSkin[i].m_spriteSkin.setColor(sf::Color::Green);
				Flag_skin = i;*/
			}
		}
	}
	m_isMousedown = false;
}

void SceneBuy::Mousedown()
{
	m_isMousedown = true;
	m_isMouseup = false;
}

