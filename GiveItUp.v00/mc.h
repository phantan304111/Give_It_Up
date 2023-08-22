#pragma once
#include "define.h"
class mc
{
private:
	sf::Texture m_textureMC;
	
	float radius = 0;
	float gravity;
	float y;
	float x;
	float t1 = 0;
public:
	mc();
	~mc();
	void Init();
	void Update(float dt);
	void Render(RenderWindow &window);
	void Jump(float height);
	void Reset();
	void Jump_down();
	sf::Sprite m_spriteMC;
	float max_height = 350.f;
	float h = 0;
	float k = 0;
	float dy;
	bool is_mc_jump = false;
	float t2 = 0.5;
	
};
