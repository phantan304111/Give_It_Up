#include "stdafx.h"
#include "GameScene.h"

float time_e = 0;
float time_jump = 0;
float time_jump_down = 0;
sf::FloatRect rect_MC;
sf::FloatRect rect_Plate;
GameScene::GameScene()
{
}
GameScene::~GameScene()
{
}
void GameScene::Init() {
	ShowCoin();
	if (!m_SoundBufferEffect.loadFromFile(SoundHitJump) || !m_fontScene.loadFromFile(Fonttext))
	{
		std::cout << "ERROR" << std::endl;
	}
	else {
		m_SoundEffect.setBuffer(m_SoundBufferEffect);
		m_textScene.setFont(m_fontScene);
		m_textScene.setString(to_string(m_isScore) + "%");
		m_textScene.setFillColor(sf::Color::Black);
		m_textScene.setCharacterSize(100);
		m_textScene.setPosition(WINDOWS_W / 9 * 4 - 20, WINDOWS_H / 6 - 80);
	}
	m_texturePlate.loadFromFile(TEXTURE_COLUMM);
	m_texturePlate_2.loadFromFile(TEXTURE_COLUMMG);
//
	m_teturecol_1.loadFromFile(TEXTURE_COLUMM_1);
	m_teturecol_2.loadFromFile(TEXTURE_COLUMM_2);
	m_teturecol_3.loadFromFile(TEXTURE_COLUMM_3);
	m_textureFire.loadFromFile(TEXTURE_FIRE);
	m_Animation.loadFromFile(TEXTURE_ANIM);
	m_Texture_buttonMenu.loadFromFile(TEXTURE_BACKGROUNDBTNMenu);
	m_spirte_buttonMenu.setPosition(770, 20);
	m_spirte_buttonMenu.setTexture(m_Texture_buttonMenu);
	//
	float x = 200.f;

	int i = 0;
	switch (Flag_level)
	{
	case(0):
			myReadFile.open(Gamelevel1);
			
			if (myReadFile.is_open()) {
				while (!myReadFile.eof()) {
					myReadFile >> output[i];
					//cout << output;
					i++;
				}
			}
			myReadFile.close();
			if (!m_music_Scene.openFromFile(MusicGame))
			{
				cout << "error" << endl;
			}
			else
			{
				m_music_Scene.openFromFile(MusicGame);
				m_music_Scene.setVolume(70);
				//m_music_Scene.play();
				m_music_Scene.setLoop(true);
			}

			break;
	case(1):
		myReadFile.open(Gamelevel2);
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				myReadFile >> output[i];
				//cout << output;
				i++;
			}
		}
		myReadFile.close();
		if (!m_music_Scene.openFromFile(MusicGame2))
		{
			cout << "error" << endl;
		}
		else
		{
			m_music_Scene.setVolume(70);
			m_music_Scene.play();
			m_music_Scene.setLoop(true);
		}

		break;
	case(2):
		myReadFile.open(Gamelevel3);
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				myReadFile >> output[i];
				//cout << output;
				i++;
			}
		}
		myReadFile.close();
		if (!m_music_Scene.openFromFile(MusicGame3))
		{
			cout << "error" << endl;
		}
		else
		{
			m_music_Scene.setVolume(70);
			m_music_Scene.play();
			m_music_Scene.setLoop(true);
		}

		break;
	case(3):
		myReadFile.open(Gamelevel4);
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				myReadFile >> output[i];
				//cout << output;
				i++;
			}
		}
		myReadFile.close();
		if (!m_music_Scene.openFromFile(MusicGame4))
		{
			cout << "error" << endl;
		}
		else
		{
			m_music_Scene.setVolume(70);
			m_music_Scene.play();
			m_music_Scene.setLoop(true);
		}

		break;
	default:
		myReadFile.open(Gamelevel1);
		if (myReadFile.is_open()) {
			while (!myReadFile.eof()) {
				myReadFile >> output[i];
				//cout << output;
				i++;
			}
		}
		myReadFile.close();

			m_music_Scene.openFromFile(MusicGame);
			m_music_Scene.setVolume(70);
			m_music_Scene.play();
			m_music_Scene.setLoop(true);

		break;

	}
	//coin
	m_spriteCoin.setTexture(m_texttureCoin);
	m_spriteCoin.setPosition(0, 0);
	m_spriteGoldbag.setPosition(WINDOWS_W - 80, 0);
	m_texttureCoin.loadFromFile(TEXTURE_COIN);
	m_Texture_Goldbag.loadFromFile(TEXTURE_GoldBag);

	for (int i = 0; i < 8; i++) {

		if (output[Flag_line] == 0)
		{
			m_vPlate.push_back(Plate(&m_texturePlate, x, 375.f));
			m_vPlate[i].m_type = 0;
			m_vState.push_back(COLUMMLEVEL_0);
		}
		else if (output[Flag_line] == 1)
		{
			m_vPlate.push_back(Plate(&m_texturePlate, &m_teturecol_1, x));  // nhap dia vao chuoi dia
			m_vPlate[i].m_type = 1;
			m_vState.push_back(COLUMMLEVEL_1);
		}
		else
		{
			m_vPlate.push_back(Plate(&m_texturePlate, x, 375.f));
			m_vPlate[i].m_type = 0;
			m_vState.push_back(COLUMMLEVEL_0);
		}
	/*	}*/
		x += 100;// tang vi tri de nhap dia ke
		m_number++;
	}



	////////////////////////////////////////////////////



	if (!m_textureBackground.loadFromFile(TEXTURE_BACKGROUND))
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
		m_spirte_buttonMenu.setTexture(m_Texture_buttonMenu);
	}
	player->Init();
	switch (Flag_skin)
	{
	case 0:
		m_Textureskin.loadFromFile(Skin0);

		break;
	case 1:
		m_Textureskin.loadFromFile(Skin1);
		break;
	case 2:
		m_Textureskin.loadFromFile(Skin2);
		break;
	case 3:
		m_Textureskin.loadFromFile(Skin3);
		break;
	case 4:
		m_Textureskin.loadFromFile(Skin4);
		break;
	case 5:
		m_Textureskin.loadFromFile(Skin5);
		break;
	case 6:
		m_Textureskin.loadFromFile(Skin6);
		break;
	default:
		m_Textureskin.loadFromFile(Skin0);
		break;
	}

	player->m_spriteMC.setTexture(m_Textureskin);
	//

	if (Flag_Sound)
		m_SoundEffect.setVolume(100);
	else
		m_SoundEffect.setVolume(0);
	if (Flag_Music)
		m_music_Scene.setVolume(70);
	else
		m_music_Scene.setVolume(0);
	
	animation = new Animation(&m_Animation, Vector2u(4, 3), 0.07);
}
void GameScene::Render(RenderWindow &window) {
	//Background

	window.draw(m_spriteBackground);
	window.draw(m_textScene);
	window.draw(m_spirte_buttonMenu);
	for (size_t i = 0; i < m_vPlate.size(); i++) {//ve chuoi dia
		if (m_vPlate[i].m_type == 1||m_vPlate[i].m_type == 2|| m_vPlate[i].m_type == 3) {// neu thuoc loai tru 
			window.draw(m_vPlate[i].m_Col_1);//loai 1
			window.draw(m_vPlate[i].m_Col_2);

		}
		else {
			window.draw(m_vPlate[i].m_spritePlate);// khong thi xuat dia
		}
	}
	m_mousePos = sf::Mouse::getPosition(window);
	player->Render(window);
	window.draw(m_spriteCoin);
	window.draw(m_textcoin);
}
static float speed_player = 180.f;//toc do MC va chuoi dia
void GameScene::Update(float dt, E &e) {
	//cout << dt;
	if (e == MOUSE_LEFT_RELEASE) {

		Mouseup();

	}
	if (e == MOUSE_LEFT) {

		Mousedown();

	}
	if ((e == MOUSE_LEFT || e == SPACE) && !is_start) {// bat su kien click
		m_music_Scene.play();
		is_start = true;
		e = NO;
	}
	for (size_t i = 0; i < m_vPlate.size(); i++) {//loop vector chua dia:
												  //Distance = 100.f;//khoang cach giua 2 dia
		if (Collision::CircleTest(player->m_spriteMC, m_vPlate[i].m_spritePlate) && m_vPlate[i].m_type == 0) {//check va cham giua Mc va thanh phan cua vector : thanh phan nay chac chan la dia
			dir = -1;
			m_plate_current_x = m_vPlate[i].m_spritePlate.getPosition().x;
			if (!m_vPlate[i].is_colision)
				player->is_mc_jump = true;
			m_vPlate[i].is_colision = true;
			//m_mc_y1 = player->m_spriteMC.getPosition().y;
			//if(m_vPlate[i + 1].m_type == m_vPlate[i].m_type )// check type thanh phan cua vector hien tai va ke tiep co giong nhau
			//	Distance = m_vPlate[i + 1].m_spritePlate.getPosition().x - m_vPlate[i].m_spritePlate.getPosition().x;//neu dung: gan Bien Distance = khoan cach 2 dia
			//else if(m_vPlate[i + 1].m_type == 1)// check type thanh phan ke tiep co phai tru 1 ( dia -> tru 1)
			//	Distance = m_vPlate[i + 1].m_Col_2.getPosition().x - m_vPlate[i].m_spritePlate.getPosition().x; // neu dung : gan Bien Distance = khoan cach dia hien tai va tru 1 ke tiep
			if (m_vState[i] == COLUMMLEVEL_0 && (m_vState[i + 1] == FIRE) && !is_click && (e == MOUSE_LEFT || e == SPACE)) {//check truong hop, dia -> dia va chuot dang click (e == MOUSE_LEFT || e == SPACE)  m_vState[i + 1]= cl1
				is_click = true;//su kien click ( tang toc/nhay cao)
				time_e = 0;//set time su kien click tren = 0
		//		std::cout << "Vao click" << endl;
				/*if (abs(player->dy) > 400)
				player->dy /= 1.2;*/
				e = NO;// set su kien lai = khong co gi het
			}
			if (m_vState[i] == COLUMMLEVEL_0 && m_vState[i + 1] == COLUMMLEVEL_1 &&(e == MOUSE_LEFT || e == SPACE)) {//vat the thap -> vat the cao hon dung 1 bac(dia ->tru)
				is_jump_up = true;//chuyen nhay thuong thanh nhay cao
		//		std::cout << "Vao jump" << endl;
				e = NO;
			}
			if (m_vState[i] == COLUMMLEVEL_0) {// neu cai hien tai la dia trang ---> doi thanh dia mau xanh
				m_spirtePlate.setTexture(m_texturePlate_2);
				m_spirtePlate.setPosition(m_vPlate[i].m_spritePlate.getPosition().x, m_vPlate[i].m_spritePlate.getPosition().y);
				m_vPlate[i].m_spritePlate = m_spirtePlate;
			}
		}
		if (Collision::CircleTest(player->m_spriteMC, m_vPlate[i].m_Col_1) && (m_vPlate[i].m_type == 1 || m_vPlate[i].m_type == 2 || m_vPlate[i].m_type == 3)) {//check con MC voi cai dia tren cai tru hien tai (va cai hien tai dang la loai tru 1)
			dir = -1;
			m_plate_current_x = m_vPlate[i].m_Col_1.getPosition().x - 2;
			//Change green
			m_spirtePlate.setTexture(m_texturePlate_2);
			m_spirtePlate.setPosition(m_vPlate[i].m_Col_1.getPosition().x, m_vPlate[i].m_Col_1.getPosition().y);
			m_vPlate[i].m_Col_1 = m_spirtePlate;
			//=======================
			if (!m_vPlate[i].is_colision)
				player->is_mc_jump = true;
			m_vPlate[i].is_colision = true;
			//m_mc_y1 = player->m_spriteMC.getPosition().y;
			//std::cout << "collistion col" << endl;
			
			//if (m_vPlate[i + 1].m_type == m_vPlate[i].m_type) {//neu cai ke tiep cung la cái trụ
			//	Distance = m_vPlate[i + 1].m_Col_2.getPosition().x - m_vPlate[i].m_Col_2.getPosition().x;//tính khoảng cách giữa 2 trụ( de tinh van toc tru cho hop li
			//}
			//else if (m_vPlate[i + 1].m_type == 0) {// neu cai ke la dia
			//	Distance = m_vPlate[i + 1].m_spritePlate.getPosition().x - m_vPlate[i].m_Col_2.getPosition().x;//tính khoảng cách giữa tru hien tai va dia ke ben
			//	//cout << "Distance Down: " << Distance << endl;
			//}
			if ((m_vPlate[i + 1].m_type > m_vPlate[i].m_type) && (e == MOUSE_LEFT || e == SPACE)) {
				is_jump_up = true;//chuyen nhay thuong thanh nhay cao
			//	std::cout << "Vao jump" << endl;
				m_vPlate[i].is_colision_2 = true;
				e = NO;
			}
			if ((m_vPlate[i + 1].m_type < m_vPlate[i].m_type) && !m_vPlate[i].is_colision_2) {// neu cai ke la vat the thap hon cai tru hien tai(tru 1 -> dia	
				is_jump_down = true;
				time_jump_down = 0;
				player->Jump_down();
				player->Reset();
				m_vPlate[i].is_colision_2 = true;
				e = NO;
			}
		}
		if (Collision::CircleTest(player->m_spriteMC, m_vPlate[i].m_Col_2) || (Collision::CircleTest_2(player->m_spriteMC, m_vPlate[i].m_spritePlate) && m_vState[i] == FIRE))//check va cham giua MC va cot
		{
			cout << " player die" << endl;//player chet
			is_end = true;
			//system("pause");
		}

	}

	if (is_start) {//bat dau, bat dau nhay
		player->Update(dt);
		if (is_jump_up) {//MC dang trong trang thai move len (tu nhay thuong -> nhay cao)
						 //player->m_spriteMC.move(0.f, -70);//su kien nhay cao(chua lam)
			time_jump += dt;
			if (Flag_level == 0)
				player->Jump(-70.f);
			else if (Flag_level == 1)
				player->Jump(-70.f);
			else if (Flag_level == 2) {
				player->Jump(-70.f);
			}
		}
		if (time_jump >= 0.02) {//level 1 0.02
			player->Reset();
			is_jump_up = false;
			time_jump = 0;

		}

		//if (!is_jump_up) {//neu khong phai nhay cao
		//	if (player->m_spriteMC.getPosition().y <= 300 + change_st) {// neu vi tri hien tai<300 + change_st(MC dang di xuong va cham moc duoi)
		//		dir = 1;//dir la trang thai hien tai ( len/xuong )
		//		m_SoundEffect.play();
		//		if (m_isScore < 100)
		//		{
		//			m_isScore++;
		//			m_textScene.setString(to_string(m_isScore) + "%");
		//		}

		//		m_mc_y2 = player->m_spriteMC.getPosition().y;//lay vi tri y cua MC
		//	}
		//}
		/*if (is_jump_up) {
		velocity1 = 100 / (player->t2)*dt + 0.08;
		}*/
		if (Flag_level == 0) {
			//cout << "level 0" << endl;
			velocity1 = 100 / (player->t2)*dt + 0.05;
			velocity1 += (m_plate_current_x - 300) / 10 * 0.52;
			if (velocity1 < 3) {//level 1 3.3 
				velocity1 = 3;
			}
		}
		else if (Flag_level == 1) {
			velocity1 = 100 / (player->t2)*dt + 0.05;
			velocity1 += (m_plate_current_x - 300) / 10 * 0.5;
			if (velocity1 < 3.4) {//level 1 3.3 
				velocity1 = 3.4;
			}
		}
		else if (Flag_level == 2) {
			//cout << "level " << Flag_level << endl;
			velocity1 = 100 / (player->t2)*dt + 0.05;

		//	cout << " x plate " << m_plate_current_x << endl;
			velocity1 += (m_plate_current_x - 300) / 10 * 0.52;
			if (velocity1 < 3) {//level 1 3.3 
				velocity1 = 3;
			}
		}
		if (is_jump_down) {
			//cout << " vao jum down game sene" << endl;
			player->Jump_down();
			time_jump_down += dt;
			if (m_plate_current_x - 300 > 20) {
				velocity1 += 0.8;
				
			}
		}
		if (time_jump_down >= 0.02) {
			player->Reset();
			
			time_jump_down = 0;
			is_jump_down = false;
		}
	//	cout << "velocity1 =" << velocity1 << endl;
		// van toc con MC, dung cho ham tang toc nhay khi click
		if (m_fPlateSpawnTimer < 100) {
			if (is_click) {

				m_fPlateSpawnTimer += 1.f * 2 * velocity1;

			}
			else {

				m_fPlateSpawnTimer += 1.f * velocity1;
			}
		}
		//Plate spawn
		if (m_fPlateSpawnTimer >= 100)
		{	
			if (Flag_line < 110) {
				cout << m_isScore;
				switch (output[Flag_line])
				{
				case 0:

					m_vPlate.push_back(Plate(&m_texturePlate, WINDOWS_W, 380.f));
					m_vState.push_back(COLUMMLEVEL_0);
					break;
				case 1:
					m_vPlate.push_back(Plate(&m_texturePlate, &m_teturecol_1, WINDOWS_W));  // nhap dia vao chuoi dia
					m_vState.push_back(COLUMMLEVEL_1);
					break;
				case 2:

					m_vPlate.push_back(Plate(&m_texturePlate, &m_teturecol_2, WINDOWS_W, 200, 230, 2));  // nhap dia vao chuoi dia
																										 //m_vPlate[Flag_line].m_Col_1.move(-2, 0);
					m_vState.push_back(COLUMMLEVEL_2);
					break;
					/*	else if (output[Flag_line] == NULL)
					{
					m_vPlate.push_back(Plate(&m_texturePlate, WINDOWS_W, 375.f));
					m_vState.push_back(COLUMMLEVEL_0);
					}*/
				case 3:
					//m_vPlate.push_back(Plate(&m_texturePlate, &m_teturecol_3, WINDOWS_W, 110, 90, 3));  // nhap dia vao chuoi dia

					m_vPlate.push_back(Plate(&m_texturePlate, &m_teturecol_3, WINDOWS_W, 120, 97, 3));  // nhap dia vao chuoi dia

					m_vState.push_back(COLUMMLEVEL_3);
					break;
				case 4:

					m_vPlate.push_back(Plate(&m_textureFire, WINDOWS_W, 380.f));
					m_vState.push_back(FIRE);
					break;
				case 5:
					m_vPlate.push_back(Plate(&m_textureFire, &m_teturecol_1, WINDOWS_W));  // nhap dia vao chuoi dia
					m_vState.push_back(COLUMMLEVEL_1_FIRE);
					break;
				case 6:

					m_vPlate.push_back(Plate(&m_textureFire, &m_teturecol_2, WINDOWS_W, 200, 230, 2));  // nhap dia vao chuoi dia
																										 //m_vPlate[Flag_line].m_Col_1.move(-2, 0);
					m_vState.push_back(COLUMMLEVEL_2_FIRE);
					break;
				default:

					m_vPlate.push_back(Plate(&m_texturePlate, WINDOWS_W, 380.f));
					m_vState.push_back(COLUMMLEVEL_0);
					break;
				}

			}
			else
			{
				m_vPlate.push_back(Plate(&m_texturePlate, WINDOWS_W, 375.f));
				m_vState.push_back(COLUMMLEVEL_0);
			}
			/*	cout << Flag_line;
			cout << output[Flag_line];*/
			Flag_line++;
			m_number++;
			m_fPlateSpawnTimer = 0;

			m_isScore++;
			if (m_isScore < 101)
						{
							m_textScene.setString(to_string(m_isScore) + "%");
						}
			else {
				is_won = true;
				is_end = true;
			}
		/*	if (m_isScore >20 )
			{
				cout << "you win ";
			}*/
		}
		//Plate move

		for (size_t i = 0; i < m_vPlate.size(); i++)
		{
			if (is_click) {//í click = dang nhay nhanh


						   //m_vPlate[i].m_spritePlate.move(-1.f * dt * 4 * dtMultiplier, 0.f);--khoa
				if (m_vPlate[i].m_type == 1 || m_vPlate[i].m_type == 2 || m_vPlate[i].m_type == 3) {
					m_vPlate[i].m_Col_1.move(-1.f * 2 * velocity1, 0.f);
					m_vPlate[i].m_Col_2.move(-1.f * 2 * velocity1, 0.f);
				}

				else {
					//cout << "vao" << endl;
					m_vPlate[i].m_spritePlate.move(-1.f * 2 * velocity1, 0.f);

				}
				time_e += dt;

				//cout << time_e << endl;
			}
			else {
				//m_vPlate[i].m_spritePlate.move(-1.f * dt * dtMultiplier, 0.f);---khoa
				//cout << "v=  " << velocity1 << endl;
				if (m_vPlate[i].m_type == 1 || m_vPlate[i].m_type == 2 || m_vPlate[i].m_type == 3) {
					//cout << "col 1 move" << endl;
					m_vPlate[i].m_Col_1.move(-1.f * velocity1, 0.f);
					m_vPlate[i].m_Col_2.move(-1.f * velocity1, 0.f);
				}
				//////////////////////////////////////////////

				///////////////////////////////////
				else
				{
					m_vPlate[i].m_spritePlate.move(-1.f * velocity1, 0.f);
				}
			}
			if (time_e > (player->t2 * 10) + 0.05)
			{
			//	cout << "time e= " << player->t2 * 10 << endl;
				is_click = false;
				time_e = 0;
			}

			if ((m_vPlate[i].m_type == 1 || m_vPlate[i].m_type == 2 || m_vPlate[i].m_type == 3) && m_vPlate[i].m_Col_2.getPosition().x <= 0 - m_vPlate[i].m_spritePlate.getGlobalBounds().width + 20) {
				m_vPlate.erase(m_vPlate.begin() + i);
				m_vState.erase(m_vState.begin() + i);
				break;
			}
			else if (m_vPlate[i].m_type == 0 && m_vPlate[i].m_spritePlate.getPosition().x <= 0 - m_vPlate[i].m_spritePlate.getGlobalBounds().width)
			{
				m_vPlate.erase(m_vPlate.begin() + i);
				m_vState.erase(m_vState.begin() + i);
				break;
			}
		}
	}


	//khi playerchet
	/*is_end = true;*/
	if (is_end) {
		player->m_spriteMC.setTexture(m_Animation);
		animation->Update(0, dt);
		player->m_spriteMC.setTextureRect(animation->uvRect);
		is_start = false;
		time_dead += dt;
		if (time_dead > 2.7f)
		{ 
			if (is_won)
			{
				m_st = Win;
				m_music_Scene.stop();
				m_IsSwitch = true;
				//time_dead = 0;
				delete animation;
			}
			else
			{
				m_st = GAMEOVER;
				m_music_Scene.stop();
				m_IsSwitch = true;
				delete animation;
			}
		}
	}
}

void GameScene::Mouseup()
{
	m_isMouseup = true;

	if (m_isMousedown)
	{
		sf::Vector2f mousePosF(static_cast<float>(m_mousePos.x), static_cast<float>(m_mousePos.y));
		if (m_spirte_buttonMenu.getGlobalBounds().contains(mousePosF))
		{
			//su kien goi lai game scene
			m_st = MENU;
			m_SoundEffect.play();
			m_IsSwitch = true;
			
		}

	}
	m_isMousedown = false;
}
void GameScene::Mousedown()
{
	m_isMousedown = true;
	m_isMouseup = false;
}