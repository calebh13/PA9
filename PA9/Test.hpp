/*
	Worked on by Elliot and Jace
	4/24/24
*/

#pragma once
#include "GameWrapper.hpp"
#include "Grid.hpp"

class Test
{
	friend class GameWrapper;
public:
	//check is pointers in the Wrapper are initialized
	void testRoundSetup();
	//play all the sounds one by one
	void testSound();
	//test grid functions
	void testGrid();

	friend class GameWrapper;

public:
	void testTextures(void);
	void testObjMovement(void);
};

