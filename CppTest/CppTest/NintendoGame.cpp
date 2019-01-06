#include "pch.h"
#include "NintendoGame.h"




NintendoGame::NintendoGame(int id, string name) : Game(id, name), m_console("Nintendo")
{	
}

const string * const NintendoGame::GetConsole() const {
	return &m_console;
}

NintendoGame::~NintendoGame()
{
}
