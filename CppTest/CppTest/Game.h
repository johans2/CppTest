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
		const void					RunThenFunc(void(*onRunFinished)(const std::string&, bool)) const;
		const void					RunThenLambda(const std::function<void(const std::string&, bool)>& onRunFinished) const;

		void						SetRating(int rating);
		

		virtual const std::string * const GetConsole() const { return &m_defaultConsole; }

	private:
		int m_ID;
		int m_rating;
		std::string m_name;
		std::string m_defaultConsole = "PC";
};

