#pragma once
#include "Framework\console.h"

class GameLevelBase
{
public: 
	virtual void init() = 0;
	virtual void input() = 0; 
	virtual void update(double dt) = 0; 
	virtual void render() = 0; 
	

	virtual void KBHandler(const KEY_EVENT_RECORD& keyboardEvent) = 0; 
	virtual void MouseHandler(const MOUSE_EVENT_RECORD& mouseEvent)=0; 
};

