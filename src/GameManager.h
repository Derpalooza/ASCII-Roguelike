#pragma once
#include "StateMachine.h"

using namespace std;

class GameManager
{
public:
	GameManager();
	void run();
	
private:
	StateMachine _stateMachine;

};