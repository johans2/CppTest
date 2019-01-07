#pragma once
#include "Game.h"

class NintendoGame : public Game
{
public:

	const std::string * const GetConsole() const override;

	NintendoGame(int id, std::string name);
	~NintendoGame();

private:
	std::string m_console;

};

