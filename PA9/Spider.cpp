#include "Spider.hpp"

void Spider::collideWith(GameObject* other)
{
	Bullet* bullet = dynamic_cast<Bullet*>(other);
	if (bullet != nullptr)
	{
		bullet->hit();
		this->health = 0;
		return;
	}
}
