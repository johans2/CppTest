// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Game.h"
#include "NintendoGame.h"

void PrintGameInfo(const Game& g);
void PrintByPointer(const Game * const gp);

int main()
{
	Game game1(1, "Blood Bourne");
	Game * game2 = new Game(2, "Mass effect");
	Game * game3 = new NintendoGame(3, "Dark souls");

	game1.SetRating(10);
	game2->SetRating(8);
	game3->SetRating(9);
	/*
	PrintGameInfo(game1);
	PrintGameInfo(*game2);
	PrintGameInfo(*game3);
	*/
	PrintByPointer(&game1);
	PrintByPointer(game2);
	PrintByPointer(game3);

	delete game2;
	delete game3;

	std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void PrintGameInfo(const Game & g)
{
	std::cout << "Game 1 ID: " << *g.GetID();
	std::cout << " Game 1 name: " << *g.GetName();
	std::cout << " Game 1 console: " << *g.GetConsole();
	std::cout << " Game 1 rating: " << *g.GetRating();
	std::cout << "\n";
}

void PrintByPointer(const Game * const gp)
{
	std::cout << "Game 1 ID: " << *gp->GetID();
	std::cout << " Game 1 name: " << *gp->GetName();
	std::cout << " Game 1 console: " << *gp->GetConsole();
	std::cout << " Game 1 rating: " << *gp->GetRating();
	std::cout << "\n";

}