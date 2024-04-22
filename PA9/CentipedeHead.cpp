#include "CentipedeHead.hpp"

void CentipedeHead::collideWith(GameObject* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->health = 0;
		return;
	}
}

//void CentipedeHead::genNewPosition(const sf::RenderWindow& window)
//{
//
//}
