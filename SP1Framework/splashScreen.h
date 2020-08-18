#pragma once

#include "GameLevelBase.h"

class splashScreen : public GameLevelBase 
{
private:
	double waitTime; 

public:

	// constructor 
	splashScreen();

	void init();
	void input();
	void update(double dt);
	void render();

	void KBHandler(const KEY_EVENT_RECORD& keyboardEvent);
	void MouseHandler(const MOUSE_EVENT_RECORD& mouseEvent); 
};