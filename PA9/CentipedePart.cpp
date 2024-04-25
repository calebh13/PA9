/*
    Caleb

    Description: CPP File for centipede

// History: 4/24/24 - Class was created and implimented initially by Caleb

*/

#include "CentipedePart.hpp"


/*************************************************************
* Function: setNodeBehind()                                  *
* Description: Sets the new behind node of the centipede node*
* Input parameters: Pointer to new node         		    *
* Returns: Nothing                                          *
* Preconditions: Pointer cannot be null                     *
* Postconditions: Behind is set				                *
*************************************************************/
void CentipedePart::setNodeBehind(CentipedePart* behind)
{
    this->nodeBehind = behind;
}

/*************************************************************
* Function: getNodeBehind()                                  *
* Description: gets the behind node of the centipede node*
* Input parameters: None     								*
* Returns: Head Node                                        *
* Preconditions: None					                    *
* Postconditions: None      				                *
*************************************************************/
CentipedePart* CentipedePart::getNodeBehind(void) const
{
    return this->nodeBehind;
}

/*************************************************************
* Function: getLastWaypoint()                                *
* Description: gets the last waypoint of the centipede node *
* Input parameters: None     								*
* Returns: Last set up valid moves                          *
* Preconditions: None					                    *
* Postconditions: None      				                *
*************************************************************/
sf::Vector2f CentipedePart::getLastWaypoint(void) const
{
    return this->lastWaypoint;
}

/*************************************************************
* Function: pause()                                         *
* Description: Mystery function. Even Caleb does not understand*
                Cannot be removed without error             *
* Input parameters: None     								*
* Returns: None                                             *
* Preconditions: None					                    *
* Postconditions:  Actions taken			                *
*************************************************************/
void CentipedePart::pause(void)
{
    this->setPosition(lastWaypoint);
    //--moveFrame;
    if (this->nodeBehind != nullptr)
    {
        this->nodeBehind->forceRegeneration();
    }
}

/*************************************************************
* Function: heal()											*
* Description: Adds health to an object 					*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Health changed      					    *
*************************************************************/
void CentipedePart::heal(void)
{
    this->health = 1;
}

/*************************************************************
* Function: forceRegeneration() 							*
* Description: Forces the centipede to regen				*
* Input parameters: None									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Centipede Regens     					    *
*************************************************************/
void CentipedePart::forceRegeneration(void)
{
    this->moveFrame = this->interpolationFrames;
    if (this->nodeBehind != nullptr)
    {
        this->nodeBehind->forceRegeneration();
    }
}

/*************************************************************
* Function: ReverseDir()									*
* Description: Reverse the direction of the centipede		*
* Input parameters: New Dir									*
* Returns: None											    *
* Preconditions: N/A							            *
* Postconditions: Direction Changes    					    *
*************************************************************/
void reverseDir(dir& d)
{
    d = static_cast<dir>((d + 2) % 4);
}