#pragma once

#include "GameLevelBase.h"
#include "splashScreen.h"

// Enumeration for the different screen states
enum EGAMESTATE
{
	SPLASHSCREEN,
	GAME,
	COUNT
};


class GameMgr {
private: 
	EGAMESTATE state;
	GameLevelBase* pGames[COUNT];

	static GameMgr *instance; 

public: 

	// constructor 
	GameMgr() :state(SPLASHSCREEN)
	{
		pGames[SPLASHSCREEN] = new splashScreen();
	}
	
	static GameMgr* getInstance();

	void init(void); 
	void shutdown(void);
	void setGameState(EGAMESTATE state);

	void input(); 
	void update(double dt);
	void render(); 

	void keyboardHandler(const KEY_EVENT_RECORD& keyboardEvent); 

	void mouseHandler(const MOUSE_EVENT_RECORD& mouseEvent);

};