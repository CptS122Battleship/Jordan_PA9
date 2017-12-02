#pragma once

// Includes
#include "ScreenNode.h"
#include "Ships.h"

using std::cin;
using std::cout;
using std::endl;

// Class

class Screen
{
	public:

		// constructor
		Screen(int const newX = 50, int const newY = 50);

		// destructor
		~Screen();

		// getters
		ScreenNode getNode(int const x, int const y);

		// setters
		void setNodeColor(int const x, int const y, sf::Color newColor);
		void setNodeHitMiss(int const x, int const y, string const newHitMiss);

		// 
		void computerShipSetup();
		void playerShipSetup();


	private:

		ScreenNode nodes[10][10];

};

int mouseHover(sf::RenderWindow &window, Screen &computer, Screen &player, sf::Text &compText, sf::Text &playerText, AircraftCarrier &carrierC, Battleship &battleshipC, Cruiser &cruiserC, Submarine &subC, Destroyer &destroyerC);