#include "stdafx.h"
#include "SettingScene.h"
SettingScene::SettingScene()
{
}


SettingScene::~SettingScene()
{
}
void SettingScene::Init() {	
	is_start = true;
	m_IsSwitch = false;
	
	if (!m_SoundBufferEffect.loadFromFile(SoundButton) || !m_fontScene.loadFromFile(Fonttext) || !m_music_Scene.openFromFile("../resources/Audio/Credit.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	else {
		m_SoundEffect.setVolume(100);
		m_music_Scene.setVolume(70);
		m_SoundEffect.setBuffer(m_SoundBufferEffect);

		/*Flag_Sound = true;
		Flag_Music = true;*/
		if(Flag_Sound)
		m_SoundEffect.setVolume(100);
		else
		m_SoundEffect.setVolume(0);
		if(Flag_Music)
		m_music_Scene.setVolume(70);
		else
		m_music_Scene.setVolume(0);


		m_music_Scene.play();
		m_music_Scene.setLoop(true);

		m_fontScene.loadFromFile(Fonttext);
		m_textScene.setFont(m_fontScene);
		m_textScene.setString("BiBle_JumP_TeaM");
		m_textScene.setFillColor(sf::Color::White);
		m_textScene.setCharacterSize(55);
		m_textScene.setPosition(70, WINDOWS_H / 6 - 50);
	}

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU))
	{
		cout << "error" << endl;
	}
	else {
		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU);
		m_Texture_music.loadFromFile("../resources/texture/Button/BTNMusic.png");
		m_Texture_effect.loadFromFile("../resources/texture/Button/BTNSound.png");
		m_Texture_buttonmenu.loadFromFile(TEXTURE_BACKGROUNDBTNMenu);
	
		//m_textureminiMC.loadFromFile(TEXTURE_MC);
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);
		//m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 4 - play.x / 2, WINDOWS_H / 6 * 5 - play.y / 2);
		m_spritebuttonmenu.setPosition(WINDOWS_W -125, WINDOWS_H / 6 * 5);
		m_spritebuttonmusic.setPosition(WINDOWS_W -150, WINDOWS_H / 6 * 3-50 );
		m_spritebuttoneffect.setPosition(WINDOWS_W - 150, WINDOWS_H / 6);


		
		if (Flag_Music)
			m_Texture_music.loadFromFile("../resources/texture/Button/BTNMusic.png");
		else
			m_Texture_music.loadFromFile("../resources/texture/Button/BTNMusicDelete.png");
		if (Flag_Sound)
			m_Texture_effect.loadFromFile("../resources/texture/Button/BTNSound.png");
		else
			m_Texture_effect.loadFromFile("../resources/texture/Button/BTNSoundDelete.png");


		m_spritebuttonmenu.setTexture(m_Texture_buttonmenu);
		m_spritebuttonmusic.setTexture(m_Texture_music);
		m_spritebuttoneffect.setTexture(m_Texture_effect);

		m_spriteBackground.setScale(ScaleX, ScaleY);
		m_spriteBackground.setScale(ScaleX, ScaleY);

		m_spritebuttonmenu.scale(sf::Vector2f(0.001f, 0.001f));
	}

	for (int i = 0; i < 3; i++)
	{
		//m_vPlate.push_back(Plate(&m_texturePlate, x, 70.f));
		switch (i)
		{
		case 0:
			m_vText.push_back(Text("Nguyen Duc Tai", m_fontScene, 25));
			break;
		case 1:
			m_vText.push_back(Text("Phan Ngoc Minh Tan", m_fontScene, 25));
			break;
		case 2:
			m_vText.push_back(Text("Tran Khanh Nhat", m_fontScene, 25));
			break;
		default:
			m_vText.push_back(Text("Who care about dev", m_fontScene, 25));
		}
		m_vText[i].setFillColor(sf::Color::Black);
		m_vText[i].setPosition(185, WINDOWS_H + 55*i);
	}
}


void SettingScene::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	window.draw(m_spritebuttonmenu);
	window.draw(m_spritebuttonmusic);
	window.draw(m_spritebuttoneffect);
	window.draw(m_textScene);
	for (size_t i = 0; i < m_vText.size(); i++)
	{
		window.draw(m_vText[i]);
	}
	m_mousePos = sf::Mouse::getPosition(window);

	/*sf::Image img;
	img.loadFromFile(TEXTURE_MC);
	img.createMaskFromColor(sf::Color(255, 255, 255, 255));
	Texture txt;
	txt.loadFromImage(img);
	Sprite sp;
	sp.setTexture(txt);
	window.draw(sp);*/


}
void SettingScene::Update(float dt, E & e) {
	for (size_t i = 0; i < m_vText.size(); i++)
	{
	//	sf::Vector2f m_Creidit_Flag = (170.f, WINDOWS_H / 6.f);
	//if(m_vText[i].getPosition)
		sf::Vector2f m_Creidit_Flag = m_vText[i].getPosition();
	if (m_Creidit_Flag.y<WINDOWS_H/6+40)
		{
			m_vText[i].setPosition(170, WINDOWS_H + 50);
		}
	else
			m_vText[i].move(0.f, -0.4f);
	}

	if (e == MOUSE_LEFT) {
		Mousedown();

	}

	if (e == MOUSE_LEFT_RELEASE) {
		Mouseup();
		
	}
		//if (e == MouseMoved)
		//{
		//	sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		//	if (m_spritebuttonmenu.getGlobalBounds().contains(mousePosF))//neu nut hinh co chua chuot
		//	{
		//		m_spritebuttonmenu.setColor(sf::Color::Green);
		//	}
		//	else
		//	{
		//		m_spritebuttonmenu.setColor(sf::Color(255, 255, 255));
		//	}
		//}
		if (is_start) {
			if (m_spritebuttonmenu.getScale().x < 1)
			{
				ScalespriteIn(m_spritebuttonmenu);

			}
			else
			{
				is_start = false;
			}
		}

	if (is_end) {
			is_start = false;
			t += dt;

			ScalespriteOut(m_spritebuttonmenu);

			if (t > 2)
			{
				m_music_Scene.stop();
				m_IsSwitch = true;
			}
		}
	}
	void SettingScene::Mouseup()
	{
		m_isMouseup = true;

		if (m_isMousedown)
		{
			sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
			if (m_spritebuttonmenu.getGlobalBounds().contains(mousePosF))
			{
				m_SoundEffect.play();
				Flag_Music = m_isMusicplay;
				Flag_Sound = m_isSoundplay;
				m_st = MENU;
				is_end = true;


				//to_string
			}
			else if (m_spritebuttonmusic.getGlobalBounds().contains(mousePosF))
			{
				m_SoundEffect.play();
				/*	t = 0;
				t += dt;
				if (t > 2);
				{*/
				if (m_isMusicplay)
				{
					m_music_Scene.setVolume(00);
					m_Texture_music.loadFromFile("../resources/texture/Button/BTNMusicDelete.png");
					m_spritebuttonmusic.setTexture(m_Texture_music);
					m_isMusicplay = false;
				}
				else
				{
					m_music_Scene.setVolume(50);
					m_Texture_music.loadFromFile("../resources/texture/Button/BTNMusic.png");
					m_spritebuttonmusic.setTexture(m_Texture_music);
					m_isMusicplay = true;
				}

				/*}*/
			}
			else if (m_spritebuttoneffect.getGlobalBounds().contains(mousePosF))
			{
				if (m_isSoundplay)
				{
					m_SoundEffect.setVolume(00);
					m_Texture_effect.loadFromFile("../resources/texture/Button/BTNSoundDelete.png");
					m_spritebuttoneffect.setTexture(m_Texture_effect);
					m_isSoundplay = false;
				}
				else
				{
					m_SoundEffect.setVolume(50);
					m_SoundEffect.play();
					m_Texture_effect.loadFromFile("../resources/texture/Button/BTNSound.png");
					m_spritebuttoneffect.setTexture(m_Texture_effect);
					m_isSoundplay = true;
				}
			}
		}
		m_isMousedown = false;
	}

	void SettingScene::Mousedown()
	{
		m_isMousedown = true;
		m_isMouseup = false;
	}
