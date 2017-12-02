#include "Boat.h"


// Member // 
/*************************************************************
* Function: Boat()                                           *
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

Boat::Boat(sf::Vector2f const &pos, sf::Color const &newColor, sf::Vector2f const &size, int const newHits)
{

	this->setPosition(pos);
	this->setFillColor(newColor);
	this->setSize(size);
	this->hits = newHits;

}



// Member // 
/*************************************************************
* Function: ~Boat()                                          *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class destructor that      *
*              deletes data.                                 *
* Input parameters: None                                     *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's data will be deleted              *
*************************************************************/

Boat::~Boat()
{

}



// Member // 
/*************************************************************
* Function: getHits()                                        *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class getter that returns  *
*              the object's hits.                            *
* Input parameters: None                                     *
* Returns: Hits                                              *
* Preconditions: Object must exist                           *
* Postconditions: object's hits will be returned             *
*************************************************************/

int Boat::getHits() const
{

	return this->hits;

}



// Member // 
/*************************************************************
* Function: setHits()                                        *
* Date Created: 11/28/2017                                   *
* Date Last Modified: 11/28/2017                             *
* Description: This function is a class setter that assigns  *
*              new hits to the object.                       *
* Input parameters: New hits                                 *
* Returns: None                                              *
* Preconditions: Object must exist                           *
* Postconditions: New hits will be assigned                  *
*************************************************************/

void Boat::setHits(int const newHits)
{

	this->hits = newHits;

}