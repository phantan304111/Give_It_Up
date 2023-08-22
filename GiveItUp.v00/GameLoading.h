#pragma once
#include "Scene.h"
#include "mc.h"
#include "Plate.h"
class GameLoading :public Scene
{
public:
	GameLoading();
	~GameLoading();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
private:

	
	bool is_start = false;
	int m_animationtime = 100;
	bool is_end = false;
	sf::Sound m_SoundLoad;
	sf::SoundBuffer m_SoundBufferLoad;
};

