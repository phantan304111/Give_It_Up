#include "stdafx.h"
#include "SceneManager.h"
#include "MenuScene.h"
#include "Scene_Over.h"
#include "GameLoading.h"
#include "SkinScene.h"
#include "SettingScene.h"
#include "SceneWin.h"
#include "SceneBuy.h"
SceneManager* SceneManager::m_pInstance = NULL;
State st = GameManagerState::getInstance()->getState();
SceneManager* SceneManager::GetInstance() {
	if (m_pInstance == NULL)
		m_pInstance = new SceneManager();
	return m_pInstance;
}
SceneManager::SceneManager()
{
}
SceneManager::~SceneManager()
{
	if (m_pInstance != NULL)
		delete SceneManager::GetInstance()->m_pInstance;
	SceneManager::GetInstance()->m_pInstance = 0;
}
Scene* SceneManager::GetCurrentScene() {
	return m_sCurrentScene;
}
void SceneManager::Init() {
	st = LOGO;
	m_sCurrentScene = new GameLoading();
	m_sCurrentScene->Init();
	




}
void SceneManager::Render(sf::RenderWindow &window) {
	m_sCurrentScene->Render(window);
}
void SceneManager::Update(float deltime,E &e) {
	//cout << st;


	if (m_sCurrentScene->m_IsSwitch)   
	{

		cout << "doi state" << endl;
		//
		st = m_sCurrentScene->m_st;
		Flag_skin = m_sCurrentScene->Flag_skin;
		Flag_level = m_sCurrentScene->Flag_level;
		Coin = m_sCurrentScene->Coin;
		Flag_Music = m_sCurrentScene->Flag_Music;
		Flag_Sound = m_sCurrentScene->Flag_Sound;
			//
		cout << st << endl;
		switch (st)
		{
		case LOGO:
			m_sNewScene = new GameLoading();
			m_sCurrentScene = m_sNewScene;
			m_sCurrentScene->Init();
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//

			break;
		case LOADING:
	

			break;
		case MENU:
			
			m_sNewScene = new MenuScene();	
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin; 
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			m_sCurrentScene->Init();
			//
			
			//

			
			break;
		case GAMEPLAY:
			m_sNewScene = new GameScene();
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();
			break;
		case GAMEOVER:
			
			m_sNewScene = new OverScene();
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();

			break;
		case SKIN:

			m_sNewScene = new SkinScene();
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();

			break;
		case SETTING:

			m_sNewScene = new SettingScene();
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();
			break;
		case Win:
				m_sNewScene = new SceneWin();
				m_sCurrentScene->~Scene();
				m_sCurrentScene = m_sNewScene;
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();
			break;
		case Buy:

			m_sNewScene = new SceneBuy();
			m_sCurrentScene->~Scene();
			m_sCurrentScene = m_sNewScene;
			//
			m_sCurrentScene->Flag_skin = Flag_skin;
			m_sCurrentScene->Coin = Coin;
			m_sCurrentScene->Flag_level = Flag_level;
			m_sCurrentScene->Flag_Music = Flag_Music;
			m_sCurrentScene->Flag_Sound = Flag_Sound;
			//
			m_sCurrentScene->Init();
			break;
		default:
			break;
		}
	}
	//
	m_sCurrentScene->Update(deltime, e);
}

