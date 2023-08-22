#include "stdafx.h"
#include "GameManagerState.h"

GameManagerState* GameManagerState::s_Instance = nullptr;
GameManagerState::GameManagerState()
{
}
GameManagerState::~GameManagerState()
{
	if (s_Instance != NULL)
		delete GameManagerState::getInstance()->s_Instance;
	GameManagerState::getInstance()->s_Instance = 0;
}
GameManagerState* GameManagerState::getInstance() {
	if (s_Instance == nullptr) {
		s_Instance = new GameManagerState();
	}
	return s_Instance;
}
void GameManagerState::ChangeState(State st) {//Change state game
	state = st;
}
State GameManagerState::getState() {//Get state game
	return state;
}