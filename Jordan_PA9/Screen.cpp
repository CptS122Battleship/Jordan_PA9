#include "Screen.h"
#include <cstdlib>
#include <ctime>


// Member // 
/*************************************************************
* Function: Screen()                                         *
* Date Created: 11/27/2017                                   *
* Date Last Modified: 11/27/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

Screen::Screen(int newX, int newY)
{
	int x = 0;
	int y = 0;
	while (x != 10)
	{

		while (y != 10)
		{

			this->nodes[x][y] = ScreenNode(sf::Vector2f( (newX + (x * 40)), (newY + (y * 40))));
			y += 1;

		}
		y = 0;
		x += 1;

	}
}



// Member // 
/*************************************************************
* Function: ~Screen()                                        *
* Date Created: 11/27/2017                                   *
* Date Last Modified: 11/27/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Screen::~Screen()
{

	//delete [] this->nodes;

}



// Member // 
/*************************************************************
* Function: getNode()                                        *
* Date Created: 11/27/2017                                   *
* Date Last Modified: 11/27/2017                             *
* Description: This function is a class getter that returns  *
*              the object's data.                            *
* Input parameters: None                                     *
* Returns: screen node                                       *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be returned             *
*************************************************************/

ScreenNode Screen::getNode(int const x, int const y)
{

	return this->nodes[x][y];

}



// Member // 
/*************************************************************
* Function: setNodeColor()                                   *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class setter that assigns  *
*              new color to the object.                      *
* Input parameters: New color                                *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New color will be assigned                 *
*************************************************************/

void Screen::setNodeColor(int const x, int const y, sf::Color newColor)
{

	this->nodes[x][y].setFillColor(newColor);

}



// Member // 
/*************************************************************
* Function: setNodeHitMiss()                                 *
* Date Created: 11/30/2017                                   *
* Date Last Modified: 11/30/2017                             *
* Description: This function is a class setter that assigns  *
*              new hit or miss to the object.                *
* Input parameters: New hit or miss                          *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New hit or miss will be assigned           *
*************************************************************/

void Screen::setNodeHitMiss(int const x, int const y, string const newHitMiss)
{

	this->nodes[x][y].setHitMiss(newHitMiss);

}



// Member // 
/*************************************************************
* Function: computerShipSetup()                              *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function sets up the computer's ships.   *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: Computer's ships will be set up            *
*************************************************************/

void Screen::computerShipSetup()
{

	int randomX;
	int randomY;
	int vertOrHor;

	// Computer Ship Placement Randomizer

	// Computer aircraft carrier
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 5 ||  nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true || nodes[randomX][randomY + 3].getOccupied() == true || nodes[randomX][randomY + 4].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Carrier");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setShip("Carrier");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setShip("Carrier");
		nodes[randomX][randomY + 3].setOccupied(true);
		nodes[randomX][randomY + 3].setShip("Carrier");
		nodes[randomX][randomY + 4].setOccupied(true);
		nodes[randomX][randomY + 4].setShip("Carrier");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 5 || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true || nodes[randomX + 3][randomY].getOccupied() == true || nodes[randomX + 4][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Carrier");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setShip("Carrier");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setShip("Carrier");
		nodes[randomX + 3][randomY].setOccupied(true);
		nodes[randomX + 3][randomY].setShip("Carrier");
		nodes[randomX + 4][randomY].setOccupied(true);
		nodes[randomX + 4][randomY].setShip("Carrier");

	}

	// Computer battleship
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 6 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true || nodes[randomX][randomY + 3].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Battleship");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setShip("Battleship");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setShip("Battleship");
		nodes[randomX][randomY + 3].setOccupied(true);
		nodes[randomX][randomY + 3].setShip("Battleship");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 6 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true || nodes[randomX + 3][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Battleship");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setShip("Battleship");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setShip("Battleship");
		nodes[randomX + 3][randomY].setOccupied(true);
		nodes[randomX + 3][randomY].setShip("Battleship");

	}

	// Computer cruiser
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Cruiser");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setShip("Cruiser");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setShip("Cruiser");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Cruiser");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setShip("Cruiser");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setShip("Cruiser");

	}

	// Computer Submarine
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Submarine");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setShip("Submarine");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setShip("Submarine");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Submarine");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setShip("Submarine");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setShip("Submarine");

	}

	// Computer Destroyer
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 8 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Destroyer");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setShip("Destroyer");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 8 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setShip("Destroyer");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setShip("Destroyer");

	}

}



// Member // 
/*************************************************************
* Function: playerShipSetup()                                *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function sets up the player's ships.     *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: Player's ships will be set up              *
*************************************************************/

void Screen::playerShipSetup()
{

	int randomX;
	int randomY;
	int vertOrHor;

	// Player Ship Placement Randomizer

	// Player aircraft carrier
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 5)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Carrier");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 1].setShip("Carrier");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 2].setShip("Carrier");
		nodes[randomX][randomY + 3].setOccupied(true);
		nodes[randomX][randomY + 3].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 3].setShip("Carrier");
		nodes[randomX][randomY + 4].setOccupied(true);
		nodes[randomX][randomY + 4].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 4].setShip("Carrier");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 5)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Carrier");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 1][randomY].setShip("Carrier");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 2][randomY].setShip("Carrier");
		nodes[randomX + 3][randomY].setOccupied(true);
		nodes[randomX + 3][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 3][randomY].setShip("Carrier");
		nodes[randomX + 4][randomY].setOccupied(true);
		nodes[randomX + 4][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 4][randomY].setShip("Carrier");

	}

	// Player battleship
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 6 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true || nodes[randomX][randomY + 3].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Battleship");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 1].setShip("Battleship");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 2].setShip("Battleship");
		nodes[randomX][randomY + 3].setOccupied(true);
		nodes[randomX][randomY + 3].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 3].setShip("Battleship");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 6 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true || nodes[randomX + 3][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Battleship");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 1][randomY].setShip("Battleship");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 2][randomY].setShip("Battleship");
		nodes[randomX + 3][randomY].setOccupied(true);
		nodes[randomX + 3][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 3][randomY].setShip("Battleship");

	}

	// Player cruiser
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Cruiser");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 1].setShip("Cruiser");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 2].setShip("Cruiser");


	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Cruiser");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 1][randomY].setShip("Cruiser");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 2][randomY].setShip("Cruiser");

	}

	// Player Submarine
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true || nodes[randomX][randomY + 2].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Submarine");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 1].setShip("Submarine");
		nodes[randomX][randomY + 2].setOccupied(true);
		nodes[randomX][randomY + 2].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 2].setShip("Submarine");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 7 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true || nodes[randomX + 2][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Submarine");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 1][randomY].setShip("Submarine");
		nodes[randomX + 2][randomY].setOccupied(true);
		nodes[randomX + 2][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 2][randomY].setShip("Submarine");

	}

	// Player Destroyer
	vertOrHor = (rand() % 2) + 1;
	if (vertOrHor == 1)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomY > 8 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX][randomY + 1].getOccupied() == true)
		{
			randomY = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Destroyer");
		nodes[randomX][randomY + 1].setOccupied(true);
		nodes[randomX][randomY + 1].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY + 1].setShip("Destroyer");

	}
	else if (vertOrHor == 2)
	{

		randomX = rand() % 10;
		randomY = rand() % 10;
		while (randomX > 8 || nodes[randomX][randomY].getOccupied() == true || nodes[randomX + 1][randomY].getOccupied() == true)
		{
			randomX = rand() % 10;
		}
		nodes[randomX][randomY].setOccupied(true);
		nodes[randomX][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX][randomY].setShip("Destroyer");
		nodes[randomX + 1][randomY].setOccupied(true);
		nodes[randomX + 1][randomY].setFillColor(sf::Color::Yellow);
		nodes[randomX + 1][randomY].setShip("Destroyer");

	}

}





int mouseHover(sf::RenderWindow &window, Screen &computer, Screen &player, sf::Text &compText, sf::Text &playerText, AircraftCarrier &carrierC, Battleship &battleshipC, Cruiser &cruiserC, Submarine &subC, Destroyer &destroyerC)
{
	int x = 0;
	int y = 0;
	int success = 0;

		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 0).getOccupied() == true)
				{

					if (computer.getNode(0, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 0, "Hit");
					computer.setNodeColor(0, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 0, "Miss");
					computer.setNodeColor(0, 0, sf::Color::White);

					success = 1;
				}

			}

		}

		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 0).getOccupied() == true)
				{

					if (computer.getNode(1, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 0, "Hit");
					computer.setNodeColor(1, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 0, "Miss");
					computer.setNodeColor(1, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 0).getOccupied() == true)
				{

					if (computer.getNode(2, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 0, "Hit");
					computer.setNodeColor(2, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 0, "Miss");
					computer.setNodeColor(2, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 0).getOccupied() == true)
				{

					if (computer.getNode(3, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 0, "Hit");
					computer.setNodeColor(3, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 0, "Miss");
					computer.setNodeColor(3, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 0).getOccupied() == true)
				{

					if (computer.getNode(4, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 0, "Hit");
					computer.setNodeColor(4, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 0, "Miss");
					computer.setNodeColor(4, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 0).getOccupied() == true)
				{

					if (computer.getNode(5, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 0, "Hit");
					computer.setNodeColor(5, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 0, "Miss");
					computer.setNodeColor(5, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 0).getOccupied() == true)
				{

					if (computer.getNode(6, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 0, "Hit");
					computer.setNodeColor(6, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 0, "Miss");
					computer.setNodeColor(6, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 0).getOccupied() == true)
				{

					if (computer.getNode(7, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 0, "Hit");
					computer.setNodeColor(7, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 0, "Miss");
					computer.setNodeColor(7, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 0).getOccupied() == true)
				{

					if (computer.getNode(8, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 0, "Hit");
					computer.setNodeColor(8, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 0, "Miss");
					computer.setNodeColor(8, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 50 && sf::Mouse::getPosition(window).y <= 90)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 0).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 0, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 0).getOccupied() == true)
				{

					if (computer.getNode(9, 0).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 0).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 0).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 0).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 0).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 0, "Hit");
					computer.setNodeColor(9, 0, sf::Color::Red);


					success = 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 0, "Miss");
					computer.setNodeColor(9, 0, sf::Color::White);

					success = 1;
				}

			}
		}

		// Row 1
		////////////////////////////////////////////////////////////////////////////////////////
		// Row 2
		
		//////////ROW 2    ROW 2///////////
		//	0,1
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 1).getOccupied() == true)
				{

					if (computer.getNode(0, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 1, "Hit");
					computer.setNodeColor(0, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 1, "Miss");
					computer.setNodeColor(0, 1, sf::Color::White);

					return 1;
				}

			}
		}

		/// 1,1
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 1).getOccupied() == true)
				{

					if (computer.getNode(1, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 1, "Hit");
					computer.setNodeColor(1, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 1, "Miss");
					computer.setNodeColor(1, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//	2,1
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 1).getOccupied() == true)
				{

					if (computer.getNode(2, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 1, "Hit");
					computer.setNodeColor(2, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 1, "Miss");
					computer.setNodeColor(2, 1, sf::Color::White);

					return 1;
				}

			}
		}
		// 3,1
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 1).getOccupied() == true)
				{

					if (computer.getNode(3, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 1, "Hit");
					computer.setNodeColor(3, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 1, "Miss");
					computer.setNodeColor(3, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//4,1
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 1).getOccupied() == true)
				{

					if (computer.getNode(4, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 1, "Hit");
					computer.setNodeColor(4, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 1, "Miss");
					computer.setNodeColor(4, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//5,1
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 1).getOccupied() == true)
				{

					if (computer.getNode(5, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 1, "Hit");
					computer.setNodeColor(5, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 1, "Miss");
					computer.setNodeColor(5, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//6,1
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 1).getOccupied() == true)
				{

					if (computer.getNode(6, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 1, "Hit");
					computer.setNodeColor(6, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 1, "Miss");
					computer.setNodeColor(6, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//7,1
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 1).getOccupied() == true)
				{

					if (computer.getNode(7, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 1, "Hit");
					computer.setNodeColor(7, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 1, "Miss");
					computer.setNodeColor(7, 1, sf::Color::White);

					return 1;
				}

			}
		}
		//8,1
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 1).getOccupied() == true)
				{

					if (computer.getNode(8, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 1, "Hit");
					computer.setNodeColor(8, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 1, "Miss");
					computer.setNodeColor(8, 1, sf::Color::White);

					return 1;
				}

			}
		}

		//9,1
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 90 && sf::Mouse::getPosition(window).y <= 130)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 1).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 1, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 1).getOccupied() == true)
				{

					if (computer.getNode(9, 1).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 1).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 1).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 1).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 1).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 1, "Hit");
					computer.setNodeColor(9, 1, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 1, "Miss");
					computer.setNodeColor(9, 1, sf::Color::White);

					return 1;
				}

			}
		}
		///////ROW 3 ROW 3///////////
		//	0,2
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 2).getOccupied() == true)
				{

					if (computer.getNode(0, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 2, "Hit");
					computer.setNodeColor(0, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 2, "Miss");
					computer.setNodeColor(0, 2, sf::Color::White);

					return 1;
				}

			}
		}
		// 1,2
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 2).getOccupied() == true)
				{

					if (computer.getNode(1, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 2, "Hit");
					computer.setNodeColor(1, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 2, "Miss");
					computer.setNodeColor(1, 2, sf::Color::White);

					return 1;
				}

			}
		}
		// 2,2
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 2).getOccupied() == true)
				{

					if (computer.getNode(2, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 2, "Hit");
					computer.setNodeColor(2, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 2, "Miss");
					computer.setNodeColor(2, 2, sf::Color::White);

					return 1;
				}

			}
		}
		//3,2
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 2).getOccupied() == true)
				{

					if (computer.getNode(3, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 2, "Hit");
					computer.setNodeColor(3, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 2, "Miss");
					computer.setNodeColor(3, 2, sf::Color::White);

					return 1;
				}

			}
		}
		//4,2
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 2).getOccupied() == true)
				{

					if (computer.getNode(4, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 2, "Hit");
					computer.setNodeColor(4, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 2, "Miss");
					computer.setNodeColor(4, 2, sf::Color::White);

					return 1;
				}

			}
		}
		//5,2
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 2).getOccupied() == true)
				{

					if (computer.getNode(5, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 2, "Hit");
					computer.setNodeColor(5, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 2, "Miss");
					computer.setNodeColor(5, 2, sf::Color::White);

					return 1;
				}

			}
		}
		//6,2
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 2).getOccupied() == true)
				{

					if (computer.getNode(6, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 2, "Hit");
					computer.setNodeColor(6, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 2, "Miss");
					computer.setNodeColor(6, 2, sf::Color::White);

					return 1;
				}

			}
		}
		// 7,2
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 2).getOccupied() == true)
				{

					if (computer.getNode(7, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 2, "Hit");
					computer.setNodeColor(7, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 2, "Miss");
					computer.setNodeColor(7, 2, sf::Color::White);

					return 1;
				}

			}
		}
		//8,2
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 2).getOccupied() == true)
				{

					if (computer.getNode(8, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 2, "Hit");
					computer.setNodeColor(8, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 2, "Miss");
					computer.setNodeColor(8, 2, sf::Color::White);

					return 1;
				}

			}
		}
		// 9,2
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 130 && sf::Mouse::getPosition(window).y <= 170)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 2).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 2, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 2).getOccupied() == true)
				{

					if (computer.getNode(9, 2).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 2).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 2).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 2).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 2).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 2, "Hit");
					computer.setNodeColor(9, 2, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 2, "Miss");
					computer.setNodeColor(9, 2, sf::Color::White);

					return 1;
				}

			}
		}
		////// ROW 4 ROW 4///////
		// 0,3
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 3).getOccupied() == true)
				{

					if (computer.getNode(0, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 3, "Hit");
					computer.setNodeColor(0, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 3, "Miss");
					computer.setNodeColor(0, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 1,3
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 3).getOccupied() == true)
				{

					if (computer.getNode(1, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 3, "Hit");
					computer.setNodeColor(1, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 3, "Miss");
					computer.setNodeColor(1, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 2,3
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 3).getOccupied() == true)
				{

					if (computer.getNode(2, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 3, "Hit");
					computer.setNodeColor(2, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 3, "Miss");
					computer.setNodeColor(2, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 3,3
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 3).getOccupied() == true)
				{

					if (computer.getNode(3, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 3, "Hit");
					computer.setNodeColor(3, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 3, "Miss");
					computer.setNodeColor(3, 3, sf::Color::White);

					return 1;
				}

			}
		}
		//4,3
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 3).getOccupied() == true)
				{

					if (computer.getNode(4, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 3, "Hit");
					computer.setNodeColor(4, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 3, "Miss");
					computer.setNodeColor(4, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 5,3
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 3).getOccupied() == true)
				{

					if (computer.getNode(5, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 3, "Hit");
					computer.setNodeColor(5, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 3, "Miss");
					computer.setNodeColor(5, 3, sf::Color::White);

					return 1;
				}

			}
		}
		//6,3
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 3).getOccupied() == true)
				{

					if (computer.getNode(6, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 3, "Hit");
					computer.setNodeColor(6, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 3, "Miss");
					computer.setNodeColor(6, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 7,3
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 3).getOccupied() == true)
				{

					if (computer.getNode(7, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 3, "Hit");
					computer.setNodeColor(7, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 3, "Miss");
					computer.setNodeColor(7, 3, sf::Color::White);

					return 1;
				}

			}
		}
		//8,3
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 3).getOccupied() == true)
				{

					if (computer.getNode(8, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 3, "Hit");
					computer.setNodeColor(8, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 3, "Miss");
					computer.setNodeColor(8, 3, sf::Color::White);

					return 1;
				}

			}
		}
		// 9,3
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 170 && sf::Mouse::getPosition(window).y <= 210)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 3).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 3, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 3).getOccupied() == true)
				{

					if (computer.getNode(9, 3).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 3).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 3).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 3).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 3).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 3, "Hit");
					computer.setNodeColor(9, 3, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 3, "Miss");
					computer.setNodeColor(9, 3, sf::Color::White);

					return 1;
				}

			}
		}
		///////// ROW 5 ROW 5///////
		// 0,4
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 4).getOccupied() == true)
				{

					if (computer.getNode(0, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 4, "Hit");
					computer.setNodeColor(0, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 4, "Miss");
					computer.setNodeColor(0, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 1,4
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 4).getOccupied() == true)
				{

					if (computer.getNode(1, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 4, "Hit");
					computer.setNodeColor(1, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 4, "Miss");
					computer.setNodeColor(1, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 2,4
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 4).getOccupied() == true)
				{

					if (computer.getNode(2, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 4, "Hit");
					computer.setNodeColor(2, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 4, "Miss");
					computer.setNodeColor(2, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 3,4
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 4).getOccupied() == true)
				{

					if (computer.getNode(3, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 4, "Hit");
					computer.setNodeColor(3, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 4, "Miss");
					computer.setNodeColor(3, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 4,4
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 4).getOccupied() == true)
				{

					if (computer.getNode(4, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 4, "Hit");
					computer.setNodeColor(4, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 4, "Miss");
					computer.setNodeColor(4, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 5,4
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 4).getOccupied() == true)
				{

					if (computer.getNode(5, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 4, "Hit");
					computer.setNodeColor(5, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 4, "Miss");
					computer.setNodeColor(5, 4, sf::Color::White);

					return 1;
				}

			}
		}
		//6,4
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 4).getOccupied() == true)
				{

					if (computer.getNode(6, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 4, "Hit");
					computer.setNodeColor(6, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 4, "Miss");
					computer.setNodeColor(6, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 7,4
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 4).getOccupied() == true)
				{

					if (computer.getNode(7, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 4, "Hit");
					computer.setNodeColor(7, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 4, "Miss");
					computer.setNodeColor(7, 4, sf::Color::White);

					return 1;
				}

			}
		}
		//8,4
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 4).getOccupied() == true)
				{

					if (computer.getNode(8, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 4, "Hit");
					computer.setNodeColor(8, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 4, "Miss");
					computer.setNodeColor(8, 4, sf::Color::White);

					return 1;
				}

			}
		}
		// 9,4
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 210 && sf::Mouse::getPosition(window).y <= 250)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 4).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 4, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 4).getOccupied() == true)
				{

					if (computer.getNode(9, 4).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 4).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 4).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 4).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 4).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 4, "Hit");
					computer.setNodeColor(9, 4, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 4, "Miss");
					computer.setNodeColor(9, 4, sf::Color::White);

					return 1;
				}

			}
		}
		/////////ROW 6 ROW 6//////
		//	0,5
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 5).getOccupied() == true)
				{

					if (computer.getNode(0, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 5, "Hit");
					computer.setNodeColor(0, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 5, "Miss");
					computer.setNodeColor(0, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 1,5
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 5).getOccupied() == true)
				{

					if (computer.getNode(1, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 5, "Hit");
					computer.setNodeColor(1, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 5, "Miss");
					computer.setNodeColor(1, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 2,5
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 5).getOccupied() == true)
				{

					if (computer.getNode(2, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 5, "Hit");
					computer.setNodeColor(2, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 5, "Miss");
					computer.setNodeColor(2, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 3,5
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 5).getOccupied() == true)
				{

					if (computer.getNode(3, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 5, "Hit");
					computer.setNodeColor(3, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 5, "Miss");
					computer.setNodeColor(3, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 4,5
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 5).getOccupied() == true)
				{

					if (computer.getNode(4, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 5, "Hit");
					computer.setNodeColor(4, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 5, "Miss");
					computer.setNodeColor(4, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 5,5
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 5).getOccupied() == true)
				{

					if (computer.getNode(5, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 5, "Hit");
					computer.setNodeColor(5, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 5, "Miss");
					computer.setNodeColor(5, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 6,5
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 5).getOccupied() == true)
				{

					if (computer.getNode(6, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 5, "Hit");
					computer.setNodeColor(6, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 5, "Miss");
					computer.setNodeColor(6, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 7,5
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 5).getOccupied() == true)
				{

					if (computer.getNode(7, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 5, "Hit");
					computer.setNodeColor(7, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 5, "Miss");
					computer.setNodeColor(7, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 8,5
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 5).getOccupied() == true)
				{

					if (computer.getNode(8, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 5, "Hit");
					computer.setNodeColor(8, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 5, "Miss");
					computer.setNodeColor(8, 5, sf::Color::White);

					return 1;
				}

			}
		}
		// 9,5
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 250 && sf::Mouse::getPosition(window).y <= 290)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 5).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 5, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 5).getOccupied() == true)
				{

					if (computer.getNode(9, 5).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 5).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 5).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 5).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 5).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 5, "Hit");
					computer.setNodeColor(9, 5, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 5, "Miss");
					computer.setNodeColor(9, 5, sf::Color::White);

					return 1;
				}

			}
		}
		///ROW 7 ROW 7////
		// 0,6
		////ROW 9/////
		///0,9////
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 9).getOccupied() == true)
				{

					if (computer.getNode(0, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 9, "Hit");
					computer.setNodeColor(0, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 9, "Miss");
					computer.setNodeColor(0, 9, sf::Color::White);

					return 1;
				}

			}
		}

		////1,9////

		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 9).getOccupied() == true)
				{

					if (computer.getNode(1, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 9, "Hit");
					computer.setNodeColor(1, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 9, "Miss");
					computer.setNodeColor(1, 9, sf::Color::White);

					return 1;
				}

			}
		}

		////2,9////
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 9).getOccupied() == true)
				{

					if (computer.getNode(2, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 9, "Hit");
					computer.setNodeColor(2, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 9, "Miss");
					computer.setNodeColor(2, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////3,9////
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 9).getOccupied() == true)
				{

					if (computer.getNode(3, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 9, "Hit");
					computer.setNodeColor(3, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 9, "Miss");
					computer.setNodeColor(3, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////4,9////
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 9).getOccupied() == true)
				{

					if (computer.getNode(4, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 9, "Hit");
					computer.setNodeColor(4, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 9, "Miss");
					computer.setNodeColor(4, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////5,9////
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 9).getOccupied() == true)
				{

					if (computer.getNode(5, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 9, "Hit");
					computer.setNodeColor(5, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 9, "Miss");
					computer.setNodeColor(5, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////6,9////
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 9).getOccupied() == true)
				{

					if (computer.getNode(6, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 9, "Hit");
					computer.setNodeColor(6, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 9, "Miss");
					computer.setNodeColor(6, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////7,9////
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 9).getOccupied() == true)
				{

					if (computer.getNode(7, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 9, "Hit");
					computer.setNodeColor(7, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 9, "Miss");
					computer.setNodeColor(7, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////8,9////
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 9).getOccupied() == true)
				{

					if (computer.getNode(8, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 9, "Hit");
					computer.setNodeColor(8, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 9, "Miss");
					computer.setNodeColor(8, 9, sf::Color::White);

					return 1;
				}

			}
		}
		////9,9////
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 410 && sf::Mouse::getPosition(window).y <= 450)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 9).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 9, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 9).getOccupied() == true)
				{

					if (computer.getNode(9, 9).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 9).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 9).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 9).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 9).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 9, "Hit");
					computer.setNodeColor(9, 9, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 9, "Miss");
					computer.setNodeColor(9, 9, sf::Color::White);

					return 1;
				}

			}
		}
		//////ROW 8/////
		////0,8////
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 8).getOccupied() == true)
				{

					if (computer.getNode(0, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 8, "Hit");
					computer.setNodeColor(0, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 8, "Miss");
					computer.setNodeColor(0, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////1,8////
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 8).getOccupied() == true)
				{

					if (computer.getNode(1, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 8, "Hit");
					computer.setNodeColor(1, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 8, "Miss");
					computer.setNodeColor(1, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////2,8////
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 8).getOccupied() == true)
				{

					if (computer.getNode(2, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 8, "Hit");
					computer.setNodeColor(2, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 8, "Miss");
					computer.setNodeColor(2, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////3,8////
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 8).getOccupied() == true)
				{

					if (computer.getNode(3, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 8, "Hit");
					computer.setNodeColor(3, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 8, "Miss");
					computer.setNodeColor(3, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////4,8////
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 8).getOccupied() == true)
				{

					if (computer.getNode(4, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 8, "Hit");
					computer.setNodeColor(4, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 8, "Miss");
					computer.setNodeColor(4, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////5,8////
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 8).getOccupied() == true)
				{

					if (computer.getNode(5, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 8, "Hit");
					computer.setNodeColor(5, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 8, "Miss");
					computer.setNodeColor(5, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////6,8////
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 8).getOccupied() == true)
				{

					if (computer.getNode(6, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 8, "Hit");
					computer.setNodeColor(6, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 8, "Miss");
					computer.setNodeColor(6, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////7,8////
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 8).getOccupied() == true)
				{

					if (computer.getNode(7, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 8, "Hit");
					computer.setNodeColor(7, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 8, "Miss");
					computer.setNodeColor(7, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////8,8////
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 8).getOccupied() == true)
				{

					if (computer.getNode(8, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 8, "Hit");
					computer.setNodeColor(8, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 8, "Miss");
					computer.setNodeColor(8, 8, sf::Color::White);

					return 1;
				}

			}
		}
		////9,8////
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 370 && sf::Mouse::getPosition(window).y <= 410)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 8).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 8, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 8).getOccupied() == true)
				{

					if (computer.getNode(9, 8).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 8).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 8).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 8).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 8).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 8, "Hit");
					computer.setNodeColor(9, 8, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 8, "Miss");
					computer.setNodeColor(9, 8, sf::Color::White);

					return 1;
				}

			}
		}
		/////ROW 7////////
		////0,7////
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 7).getOccupied() == true)
				{

					if (computer.getNode(0, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 7, "Hit");
					computer.setNodeColor(0, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 7, "Miss");
					computer.setNodeColor(0, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////1,7////
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 7).getOccupied() == true)
				{

					if (computer.getNode(1, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 7, "Hit");
					computer.setNodeColor(1, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 7, "Miss");
					computer.setNodeColor(1, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////2,7////
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 7).getOccupied() == true)
				{

					if (computer.getNode(2, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 7, "Hit");
					computer.setNodeColor(2, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 7, "Miss");
					computer.setNodeColor(2, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////3,7////
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 7).getOccupied() == true)
				{

					if (computer.getNode(3, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 7, "Hit");
					computer.setNodeColor(3, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 7, "Miss");
					computer.setNodeColor(3, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////4,7////
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 7).getOccupied() == true)
				{

					if (computer.getNode(4, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 7, "Hit");
					computer.setNodeColor(4, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 7, "Miss");
					computer.setNodeColor(4, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////5,7////
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 7).getOccupied() == true)
				{

					if (computer.getNode(5, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 7, "Hit");
					computer.setNodeColor(5, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 7, "Miss");
					computer.setNodeColor(5, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////6,7////
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 7).getOccupied() == true)
				{

					if (computer.getNode(6, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 7, "Hit");
					computer.setNodeColor(6, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 7, "Miss");
					computer.setNodeColor(6, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////7,7////
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 7).getOccupied() == true)
				{

					if (computer.getNode(7, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 7, "Hit");
					computer.setNodeColor(7, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 7, "Miss");
					computer.setNodeColor(7, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////8,7////
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 7).getOccupied() == true)
				{

					if (computer.getNode(8, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 7, "Hit");
					computer.setNodeColor(8, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 7, "Miss");
					computer.setNodeColor(8, 7, sf::Color::White);

					return 1;
				}

			}
		}
		////9,7////
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 330 && sf::Mouse::getPosition(window).y <= 370)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 7).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 7, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 7).getOccupied() == true)
				{

					if (computer.getNode(9, 7).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 7).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 7).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 7).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 7).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 7, "Hit");
					computer.setNodeColor(9, 7, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 7, "Miss");
					computer.setNodeColor(9, 7, sf::Color::White);

					return 1;
				}

			}
		}
		/////ROW 6/////
		////0,6////
		if (sf::Mouse::getPosition(window).x >= 50 && sf::Mouse::getPosition(window).x <= 90 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(0, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(0, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(0, 6).getOccupied() == true)
				{

					if (computer.getNode(0, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(0, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(0, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(0, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(0, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(0, 6, "Hit");
					computer.setNodeColor(0, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(0, 6, "Miss");
					computer.setNodeColor(0, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////1,6////
		if (sf::Mouse::getPosition(window).x >= 90 && sf::Mouse::getPosition(window).x <= 130 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(1, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(1, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(1, 6).getOccupied() == true)
				{

					if (computer.getNode(1, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(1, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(1, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(1, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(1, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(1, 6, "Hit");
					computer.setNodeColor(1, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(1, 6, "Miss");
					computer.setNodeColor(1, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////2,6////
		if (sf::Mouse::getPosition(window).x >= 130 && sf::Mouse::getPosition(window).x <= 170 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(2, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(2, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(2, 6).getOccupied() == true)
				{

					if (computer.getNode(2, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(2, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(2, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(2, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(2, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(2, 6, "Hit");
					computer.setNodeColor(2, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(2, 6, "Miss");
					computer.setNodeColor(2, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////3,6////
		if (sf::Mouse::getPosition(window).x >= 170 && sf::Mouse::getPosition(window).x <= 210 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(3, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(3, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(3, 6).getOccupied() == true)
				{

					if (computer.getNode(3, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(3, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(3, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(3, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(3, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(3, 6, "Hit");
					computer.setNodeColor(3, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(3, 6, "Miss");
					computer.setNodeColor(3, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////4,6////
		if (sf::Mouse::getPosition(window).x >= 210 && sf::Mouse::getPosition(window).x <= 250 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(4, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(4, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(4, 6).getOccupied() == true)
				{

					if (computer.getNode(4, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(4, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(4, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(4, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(4, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(4, 6, "Hit");
					computer.setNodeColor(4, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(4, 6, "Miss");
					computer.setNodeColor(4, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////5,6////
		if (sf::Mouse::getPosition(window).x >= 250 && sf::Mouse::getPosition(window).x <= 290 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(5, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(5, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(5, 6).getOccupied() == true)
				{

					if (computer.getNode(5, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(5, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(5, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(5, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(5, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(5, 6, "Hit");
					computer.setNodeColor(5, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(5, 6, "Miss");
					computer.setNodeColor(5, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////6,6////
		if (sf::Mouse::getPosition(window).x >= 290 && sf::Mouse::getPosition(window).x <= 330 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(6, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(6, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(6, 6).getOccupied() == true)
				{

					if (computer.getNode(6, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(6, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(6, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(6, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(6, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(6, 6, "Hit");
					computer.setNodeColor(6, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(6, 6, "Miss");
					computer.setNodeColor(6, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////7,6////
		if (sf::Mouse::getPosition(window).x >= 330 && sf::Mouse::getPosition(window).x <= 370 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(7, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(7, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(7, 6).getOccupied() == true)
				{

					if (computer.getNode(7, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(7, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(7, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(7, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(7, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(7, 6, "Hit");
					computer.setNodeColor(7, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(7, 6, "Miss");
					computer.setNodeColor(7, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////8,6////
		if (sf::Mouse::getPosition(window).x >= 370 && sf::Mouse::getPosition(window).x <= 410 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(8, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(8, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(8, 6).getOccupied() == true)
				{

					if (computer.getNode(8, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(8, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(8, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(8, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(8, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(8, 6, "Hit");
					computer.setNodeColor(8, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(8, 6, "Miss");
					computer.setNodeColor(8, 6, sf::Color::White);

					return 1;
				}

			}
		}
		////9,6////
		if (sf::Mouse::getPosition(window).x >= 410 && sf::Mouse::getPosition(window).x <= 450 && sf::Mouse::getPosition(window).y >= 290 && sf::Mouse::getPosition(window).y <= 330)
		{
			window.clear(sf::Color::White);
			if (computer.getNode(9, 6).getHitMiss() == "None")
			{
				computer.setNodeColor(9, 6, sf::Color::Blue);
			}
			x = 0;
			y = 0;
			while (x != 10)
			{

				while (y != 10)
				{
					window.draw(computer.getNode(x, y));
					window.draw(player.getNode(x, y));
					y += 1;

				}
				y = 0;
				x += 1;

			}
			window.draw(compText);
			window.draw(playerText);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

				if (computer.getNode(9, 6).getOccupied() == true)
				{

					if (computer.getNode(9, 6).getShip() == "Carrier")
					{
						carrierC.setHits(carrierC.getHits() + 1);
					}
					else if (computer.getNode(9, 6).getShip() == "Battleship")
					{
						battleshipC.setHits(battleshipC.getHits() + 1);
					}
					else if (computer.getNode(9, 6).getShip() == "Cruiser")
					{
						cruiserC.setHits(cruiserC.getHits() + 1);
					}
					else if (computer.getNode(9, 6).getShip() == "Submarine")
					{
						subC.setHits(subC.getHits() + 1);
					}
					else if (computer.getNode(9, 6).getShip() == "Destroyer")
					{
						destroyerC.setHits(destroyerC.getHits() + 1);
					}

					computer.setNodeHitMiss(9, 6, "Hit");
					computer.setNodeColor(9, 6, sf::Color::Red);


					return 1;
				}
				else
				{

					computer.setNodeHitMiss(9, 6, "Miss");
					computer.setNodeColor(9, 6, sf::Color::White);

					return 1;
				}

			}
		}


		return success;


	}