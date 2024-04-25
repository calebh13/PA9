#pragma once
#include "CentipedePart.hpp"

class CentipedeBody : public CentipedePart
{

public:
	CentipedeBody(unsigned int scale = 1, const sf::Vector2f& pos = sf::Vector2f(0, 0),
		const sf::Texture& texture = sf::Texture(), unsigned int health = 1, unsigned int interpolationFrames = 15, enum dir d = DOWN,
		CentipedePart* nodeInFront = nullptr) : CentipedePart(scale, pos, texture, health, interpolationFrames, d)
	{
		this->nodeInFront = nodeInFront;
		nodeInFront->setNodeBehind(this);
	}
	void collideWith(GameObject* other);
	enum action isDead(void) const;
	void setFrontNode(CentipedePart* frontNode);
	CentipedePart* getFrontNode(void) const;
private:
	CentipedePart* nodeInFront;
	void genNewPosition(const sf::RenderWindow& window);
};