#include "ScreenNode.h"


// Member // 
/*************************************************************
* Function: ScreenNode()                                     *
* Date Created: 11/27/2017                                   *
* Date Last Modified: 11/27/2017                             *
* Description: This function is a class constructor that     *
*              initializes object and validates data.        *
* Input parameters: color, size, position                    *
* Returns: None                                              *
* Preconditions: Program must be running                     *
* Postconditions: object will be initialized and data        *
*                 validated                                  *
*************************************************************/

ScreenNode::ScreenNode(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, string const &newHitMiss, bool const &newOccupied, string const &newShip)
{

	this->setFillColor(newColor);
	this->setSize(size);
	this->setPosition(pos);
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(1);
	this->hitMiss = newHitMiss;
	this->occupied = newOccupied;
	this->ship = newShip;

}



// Member // 
/*************************************************************
* Function: ~ScreenNode()                                    *
* Date Created: 11/27/2017                                   *
* Date Last Modified: 11/27/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

ScreenNode::~ScreenNode()
{

}



// Member // 
/*************************************************************
* Function: getHitMiss()                                     *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class getter that returns  *
*              the object's hit or miss.                     *
* Input parameters: None                                     *
* Returns: hit or miss                                       *
* Preconditions: Object must exist                           *
* Postconditions: object's hit or miss will be returned      *
*************************************************************/

string ScreenNode::getHitMiss() const
{

	return this->hitMiss;

}



// Member // 
/*************************************************************
* Function: setHitMiss()                                     *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class setter that assigns  *
*              new hit or miss to the object.                *
* Input parameters: New hit or miss                          *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New hit or miss will be assigned           *
*************************************************************/

void ScreenNode::setHitMiss(string const newHitMiss)
{

	this->hitMiss = newHitMiss;

}



// Member // 
/*************************************************************
* Function: changeColor()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function updates the object's color based*
*              on whether it is a hit or miss.               *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: Object's color will be updated             *
*************************************************************/

void ScreenNode::changeColor()
{

	if (this->hitMiss == "Hit")
	{
		this->setFillColor(sf::Color::Red);
	}
	else if (this->hitMiss == "Miss")
	{
		this->setFillColor(sf::Color::White);
		this->setOutlineThickness(5);
	}
	else
	{

	}

}



// Member // 
/*************************************************************
* Function: getOccupied()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class getter that returns  *
*              the object's occupied bool.                   *
* Input parameters: None                                     *
* Returns: Bool                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's occupied bool will be returned    *
*************************************************************/

bool ScreenNode::getOccupied() const
{

	return this->occupied;

}



// Member // 
/*************************************************************
* Function: setOccupied()                                    *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class setter that assigns  *
*              new occupied bool to the object.              *
* Input parameters: Bool                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New occupied bool will be assigned         *
*************************************************************/

void ScreenNode::setOccupied(bool const newOccupied)
{

	this->occupied = newOccupied;

}



// Member // 
/*************************************************************
* Function: getShip()                                        *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class getter that returns  *
*              the object's ship.                            *
* Input parameters: None                                     *
* Returns: string                                            *
* Preconditions: Object must exist                           *
* Postconditions: object's ship will be returned             *
*************************************************************/

string ScreenNode::getShip() const
{

	return this->ship;

}



// Member // 
/*************************************************************
* Function: setShip()                                        *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class setter that assigns  *
*              new ship to the object.                       *
* Input parameters: Ship                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New ship will be assigned                  *
*************************************************************/

void ScreenNode::setShip(string const newShip)
{

	this->ship = newShip;

}