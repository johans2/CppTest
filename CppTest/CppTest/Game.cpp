#include "pch.h"
#include "Game.h"


Game::Game(int id, string name)
{
	m_ID = id;
	m_name = name;
	m_rating = 0;
}


// Get the ID of the game.
const int * const Game::GetID() const {
	return &m_ID;
}


// Get the name of the game.
const string * const Game::GetName() const {
	return &m_name;
}

const int * const Game::GetRating() const {
	return &m_rating;
}

void Game::SetRating(int rating)
{
	m_rating = rating;
}

Game::~Game()
{
}
