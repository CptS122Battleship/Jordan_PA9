#pragma once

// Includes
#include "ScreenNode.h"

using std::cin;
using std::cout;
using std::endl;

// Class

class Boat : public sf::RectangleShape
{

	public:

		// constructor
		Boat(sf::Vector2f const &pos = sf::Vector2f(300, 100), sf::Color const &newColor = sf::Color::Black, sf::Vector2f const &size = sf::Vector2f(40, 40), int const newHits = 0);

		// destructor
		~Boat();

		// getters
		int getHits() const;

		// setters
		void setHits(int const newHits);

		//
		virtual bool isDestroyed() = 0;

	private:

		int hits;

};
