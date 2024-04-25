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
	//test if getGridPos gives correct converitions
	void testGetGrigPos();
	//test snapToGrid
	void testSnapToGrid();
	//test getGridIndices
	void testgetGridIndices();
};

