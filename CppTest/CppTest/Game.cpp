
#include "pch.h"
#include "Game.h"
#include <thread>
#include <memory>

Game::Game(int id, std::string name) :
	m_ID(id),
	m_Name(name),
	m_Rating(0)
{
	m_SplashScreenState =	std::make_shared<SplashScreenState>();
	m_RunningState =		std::make_shared<RunningState>();
	m_CreditsState =		std::make_shared<CreditsState>();
	

	std::cout << "Game: " << m_Name << " created.\n";
}


// Get the ID of the game.
const int * const Game::GetID() const {
	return &m_ID;
}


// Get the name of the game.
const std::string * const Game::GetName() const {
	return &m_Name;
}

const int * const Game::GetRating() const {
	return &m_Rating;
}

// Callback with pure function pointer
void Game::RunThenFunc(void(*onRunFinished)(const std::string&, bool))
{
	GoToState(m_SplashScreenState);

	onRunFinished(m_Name, true);
}

// Callback accepting lambda
void Game::RunThenLambda(const std::function<void(const std::string&, bool)>& onRunFinished) const
{
	using namespace std::literals::chrono_literals;

	std::this_thread::sleep_for(1s);

	onRunFinished(m_Name, true);
}

void Game::SetRating(int rating) 
{
	m_Rating = rating;
}

void Game::GoToState(std::shared_ptr<GameState> newState)
{
	if (m_CurrenState != nullptr)
	{
		m_CurrenState->Exit();
	}

	m_CurrenState = newState;

	m_CurrenState->Enter();
}

Game::~Game()
{
	std::cout << "Game: " << m_Name << " deleted.\n";
}


// Splash screen game state implementation.

void Game::SplashScreenState::Enter()
{
	std::cout << "GAMESTATE:  Entered splashscreen state.\n";
	
}

void Game::SplashScreenState::Update()
{
	std::cout << "GAMESTATE:  Updating splashscreen state...\n";
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(1s);
}

void Game::SplashScreenState::Exit()
{
	std::cout << "GAMESTATE:  Exit splashscreen state.\n";
}

// Running game state implementation.

void Game::RunningState::Enter()
{
	std::cout << "GAMESTATE:  Entered Running state.\n";
}

void Game::RunningState::Update()
{
	std::cout << "GAMESTATE:  Updating running state...\n";
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(1s);
}

void Game::RunningState::Exit()
{
	std::cout << "GAMESTATE:  Exit running state.\n";
}

// Credits game state implementation.

void Game::CreditsState::Enter()
{
	std::cout << "GAMESTATE:  Entered credits state.\n";
}

void Game::CreditsState::Update()
{
	std::cout << "GAMESTATE:  Updating credits state...\n";
	using namespace std::literals::chrono_literals;
	std::this_thread::sleep_for(1s);
}

void Game::CreditsState::Exit()
{
	std::cout << "GAMESTATE:  Exit credits state.\n";
}
