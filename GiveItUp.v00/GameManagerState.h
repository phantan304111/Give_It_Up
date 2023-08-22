#pragma once
#include "define.h"
class GameManagerState
{
public:
	GameManagerState();
	~GameManagerState();
	static GameManagerState* getInstance();//sigleton
	void ChangeState(State st);
	State getState();
private:
	static GameManagerState* s_Instance;
	State state;
};
