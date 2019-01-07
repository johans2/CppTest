#pragma once
#include <string>
#include <iostream>
using namespace std;

class Game
{
	
	public:
		Game(int id, string name);
		~Game();
		const int * const GetID() const;
		const string * const GetName() const;
		const int * const GetRating() const;

		void SetRating(int rating);
		

		virtual const string * const GetConsole() const { return &m_defaultConsole; }

	private:
		int m_ID;
		int m_rating;
		string m_name;
		string m_defaultConsole = "PC";
};

