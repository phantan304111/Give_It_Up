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

	//
	//sf::Texture m_textureBackground;



	//

	//int m_isScore;
	//float m_speed;
	//mc* player = new mc();
	//std::vector<Plate> m_vPlate;
	//float m_fPlateSpawnTimer = 0.f;
	//Plate* pt;
	//sf::Texture m_texturePlate;
	//sf::Texture m_texturePlate_2;
	//sf::Event ev;
	//bool is_jump_up = false;
	//bool is_jump_down = false;
	//int v = 100;
	//int v2 = 100;
//	int dir = -1;
	bool is_start = false;
	//float t = 0;
	//std::vector<State_Columm> m_vState;


	int m_animationtime = 100;
	bool is_end = false;

};

