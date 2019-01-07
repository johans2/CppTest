#pragma once
#include <string>
#include <iostream>

class Game
{
	
	public:
		Game(int id, std::string name);
		~Game();
		const int * const GetID() const;
		const std::string * const GetName() const;
		const int * const GetRating() const;

		void SetRating(int rating);
		

		virtual const std::string * const GetConsole() const { return &m_defaultConsole; }

	private:
		int m_ID;
		int m_rating;
		std::string m_name;
		std::string m_defaultConsole = "PC";
};

