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
	
	m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDLOAD);
	float x = 55.f;

	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUNDLOAD))
	{
		cout << "error" << endl;
	}
	else {

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


	if (is_start) {

		//animation

		{

		}
	}
		//end


		if (is_end) {
			//animation

			{

			}
		}
}