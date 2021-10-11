#include <stdio.h>

#include "actor.h"

Actor::Actor(int x, int y)
{
	this->setXY(x, y);
}

void Actor::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}
