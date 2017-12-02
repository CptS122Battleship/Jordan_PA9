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
		while (randomY > 5)
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
		while (randomX > 5)
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

				
				return 1;
			}
			else
			{

				computer.setNodeHitMiss(0, 0, "Miss");
				computer.setNodeColor(0, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(1, 0, "Miss");
				computer.setNodeColor(1, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(2, 0, "Miss");
				computer.setNodeColor(2, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(3, 0, "Miss");
				computer.setNodeColor(3, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(4, 0, "Miss");
				computer.setNodeColor(4, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(5, 0, "Miss");
				computer.setNodeColor(5, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(6, 0, "Miss");
				computer.setNodeColor(6, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(7, 0, "Miss");
				computer.setNodeColor(7, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(8, 0, "Miss");
				computer.setNodeColor(8, 0, sf::Color::White);

				return 1;
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


				return 1;
			}
			else
			{

				computer.setNodeHitMiss(9, 0, "Miss");
				computer.setNodeColor(9, 0, sf::Color::White);

				return 1;
			}

		}
	}

	return 1;
	
}