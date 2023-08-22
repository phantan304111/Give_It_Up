#pragma once
#include "stdafx.h"
#include "GameScene.h"
//
#include "GameLoading.h"
//

//

GameLoading::GameLoading()
{
}


GameLoading::~GameLoading()
{
}
void GameLoading::Init()

{
	
	if (!m_SoundBufferLoad.loadFromFile(Loading))
	{
		std::cout << "ERROR" << std::endl;
	}
	else {

		m_SoundLoad.setBuffer(m_SoundBufferLoad);
		m_SoundLoad.setVolume(100);
		m_SoundLoad.play();

	}
	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDLOAD))
	{
		cout << "error" << endl;
	}
	else {
		m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDLOAD);
		m_vecTextureSize = m_textureBackground.getSize();
		m_vecWindowSize = sf::Vector2u(WINDOWS_W, WINDOWS_H);
		float ScaleX = (float)m_vecWindowSize.x / m_vecTextureSize.x;
		float ScaleY = (float)m_vecWindowSize.y / m_vecTextureSize.y;
		m_spriteBackground.setTexture(m_textureBackground);
		m_spriteBackground.setScale(ScaleX, ScaleY);
	}

}
void GameLoading::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	is_start = true;
	//
}
void GameLoading::Update(float dt, E &e) {
	float dtMultiplier = 64.5f;

	t += dt;
	if (is_start) {

		//animation

		
			if (t >= 3)
			{
				m_st = MENU;
				m_IsSwitch = true;
			}
		
	}
		//end


		if (is_end) {
			//animation

			{

			}
		}
}