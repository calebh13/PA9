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

void CentipedePart::pause(void)
{
    this->setPosition(lastWaypoint);
    //--moveFrame;
    if (this->nodeBehind != nullptr)
    {
        this->nodeBehind->forceRegeneration();
    }
}

void CentipedePart::forceRegeneration(void)
{
    this->moveFrame = this->interpolationFrames;
    if (this->nodeBehind != nullptr)
    {
        this->nodeBehind->forceRegeneration();
    }
}
