#pragma once
#include "Scene.h"
#include "GameScene.h"
#include "GameManagerState.h"
//int Coin = 0;
//int Flag_level = 0;
//int Flag_skin = 0;
//int Music_volumn = 50;
class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;
	static SceneManager* GetInstance();
	void Update(float deltime,E &e);
	void Render(sf::RenderWindow &window);
	void Init();

	Scene* GetCurrentScene();
	//
	int Flag_skin = 0;
	int Flag_level = 0;
	int Coin = 0;
	bool Flag_Music = true;
	bool Flag_Sound = true;
	//
private:
	static SceneManager* m_pInstance;
	Scene *m_sCurrentScene;
	Scene *m_sNewScene;
};

