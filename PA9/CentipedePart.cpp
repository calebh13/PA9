#include "CentipedePart.hpp"

void CentipedePart::setNodeBehind(CentipedePart* behind)
{
    this->nodeBehind = behind;
}

CentipedePart* CentipedePart::getNodeBehind(void) const
{
    return this->nodeBehind;
}

sf::Vector2f CentipedePart::getLastWaypoint(void) const
{
    return this->lastWaypoint;
}
