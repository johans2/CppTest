#pragma once
#include <string>
#include <iostream>
#include <functional>
#include <memory>
#include "GameState.h"


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
		class SplashScreenState : public GameState {
			void Enter() override;
			void Update() override;
			void Exit() override;
		};

		class RunningState : public GameState {
			void Enter() override;
			void Update() override;
			void Exit() override;
		};

		class CreditsState : public GameState {
			void Enter() override;
			void Update() override;
			void Exit() override;
		};

		std::shared_ptr<SplashScreenState>	m_SplashScreenState;
		std::shared_ptr<RunningState>		m_RunningState;
		std::shared_ptr<CreditsState>		m_CreditsState;

		std::shared_ptr <GameState>			m_CurrenState;
		void GoToState(std::shared_ptr<GameState> newState);


	private:
		


		const int m_ID;
		int m_Rating;
		std::string m_Name;
		const std::string m_defaultConsole = "PC";

};

