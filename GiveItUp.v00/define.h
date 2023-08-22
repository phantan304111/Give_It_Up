#pragma once
#include <math.h>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <iostream>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
using namespace std;

//Window
#define WINDOWS_W	900
#define WINDOWS_H	600
#define FPS_LIMIT	60

//GameScene
#define MC_X 300
#define MC_Y 350.f
#define COLUMM_Y  250.f
#define COLUMM_X 900
#define SPEED	370
#define TEXTURE_MC	"../resources/texture/MC.png"
#define TEXTURE_COLUMM	"../resources/texture/CL0.png"
#define TEXTURE_COLUMMG "../resources/texture/CLG0.png"
#define TEXTURE_COLUMM_1	"../resources/texture/CL1.png"
#define TEXTURE_COLUMM_2	"../resources/texture/CL2.png"
#define TEXTURE_COLUMM_3	"../resources/texture/CL3.png"

#define TEXTURE_BACKGROUND	"../resources/texture/Gameover2.png"
#define TEXTURE_FIRE		"../resources/texture/fire.png"
#define TEXTURE_ANIM		"../resources/Animation/die.png"
//MenuScene
#define TEXTURE_BACKGROUNDLOAD "../resources/texture/logo.jpg"
#define TEXTURE_BACKGROUNDMENU "../resources/texture/bkmenu.jpg"
#define TEXTURE_BACKGROUNDBTNPlay "../resources/texture/btnPlay.png"
#define TEXTURE_BACKGROUNDBTNSkin "../resources/texture/btnSkin.png"
#define TEXTURE_BACKGROUNDBTNCalendar "../resources/texture/calendar.png"

//GameOver
#define TEXTURE_BACKGROUNDGAMEOver "../resources/texture/Gameover2.png"
#define TEXTURE_BACKGROUNDBTNReplay "../resources/texture/Button/BTNReplay.png"
#define TEXTURE_BACKGROUNDBTNMenu "../resources/texture/Button/BTNMenu.png"
#define TEXTURE_BACKGROUNDBTNBuy "../resources/texture/Button/BTNBuy.png"

//Other

#define TEXTURE_MINICOLUMM	"../resources/texture/CLevel.png"
#define TEXTURE_Flag	"../resources/texture/CFlag.png"
#define TEXTURE_BTNSelect "../resources/texture/Button/BTNSelect.png"
#define TEXTURE_Arrow "../resources/texture/Skin/ArrowSelect.png"
#define TEXTURE_COIN "../resources/texture/Coin.png" 
#define TEXTURE_GoldBag "../resources/texture/Goldbag.png" 
#define TEXTURE_Pack "../resources/texture/pack.png"


#define MusicMenu "../resources/Audio/MenuMusic.ogg"
#define MusicGame "../resources/Audio/GameSceneMusic.ogg"
#define MusicGameOver "../resources/Audio/GameOverScene.ogg"
#define MusicSceneSkin "../resources/Audio/SkinScene.ogg"
#define Loading "../resources/Sound/Loading.wav"
#define SoundButton "../resources/Sound/ButtonEffect2.wav"
#define SoundHitJump "../resources/Sound/SoundJumpEffect1.wav"
#define Fonttext "../resources/Font/GameFont2.ttf"
//Skin
#define Skin0 "../resources/texture/Skin/Skin0.png"
#define Skin1 "../resources/texture/Skin/Skin1.png"
#define Skin2 "../resources/texture/Skin/Skin2.png"
#define Skin3 "../resources/texture/Skin/Skin3.png"
#define Skin4 "../resources/texture/Skin/Skin4.png"
#define Skin5 "../resources/texture/Skin/Skin5.png"
#define Skin6 "../resources/texture/Skin/Skin6.png"
//Level
#define Gamelevel1 "../resources/Level/Level1.txt"
#define Gamelevel2 "../resources/Level/Level2.txt"
#define Gamelevel3 "../resources/Level/Level3.txt"
#define Gamelevel4 "../resources/Level/Level4.txt"
//Music
#define MusicGame "../resources/Audio/GameSceneMusic.ogg"
#define MusicGame2 "../resources/Audio/GameSceneMusic2.ogg"
#define MusicGame3 "../resources/Audio/GameSceneMusic3.ogg"
#define MusicGame4 "../resources/Audio/GameSceneMusic4.ogg"


//static int  Coin = 0;
//static int Flag_level = 0;
//static int Flag_skin = 0;
//static int Music_volumn = 50;


enum State
{
	LOGO,
	LOADING,
	MENU,
	GAMEPLAY,
	GAMEOVER,
	SKIN,
	SETTING,
	Buy,
	Win,
};
enum E
{
	MOUSE_LEFT,
	MOUSE_LEFT_RELEASE,
	MouseMoved,
	SPACE,
	NO
};

enum State_Columm
{
	COLUMMLEVEL_0 = 0,
	COLUMMLEVEL_1 = 20,
	COLUMMLEVEL_2 = 40,
	COLUMMLEVEL_3 = 60,
	FIRE = 70,
	COLUMMLEVEL_1_FIRE = 80,
	COLUMMLEVEL_2_FIRE = 90
};

