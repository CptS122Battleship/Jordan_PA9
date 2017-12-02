#pragma once

// Includes
#include "Boat.h"

using std::cin;
using std::cout;
using std::endl;

// Classes

class AircraftCarrier : public Boat
{

	public:

		// constructor
		AircraftCarrier(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~AircraftCarrier();

		//
		bool isDestroyed();

	private:

};

class Battleship : public Boat
{

	public:

		// constructor
		Battleship(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~Battleship();

		//
		bool isDestroyed();

	private:

};

class Cruiser : public Boat
{

	public:

		// constructor
		Cruiser(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~Cruiser();

		//
		bool isDestroyed();

	private:

};

class Submarine : public Boat
{

	public:

		// constructor
		Submarine(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~Submarine();

		//
		bool isDestroyed();

	private:

};

class Destroyer : public Boat
{

	public:

		// constructor
		Destroyer(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~Destroyer();

		//
		bool isDestroyed();

	private:

};