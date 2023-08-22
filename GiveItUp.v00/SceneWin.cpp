#include "stdafx.h"
#include "SceneWin.h"

SceneWin::SceneWin()
{
}


SceneWin::~SceneWin()
{
}
void SceneWin::Init() {
	//
	t = 0;
	is_start = true;
	//coin
	ShowCoin();

	//
	if (!m_SoundBufferEffect.loadFromFile(SoundButton) || !m_fontScene.loadFromFile(Fonttext))
	{
		std::cout << "ERROR" << std::endl;
	}
	else {

		m_SoundEffect.setBuffer(m_SoundBufferEffect);

		//if (Flag_Sound)
		//	m_SoundEffect.setVolume(100);
		//else
		//	m_SoundEffect.setVolume(0);

		m_textScene.setFont(m_fontScene);
		m_textScene.setString("congratulation!!!");
		m_textScene.setFillColor(sf::Color::Black);
		m_textScene.setCharacterSize(40);
		m_textScene.setPosition(WINDOWS_W / 9 * 2, WINDOWS_H / 5-50);

		m_Textwon.setFont(m_fontScene);
		m_Textwon.setString("Your jump skill is amazing!");
		m_Textwon.setFillColor(sf::Color::Black);
		m_Textwon.setCharacterSize(40);
		m_Textwon.setPosition(WINDOWS_W / 9 * 2-100, WINDOWS_H / 5);
	}
	if (!m_music_Scene.openFromFile(MusicGameOver))
	{
		cout << "error" << endl;
	}
	else
	{
		m_music_Scene.openFromFile(MusicGameOver);

		/*if (Flag_Music)
		m_music_Scene.setVolume(70);
		else
		m_music_Scene.setVolume(0);*/
		m_music_Scene.play();
		m_music_Scene.setLoop(true);

	}


	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDGAMEOver))
	{
		cout << "error" << endl;
	}
	else {
		//
		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDGAMEOver);
		m_Texture_buttonReplay.loadFromFile(TEXTURE_BACKGROUNDBTNReplay);
		m_Texture_buttonPlay.loadFromFile(TEXTURE_BACKGROUNDBTNPlay);
		m_Texture_buttonMenu.loadFromFile(TEXTURE_BACKGROUNDBTNMenu);
		m_Texture_MC.loadFromFile(TEXTURE_MC);
		//
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);


		//btnreplay

		m_spritebuttonMenu.setPosition(float(WINDOWS_W-80), float(WINDOWS_H / 6));
		m_spritebuttonReplay.setPosition(float(WINDOWS_W / 9 * 6), float(WINDOWS_H / 6 * 5-30));
		m_spritebuttonPlay.setPosition(float(WINDOWS_W / 9 * 3), float(WINDOWS_H / 6 * 5-30));
		m_spriteMC.setPosition(float(WINDOWS_W / 9 * 4-30), float(WINDOWS_H / 6 *2+20));


		m_spritebuttonReplay.setTexture(m_Texture_buttonReplay);
		m_spritebuttonPlay.setTexture(m_Texture_buttonPlay);
		m_spritebuttonMenu.setTexture(m_Texture_buttonMenu);
		m_spriteMC.setTexture(m_Texture_MC);
		//
		m_spritebuttonReplay.scale(sf::Vector2f(float(0.001), float(0.001)));
		m_spritebuttonMenu.scale(sf::Vector2f(float(0.001), float(0.001)));
		m_spritebuttonPlay.scale(sf::Vector2f(float(0.001), float(0.001)));
		//

		m_spriteBackground.setScale(ScaleX, ScaleY);
	}
	if (Flag_Sound)
		m_SoundEffect.setVolume(100);
	else
		m_SoundEffect.setVolume(0);
	if (Flag_Music)
		m_music_Scene.setVolume(70);
	else
		m_music_Scene.setVolume(0);
}


void SceneWin::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	window.draw(m_textScene);
	window.draw(m_spritebuttonReplay);
	window.draw(m_spritebuttonMenu);
	window.draw(m_spritebuttonPlay);
	window.draw(m_spriteCoin);
	window.draw(m_textcoin);
	window.draw(m_Textwon);
	window.draw(m_spriteMC);
	m_mousePos = sf::Mouse::getPosition(window);

}


void SceneWin::Update(float dt, E & e) {
	//m_spriteMC.setRotation(10);
	if (e == MOUSE_LEFT) {

		Mousedown();

	}
	if (e == MOUSE_LEFT_RELEASE) {

		Mouseup();

	}
	if (is_start) {
		if (m_spritebuttonReplay.getScale().x < 1)
		{
			ScalespriteIn(m_spritebuttonMenu);
			ScalespriteIn(m_spritebuttonReplay);
			ScalespriteIn(m_spritebuttonPlay);
		}
		else
		{
			is_start = false;
		}
	}
	if (is_end) {
		is_start = false;
		t += dt;
		ScalespriteOut(m_spritebuttonMenu);
		ScalespriteOut(m_spritebuttonReplay);
		ScalespriteOut(m_spritebuttonPlay);
		if (t > 2)
		{
			m_music_Scene.stop();
			m_IsSwitch = true;
		}
	}

}
void SceneWin::Mouseup()
{
	m_isMouseup = true;

	if (m_isMousedown)
	{
		sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		if (m_spritebuttonReplay.getGlobalBounds().contains(mousePosF))
		{
			//su kien goi lai game scene
			m_st = GAMEPLAY;
			is_end = true;
			m_SoundEffect.play();
		}
		else if (m_spritebuttonMenu.getGlobalBounds().contains(mousePosF))
		{
			m_st = MENU;
			is_end = true;
			m_SoundEffect.play();

		}
		else if (m_spritebuttonPlay.getGlobalBounds().contains(mousePosF))
		{
			//su kien
			if (Flag_level < 4)
			Flag_level++;
			m_st = GAMEPLAY;
			is_end = true;
			m_SoundEffect.play();

		}
	}
	m_isMousedown = false;
}
void SceneWin::Mousedown()
{
	m_isMousedown = true;
	m_isMouseup = false;
}