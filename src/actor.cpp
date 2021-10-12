#include <stdio.h>
#include <string>

#include "actor.h"

std::string Actor::to_string()
{
	return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}

Actor::Actor(int x, int y, int height, int width)
{
	this->set_pos(x, y);
	this->set_height(height);
	this->set_width(width);
}

void Actor::set_pos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Actor::set_height(int height)
{
	this->height = height;
}

void Actor::set_width(int width)
{
	this->width = width;
}
