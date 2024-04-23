#pragma once
#include "GameObject.hpp"
#include "Grid.hpp"
#include "CentipedePart.hpp"


class CentipedeHead : public CentipedePart
{

public:
	using CentipedePart::CentipedePart;
	void collideWith(GameObject* other);
	enum action isDead(void) const;
private:
	void genNewPosition(const sf::RenderWindow& window);
};