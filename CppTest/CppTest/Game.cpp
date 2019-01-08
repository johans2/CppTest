
#include "pch.h"
#include "Game.h"

#include <thread>

Game::Game(int id, std::string name) :
	m_ID(id),
	m_name(name),
	m_rating(0)
{
	std::cout << "Game: " << m_name << " created.\n";
}


// Get the ID of the game.
const int * const Game::GetID() const {
	return &m_ID;
}


// Get the name of the game.
const std::string * const Game::GetName() const {
	return &m_name;
}

const int * const Game::GetRating() const {
	return &m_rating;
}

// Callback with pure function pointer
void Game::RunThenFunc(void(*onRunFinished)(const std::string&, bool)) const
{
	using namespace std::literals::chrono_literals;

	std::this_thread::sleep_for(1s);

	onRunFinished(m_name, true);
}

// Callback accepting lambda
void Game::RunThenLambda(const std::function<void(const std::string&, bool)>& onRunFinished) const
{
	using namespace std::literals::chrono_literals;

	std::this_thread::sleep_for(1s);

	onRunFinished(m_name, true);
}

void Game::SetRating(int rating)
{
	m_rating = rating;
}

Game::~Game()
{
	std::cout << "Game: " << m_name << " deleted.\n";
}
