#pragma once
#include "Game.h"

class NintendoGame : public Game
{
public:

	const string * const GetConsole() const override;

	NintendoGame(int id, string name);
	~NintendoGame();

private:
	string m_console;

};

