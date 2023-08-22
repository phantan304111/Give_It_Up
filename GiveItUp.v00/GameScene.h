#pragma once
#include "Scene.h"
#include "mc.h"
#include "Plate.h"
#include "Collision.h"
#include "Animation.h"
class GameScene:public Scene
{
public:
	GameScene();
	~GameScene();
	void Init()override;
	void Update(float dt, E &e) override;
	void Render(RenderWindow &window)override;
	void Mouseup() override;
	void Mousedown() override;
private:
	int m_isScore;
	float m_speed; 



	int m_number = 0;
	float m_mc_x = MC_X;
	mc* player = new mc();
	std::vector<Plate> m_vPlate;
	float m_fPlateSpawnTimer = 0.f;
	Plate* pt;
	sf::Texture m_texturePlate;
	sf::Texture m_texturePlate_2;
	sf::Texture m_teturecol_1;
	sf::Texture m_teturecol_2;
	sf::Texture m_teturecol_3;
	sf::Sprite m_spirtePlate;
	sf::Texture m_textureFire;
	sf::Event ev;
	bool is_jump_up = false;
	bool is_jump_down = false;
	int v = 100;
	int v2 = 100;
	int dir = -1;

	float t = 0;
	std::vector<State_Columm> m_vState;
	State_Columm en_st = COLUMMLEVEL_0;
	int change_st = 0;
	bool is_jump = false;
	float velocity1 = 0, velocity2 = 0; // van toc mc , plate
	float Distance = 0;//khoang canh 2 dia
	float m_mc_y1 = 0, m_mc_y2 = 300;

	float vtru = 90.f;
	//
	sf::Texture m_Texture_buttonMenu;
	sf::Sprite m_spirte_buttonMenu;
	sf::Texture m_Textureskin;
	ifstream myReadFile;
	int output[110];
	int Flag_line = 0;
	float time_dead = 0;
	float m_plate_current_x;
	bool is_won = 0;
	bool m_isMousedown = false;
	bool m_isMouseup = true;
	Texture m_Animation;
	Animation* animation;
	//
//	float v2 = 90.f;


};

