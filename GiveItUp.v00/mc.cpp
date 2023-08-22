#include "stdafx.h"
#include "mc.h"

mc::mc()
{
}


mc::~mc()
{
}
void mc::Init() {
	dy = 400;
	gravity = 0.5;
	if (!m_textureMC.loadFromFile(TEXTURE_MC))
		cout << "erorr load" << endl;
	else {
		m_spriteMC.setTexture(m_textureMC);
		m_spriteMC.setScale(0.5, 0.5);
		m_spriteMC.setPosition(MC_X, MC_Y);
	}
}
void mc::Update(float dt) {
	t1 += dt;
	y = m_spriteMC.getPosition().y;
	x = m_spriteMC.getPosition().x;
	//cout << "max_height main = " << max_height<<endl;
	if (is_mc_jump)//y + radius >= max_height && y + radius < max_height + 10
	{
		t2 = t1;
		//cout<< " t2 === " << t2 << endl;
		if (t2 < 0.2 || t2 > 0.7)//level 1 0.7
			t2 = 0.5;

		t1 = 0;
		dy = -dy;
		is_mc_jump = false;
	}
	else
	{
		dy += gravity / dt;
	}
	if (abs(dy*dt) > 7) {
		if (dy*dt < 0)
			dy = -7.f / dt;
		else {
			dy = 7.f / dt;
		}
	}
	y += dy*dt + h;

	//cout << " dy*dt" << dy*dt << endl;

	m_spriteMC.setPosition(x, y);
}
void mc::Jump(float height) {
	//cout << "vao ham jump" << endl;
	h = height;//-60
	max_height -= 45;
	//cout << " dy === jump up " << dy << endl;
}
void mc::Reset() {
	h = 0;
}
void mc::Jump_down() {
	h = 10;
	//cout << "====================" << h << endl;
	//cout << " dy  " << dy << endl;
	////dy /= 10;
	//cout << " dy down " << dy << endl;
	//cout << "jump down max hieght= " << max_height;
	//cout << "====================" << endl;
}
void mc::Render(RenderWindow &window) {
	window.draw(m_spriteMC);
}

