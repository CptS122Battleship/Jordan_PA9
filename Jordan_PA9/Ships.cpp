#include "Ships.h"


// Aircraft Carrier //
// Member // 
/*************************************************************
* Function: AircraftCarrier()                                *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

AircraftCarrier::AircraftCarrier(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->setHits(newHits);

}



// Aircraft Carrier //
// Member // 
/*************************************************************
* Function: ~AircraftCarrier()                               *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

AircraftCarrier::~AircraftCarrier()
{

}



// Aircraft Carrier //
// Member // 
/*************************************************************
* Function: isDestroyed()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function determines if the ship is       *
*              destroyed.                                    *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: ship's condition will be determined        *
*************************************************************/

bool AircraftCarrier::isDestroyed()
{
	if (this->getHits() == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// Battleship //
// Member // 
/*************************************************************
* Function: Battleship()                                     *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

Battleship::Battleship(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->setHits(newHits);

}



// Battleship //
// Member // 
/*************************************************************
* Function: ~Battleship()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Battleship::~Battleship()
{

}



// Battleship //
// Member // 
/*************************************************************
* Function: isDestroyed()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function determines if the ship is       *
*              destroyed.                                    *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: ship's condition will be determined        *
*************************************************************/

bool Battleship::isDestroyed()
{
	if (this->getHits() == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// Cruiser //
// Member // 
/*************************************************************
* Function: Cruiser()                                        *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

Cruiser::Cruiser(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->setHits(newHits);

}



// Cruiser //
// Member // 
/*************************************************************
* Function: ~Cruiser()                                       *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Cruiser::~Cruiser()
{

}



// Cruiser //
// Member // 
/*************************************************************
* Function: isDestroyed()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function determines if the ship is       *
*              destroyed.                                    *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: ship's condition will be determined        *
*************************************************************/

bool Cruiser::isDestroyed()
{
	if (this->getHits() == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// Submarine //
// Member // 
/*************************************************************
* Function: Submarine()                                      *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

Submarine::Submarine(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->setHits(newHits);

}



// Submarine //
// Member // 
/*************************************************************
* Function: ~Submarine()                                     *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Submarine::~Submarine()
{

}



// Submarine //
// Member // 
/*************************************************************
* Function: isDestroyed()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function determines if the ship is       *
*              destroyed.                                    *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: ship's condition will be determined        *
*************************************************************/

bool Submarine::isDestroyed()
{
	if (this->getHits() == 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// Destroyer //
// Member // 
/*************************************************************
* Function: Destroyer()                                      *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

Destroyer::Destroyer(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->setHits(newHits);

}



// Destroyer //
// Member // 
/*************************************************************
* Function: ~Destroyer()                                     *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Destroyer::~Destroyer()
{

}



// Destroyer //
// Member // 
/*************************************************************
* Function: isDestroyed()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function determines if the ship is       *
*              destroyed.                                    *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: ship's condition will be determined        *
*************************************************************/

bool Destroyer::isDestroyed()
{
	if (this->getHits() == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}