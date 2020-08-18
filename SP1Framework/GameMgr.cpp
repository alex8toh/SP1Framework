#include "gameMgr.h"

GameMgr* GameMgr::instance = NULL; 

GameMgr* GameMgr::getInstance(){

	if (instance == NULL)
	{
		instance = new GameMgr();
	}
	return instance;
}

void GameMgr::init()
{


}

void GameMgr::input() {
	pGames[state]->input();
}

void GameMgr::update(double dt)
{
	pGames[state]->update(dt);
}

void GameMgr::render()
{
	pGames[state]->render();
}

void GameMgr::setGameState(EGAMESTATE state)
{
	this->state = state;
}

void GameMgr::keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent) 
{
	pGames[state]->KBHandler(keyboardEvent);
}

void GameMgr::mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent) 
{
	pGames[state]->MouseHandler(mouseEvent);
}