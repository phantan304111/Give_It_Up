#include "stdafx.h"
#include "SkinScene.h"
SkinScene::SkinScene()
{
}


SkinScene::~SkinScene()
{
}
void SkinScene::Init() {
	is_start = true;
	m_IsSwitch = false;
	ShowCoin();


	if (!m_SoundBufferEffect.loadFromFile(SoundButton) || !m_fontScene.loadFromFile(Fonttext)||!m_music_Scene.openFromFile(MusicSceneSkin))
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
		m_textScene.setString("Choice your Bible!!");
		m_textScene.setFillColor(sf::Color::Black);
		m_textScene.setCharacterSize(40);
		m_textScene.setPosition(WINDOWS_W /3-40, 10);
		m_music_Scene.play();
		m_music_Scene.setLoop(true);
	}

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU))
	{
		cout << "error" << endl;
	}
	else {

		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDMENU);
		m_Texture_buttonBuy.loadFromFile(TEXTURE_BACKGROUNDBTNBuy);
		m_Texture_buttonSelect.loadFromFile(TEXTURE_BTNSelect);
		m_TextureFlag.loadFromFile(TEXTURE_Arrow);
		//m_textureminiMC.loadFromFile(TEXTURE_MC);
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);


		m_texttureCoin.loadFromFile("../resources/texture/Coin.png");
		m_Texture_Goldbag.loadFromFile("../resources/texture/Goldbag.png");


		sf::Vector2u play = m_Texture_buttonBuy.getSize();
		sf::Vector2u play2 = m_Texture_buttonSelect.getSize();
		//m_spritebuttonplay.setPosition(WINDOWS_W / 18 * 4 - play.x / 2, WINDOWS_H / 6 * 5 - play.y / 2);
		m_spritebuttonBuy.setPosition(WINDOWS_W / 9*3-25, WINDOWS_H / 6 * 5);
		m_spritebuttonSelect.setPosition(WINDOWS_W / 9 * 6 - 25, WINDOWS_H / 6 * 5-30);


		m_spritebuttonBuy.setTexture(m_Texture_buttonBuy);
		m_spritebuttonSelect.setTexture(m_Texture_buttonSelect);
		m_spriteBackground.setScale(ScaleX, ScaleY);
		m_spritebuttonSelect.scale(sf::Vector2f(0.0015f, 0.0015f));
		m_spritebuttonBuy.scale(sf::Vector2f(0.0015f, 0.0015f));

	m_skintexture0.loadFromFile(Skin0);
    m_skintexture1.loadFromFile(Skin1);
	m_skintexture2.loadFromFile(Skin2);
	m_skintexture3.loadFromFile(Skin3);
	m_skintexture4.loadFromFile(Skin4);
	m_skintexture5.loadFromFile(Skin5);
	m_skintexture6.loadFromFile(Skin6);

		for (int i = 0; i < 8; i++) {
			m_vSkin.push_back(Skin(100+i*100, 70.f));
			switch (i)
			{
			case 0:
				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture0);
				m_vSkin[i].m_textskin.setFont(m_fontScene);
;
				m_vSkin[i].m_textskin.setString("BiBle");
			
				break;
			case 1:

				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture1);
				m_vSkin[i].m_textskin.setString("Bilien");
				break;
			case 2:

				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture2);
				m_vSkin[i].m_textskin.setString("Maria");
				break;
			case 3:

				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture3);
				m_vSkin[i].m_textskin.setString("Furry");
				break;
			case 4:

				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture4);
				m_vSkin[i].m_textskin.setString("BigBob");
				break;
			case 5:
				m_vSkin[i].m_spriteSkin.setTexture(m_skintexture5);
				m_vSkin[i].m_textskin.setString("Jimmy");
				break;
				case 6:
					m_vSkin[i].m_spriteSkin.setTexture(m_skintexture6);
					m_vSkin[i].m_textskin.setString("Robert");
				break;
				default:
					break;
			}
			m_vSkin[i].m_textskin.setFont(m_fontScene);
			m_vSkin[i].m_textskin.setFillColor(sf::Color::Black);
			m_vSkin[i].m_textskin.setCharacterSize(20);
			m_vSkin[i].m_textskin.setPosition(100 + i * 100, 130.f);
			m_vSkin[i].m_spriteSkin.setScale(0.4, 0.4);
		
		}
	}
	/*m_spriteFlag.setTexture(m_TextureFlag);
	m_spriteFlag.setPosition(100 + Flag_skin * 100 , 20);
	m_spriteFlag.setScale(0.08, 0.08);*/
}


void SkinScene::Render(RenderWindow &window) {
	//Background
	window.draw(m_spriteBackground);
	window.draw(m_spritebuttonBuy);
	window.draw(m_spritebuttonSelect);
	window.draw(m_textScene);
	window.draw(m_spriteFlag);
	window.draw(m_spriteCoin);
	window.draw(m_textcoin);
	for (size_t i = 0; i < m_vSkin.size(); i++)
	{
		window.draw(m_vSkin[i].m_spriteSkin);
		window.draw(m_vSkin[i].m_textskin);
	}
	m_mousePos = sf::Mouse::getPosition(window);


}
void SkinScene::Update(float dt, E & e) {

	if (e == MOUSE_LEFT)
		Mousedown();
	if (e == MOUSE_LEFT_RELEASE) {
		Mouseup();

	}
	if (e == MouseMoved)
	{
		sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		//if (m_spritebuttonBuy.getGlobalBounds().contains(mousePosF))//neu nut hinh co chua chuot
		//{
		//	m_spritebuttonBuy.setColor(sf::Color::Green);
		//}
		 if (m_spritebuttonSelect.getGlobalBounds().contains(mousePosF))
		{
			m_spritebuttonSelect.setColor(sf::Color::Green);
		}
		/*else if (m_spritebuttonSelect.getGlobalBounds().contains(mousePosF))
		{
			m_spritebuttonSelect.setColor(sf::Color::Green);
		}*/

		//m_vPlate[i].m_spritePlate.setColor(sf::Color(255, 255, 255));
		else
		{
		//	m_spritebuttonBuy.setColor(sf::Color(255, 255, 255));
			m_spritebuttonSelect.setColor(sf::Color(255, 255, 255));
		}
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

void SkinScene::Mouseup()
{
	m_isMouseup = true;

	if (m_isMousedown)
	{
		sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		m_isMouseClick = false;
		if (m_spritebuttonBuy.getGlobalBounds().contains(mousePosF))
		{
			if (Coin >= 50)
			{
				Coin -= 50;
				m_textcoin.setString(to_string(Coin));
			}
		}
		else if (m_spritebuttonSelect.getGlobalBounds().contains(mousePosF))
		{
			is_end = true;
			m_st = MENU;
			m_SoundEffect.play();



		}
		for (int i = 0; i < m_iSkinnumber; i++)
		{
			if (m_vSkin[i].m_spriteSkin.getGlobalBounds().contains(mousePosF))
			{
				sf::Vector2f pos = m_vSkin[i].m_spriteSkin.getPosition();
				m_spriteFlag.setTexture(m_TextureFlag);
				m_spriteFlag.setPosition(pos.x + 10, 20);
				m_spriteFlag.setScale(0.08, 0.08);
				for (int i = 0; i < m_iSkinnumber; i++)
				{
					m_vSkin[i].m_spriteSkin.setColor(sf::Color::White);
				}
				m_vSkin[i].m_spriteSkin.setColor(sf::Color::Green);
				Flag_skin = i;
			}
		}
	}
	m_isMousedown = false;
}

void SkinScene::Mousedown()
{
	m_isMousedown = true;
	m_isMouseup = false;
}
