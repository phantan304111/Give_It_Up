#include "stdafx.h"
#include "MenuScene.h"
MenuScene::MenuScene()
{
}


MenuScene::~MenuScene()
{
}
void MenuScene::Init() {
	cout << Flag_skin;
	is_start = true;
	m_IsSwitch = false;
	if (!m_SoundBufferEffect.loadFromFile(SoundButton) || !m_fontScene.loadFromFile(Fonttext) || !m_music_Scene.openFromFile(MusicMenu))
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


		m_music_Scene.openFromFile(MusicMenu);
	
		m_music_Scene.play();
		m_music_Scene.setLoop(true);

		m_fontScene.loadFromFile(Fonttext);
		m_textScene.setFont(m_fontScene);
		m_textScene.setString("Select Level");
		m_textScene.setFillColor(sf::Color::Black);
		m_textScene.setCharacterSize(30);
		m_textScene.setPosition(WINDOWS_W / 2 - 110, WINDOWS_H / 4 - 25);
		/*m_textcoin.setFont(m_fontScene);
		m_textcoin.setString(to_string(Coin));
		m_textcoin.setFillColor(sf::Color::Black);
		m_textcoin.setCharacterSize(40);
		m_textcoin.setPosition(55,0);*/
		
	}

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU))
	{
		cout << "error" << endl;
	}
	else {
		
		//textture load
		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU);
		m_Texture_buttonplay.loadFromFile(TEXTURE_BACKGROUNDBTNPlay);
		m_Texture_buttonskin.loadFromFile(Skin3);
		m_Texture_buttondaily.loadFromFile(TEXTURE_BACKGROUNDBTNCalendar);
		m_texturePlate.loadFromFile(TEXTURE_MINICOLUMM);
		m_TextureFlag.loadFromFile(TEXTURE_Flag);
		m_Texture_buttonsetings.loadFromFile("../resources/texture/Button/BTNSettings.png");
		m_textturelogo.loadFromFile(TEXTURE_Pack);
		switch (Flag_skin)
		{
		case 0:
			m_Textureskin.loadFromFile(Skin0);

			break;
		case 1:
			m_Textureskin.loadFromFile(Skin1);
			break;
		case 2:
			m_Textureskin.loadFromFile(Skin2);
			break;
		case 3:
			m_Textureskin.loadFromFile(Skin3);
			break;
		case 4:
			m_Textureskin.loadFromFile(Skin4);
			break;
		case 5:
			m_Textureskin.loadFromFile(Skin5);
			break;
		case 6:
			m_Textureskin.loadFromFile(Skin6);
			break;
		default:
			m_Textureskin.loadFromFile(Skin0);
			break;
		}
		//Coin

		ShowCoin();
		m_Texture_Goldbag.loadFromFile(TEXTURE_GoldBag);
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);

		//m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 4 - play.x / 2, WINDOWS_H / 6 * 5 - play.y / 2);
		m_spritebuttonskin.setPosition(WINDOWS_W / 18 * 4  , WINDOWS_H / 6 * 5 );
		m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 9 -10, WINDOWS_H/6 * 5 -30);
		m_spritebuttondaily.setPosition(WINDOWS_W / 18 * 14  , WINDOWS_H /6 * 5);
		m_spritebuttonbuttonsetings.setPosition(0,WINDOWS_H - 80);
		m_spriteGoldbag.setPosition(WINDOWS_W - 80, 0);
		m_spritelogo.setPosition(WINDOWS_W / 9*8, WINDOWS_H / 6*5);
		//sprite set texture
		m_spritebuttonplay.setTexture(m_Texture_buttonplay);
		m_spritebuttonskin.setTexture(m_Texture_buttonskin);
		m_spritebuttondaily.setTexture(m_Texture_buttondaily);
		m_spriteskin.setTexture(m_Textureskin);
		m_spritebuttonbuttonsetings.setTexture(m_Texture_buttonsetings);
		
		m_spriteGoldbag.setTexture(m_Texture_Goldbag);
		m_spritelogo.setTexture(m_textturelogo);
		m_spriteBackground.setScale(ScaleX, ScaleY);
		m_spriteBackground.setScale(ScaleX, ScaleY);

		m_spritebuttonskin.scale(sf::Vector2f(0.001f, 0.001f));
		m_spritebuttondaily.scale(sf::Vector2f(0.0015f, 0.0015f));
		m_spritebuttonplay.scale(sf::Vector2f(0.0015f, 0.0015f));
		m_spriteskin.scale(0.24f, 0.24f);

		float x = 155.f;
		m_spriteskin.setPosition(x + Flag_level *70, 40.f);
		for (int i = 0; i < 4; i++) {
			m_vPlate.push_back(Plate(&m_texturePlate, x, 70.f));
			m_vPlate[i].m_spritePlate.setScale(0.5, 0.5);
			x += 70;
		}
//		m_vPlate[m_iFlag_level].m_spritePlate.setTexture(m_TextureFlag);
		m_vPlate[Flag_level].m_spritePlate.setTexture(m_TextureFlag);
	}
	m_spritelogo.setScale(0.2, 0.2);
}


void MenuScene::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	window.draw(m_spritebuttonplay);
	window.draw(m_spritebuttondaily);
	window.draw(m_spritebuttonskin);
	window.draw(m_spriteskin);
	window.draw(m_textScene);
	window.draw(m_spritebuttonbuttonsetings);
	window.draw(m_spriteCoin);
	window.draw(m_spriteGoldbag);
	window.draw(m_textcoin);
	window.draw(m_spritelogo);
	for (size_t i = 0; i < m_vPlate.size(); i++) 
	{

		window.draw(m_vPlate[i].m_spritePlate);
	}
	m_mousePos = sf::Mouse::getPosition(window);



	
}

void MenuScene::Update(float dt, E & e) {
	if (e == MOUSE_LEFT) {
		Mousedown();
		
	}

	if (e == MOUSE_LEFT_RELEASE)
	{

		
		Mouseup();
	}
		if (is_start) {
			if (m_spritebuttonplay.getScale().x < 1)
			{
				ScalespriteIn(m_spritebuttondaily);
				ScalespriteIn(m_spritebuttonplay);
				ScalespriteIn(m_spritebuttonskin);
			}
			else
			{
				is_start = false;
			}
		}

		if (is_end) {
			is_start = false;
			t += dt;

			ScalespriteOut(m_spritebuttondaily);
			ScalespriteOut(m_spritebuttonplay);
			ScalespriteOut(m_spritebuttonskin);
			if (t > 2)
			{
				m_music_Scene.stop();
				m_IsSwitch = true;
			}
		}
	}
	void MenuScene::Mouseup()
{
		m_isMouseup = true;

		if (m_isMousedown)
		{
			sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
			if (m_spriteGoldbag.getGlobalBounds().contains(mousePosF))
			{
				if (m_isMousedown)
				{
					Coin += 5;
					m_textcoin.setString(to_string(Coin));
				}
			}
			else if (m_spritebuttonplay.getGlobalBounds().contains(mousePosF))
			{
				m_SoundEffect.play();
				m_st = GAMEPLAY;
				is_end = true;
			}
			else if (m_spritebuttondaily.getGlobalBounds().contains(mousePosF))
			{
				//su kien dailyquest
				is_end = true;
				m_st = Win;
				m_SoundEffect.play();
			}
			else if (m_spritebuttonskin.getGlobalBounds().contains(mousePosF))
			{
				m_SoundEffect.play();
				is_end = true;
				m_st = SKIN;
			}
			else if (m_spritebuttonbuttonsetings.getGlobalBounds().contains(mousePosF))
			{
				m_st = SETTING;
				is_end = true;
				
				m_SoundEffect.play();

			}
			else if (m_spritelogo.getGlobalBounds().contains(mousePosF))
			{
				m_st = Buy;
				is_end = true;

				m_SoundEffect.play();

			}
			/*else if (m_spriteGoldbag.getGlobalBounds().contains(mousePosF))
			{
			Coin += 5;
			m_textcoin.setString(to_string(Coin));
			}*/
			for (unsigned int i = 0; i < m_vPlate.size(); i++)
			{
				if (m_vPlate[i].m_spritePlate.getGlobalBounds().contains(mousePosF))
				{

					sf::Vector2f pos = m_vPlate[i].m_spritePlate.getPosition();
					m_spriteskin.setPosition(pos.x, 40);
					for (unsigned int i = 0; i < m_vPlate.size(); i++)
					{
						m_vPlate[i].m_spritePlate.setTexture(m_texturePlate);
					}
					//m_iFlag_level = i;
					Flag_level = i;
					m_vPlate[Flag_level].m_spritePlate.setTexture(m_TextureFlag);
					/*Flag_skin = i;*/


				}
			}
		}
			m_isMousedown = false;
}

	void MenuScene::Mousedown()
	{
		m_isMousedown = true;
		m_isMouseup = false;
	}
