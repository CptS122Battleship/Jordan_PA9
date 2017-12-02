#pragma once

// Includes
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Class

class ScreenNode : public sf::RectangleShape
{

public:

	// constructor
	ScreenNode(sf::Vector2f const &pos = sf::Vector2f( 300, 100), sf::Color const &newColor = sf::Color::Cyan, sf::Vector2f const &size = sf::Vector2f(40, 40), string const &newHitMiss = "None", bool const &newOccupied = false, string const &newShip = "None");

	// destructor
	~ScreenNode();

	// getters
	string getHitMiss() const;
	bool getOccupied() const;
	string getShip() const;

	// setters
	void setHitMiss(string const newHitMiss);
	void setOccupied(bool const newOccupied);
	void setShip(string const newShip);

	//
	void changeColor();

private:

	string hitMiss;

	bool occupied; 

	string ship;

};
