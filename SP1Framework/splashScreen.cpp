#include "splashScreen.h"
#include "gameMgr.h"

splashScreen::splashScreen() :waitTime(0)
{
}


void splashScreen::init()
{
}

void splashScreen::input() {
}

void splashScreen::render()
{

}


void splashScreen::update(double dt) 
{
	waitTime += dt;

	if (waitTime > 3.0)
		GameMgr::getInstance()->setGameState(GAME);
}

void splashScreen::KBHandler(const KEY_EVENT_RECORD& keyboardEvent) {
}


void splashScreen::MouseHandler(const MOUSE_EVENT_RECORD& mouseEvent) {


}