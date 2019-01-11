#pragma once
#include <string>
#include <iostream>
#include <functional>
#include <memory>
#include "GameState.h"
#include "Game.h"


class Game
{
	
	public:
		Game(int id, std::string name);
		~Game();

		const int * const			GetID() const;
		const std::string * const	GetName() const;
		const int * const			GetRating() const;
		void						SetRating(int rating);
		void						RunThenFunc(void(*onRunFinished)(const std::string&, bool));
		void						RunThenLambda(const std::function<void(const std::string&, bool)>& onRunFinished) const;
		
		virtual const std::string * const GetConsole() const { return &m_defaultConsole; }

		bool operator==(const Game& other) const { return m_Name == *other.GetName(); }

	protected:
		
		// Game States
		class GameState
		{
		public:
			virtual void Enter(Game& game) {};
			virtual void Update(Game& game) {};
			virtual void Exit(Game& game) {};
		};

		class SplashScreenState : public GameState {
			public:
				SplashScreenState()
				{ 
					std::cout << "SplashScreenState constructor called.\n"; 
				}
				void Enter(Game& game) override;
				void Update(Game& game) override;
				void Exit(Game& game) override;
		};

		class RunningState : public GameState {
			public:
				RunningState()
				{ 
					std::cout << "RunningState constructor called.\n"; 
				}
				void Enter(Game& game) override;
				void Update(Game& game) override;
				void Exit(Game& game) override;
		};

		class CreditsState : public GameState {
			public:
				CreditsState()
				{ 
					std::cout << "CreditsState constructor called.\n"; 
				}
				void Enter(Game& game) override;
				void Update(Game& game) override;
				void Exit(Game& game) override;
		};

		SplashScreenState	m_SplashScreenState;
		RunningState		m_RunningState;
		CreditsState		m_CreditsState;

		GameState *			m_CurrenState;
		void GoToState(GameState& newState);


	private:
		


		const int m_ID;
		int m_Rating;
		std::string m_Name;
		const std::string m_defaultConsole = "PC";

};

