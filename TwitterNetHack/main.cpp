#include"Character.h"
#include"Enemy.h"
#include"Player.h"
#include"Game.h"
#include"TextHandler.h"
#include"InputHandler.h"
#include<iostream>
using namespace std;
int main()
{
	Game game;
	TextHandler* txtH = new TextHandler();
	Player player(txtH, 100, 20, 20);
	Enemy enemy(txtH, 70, 10, 10, "Chestcunt", "It's a bitch boi");
	bool running = true;
	cout << "Welcome to TwitterNetHack!\n\n";
	while (running)
	{
		cout << "What do you want to do? (start/join/quit)\n";
		string answer = "";
		cin >> answer;
		cout << endl;
		if (answer == "start")
		{
			game.battleSequence(&enemy);
			//TODO: Start game.
		}
		else if (answer == "join")
		{
			cout << "This feature is under development.\n\n";
		}
		else if (answer == "quit")
		{
			running = false;
		}
		else
		{
			cout << "That's not a valid response! Try again.\n\n";
		}
	}
	return 0;
}