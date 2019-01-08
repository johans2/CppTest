#pragma once
#include <string>
#include <iostream>
#include <functional>

class Game
{
	
	public:
		Game(int id, std::string name);
		~Game();

		const int * const			GetID() const;
		const std::string * const	GetName() const;
		const int * const			GetRating() const;
		void						SetRating(int rating);
		void						RunThenFunc(void(*onRunFinished)(const std::string&, bool)) const;
		void						RunThenLambda(const std::function<void(const std::string&, bool)>& onRunFinished) const;
		
		virtual const std::string * const GetConsole() const { return &m_defaultConsole; }

		bool operator==(const Game& other) const { return m_name == *other.GetName(); }

	private:
		int m_ID;
		int m_rating;
		std::string m_name;
		std::string m_defaultConsole = "PC";
};

