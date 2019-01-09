// CppTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <memory>
#include "Game.h"
#include "NintendoGame.h"
#include <thread>
#include <mutex>

using namespace std;

void PrintByReference(const Game& g);
void PrintByPointer(const Game * const gp);
void PrintBySharedPointer(const shared_ptr<Game> gp);
void OnRunComplete(const std::string& name, bool success);
void PrintIsSameGame(const Game& a, const Game& b);
void WaitInThread(std::string returnMsg);

template<typename T>
using sPtr = shared_ptr<T>;

using UShort = unsigned short int;

int main()
{
	{
		Game game1(1, "Blood Bourne");
		sPtr<Game> game2 = make_shared<Game>(2, "Mass effect");
		sPtr<Game> game3 = make_shared<NintendoGame>(3, "Dark souls");
		sPtr<Game> game4 = make_shared<NintendoGame>(4, "Blood Bourne");
		
		std::string err = "ERROR: ";

		game1.SetRating(10);
		game2->SetRating(8);
		game3->SetRating(9);

		PrintByReference(game1);
		PrintByReference(*game2);
		PrintByReference(*game3);

		PrintIsSameGame(game1, *game4);

		auto lambda = [&err](const std::string& name, bool success) { 
			std::cout << err << name << " Did not run successfully.\n";
		};

		std::thread t1(WaitInThread, std::string("stuff..\n"));
		std::thread t2(WaitInThread, std::string("other stuff..\n"));
		std::thread t3(WaitInThread, std::string("different stuff..\n"));

		game1.RunThenFunc(OnRunComplete);
		game2->RunThenFunc(OnRunComplete);
		game3->RunThenLambda(lambda);
		

		t1.join();
		t2.join();
		t3.join();


		std::cout << " ----> Program finished.\n";
	}

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

int number(0);
std::mutex mtx;

void WaitInThread(std::string returnMsg) {
	using namespace std::literals::chrono_literals;
	
	std::this_thread::sleep_for(2s);


	mtx.lock();
	for (size_t i = 0; i < 10; i++)
	{
		number++;
	}
	std::cout << " Done doing " << returnMsg << "  number: " << number << "\n";
	mtx.unlock();
	
}

void PrintIsSameGame(const Game& a, const Game& b) {
	
	if (a == b)
	{
		std::cout << *a.GetName() << " and " << *b.GetName() << " are the same\n";
	}
	else {
		std::cout << *a.GetName() << " and " << *b.GetName() << " are NOT the same\n";
	}

	
}

void OnRunComplete(const std::string& name, bool success) {
	if (success)
	{
		std::cout << name << " Ran successfully!\n";
	}
	else {
		std::cout << name << " Did not run successfully.\n";
	}

}

void PrintByReference(const Game & g)
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

void PrintBySharedPointer(const std::shared_ptr<Game> gp)
{
	std::cout << "Game 1 ID: " << *gp->GetID();
	std::cout << " Game 1 name: " << *gp->GetName();
	std::cout << " Game 1 console: " << *gp->GetConsole();
	std::cout << " Game 1 rating: " << *gp->GetRating();
	std::cout << "\n";
}