#include <raylib.h>
#include "EnvironmentItem.h"

EnvironmentItem::EnvironmentItem(float x, float y, float width, float height, bool isBlocking, Color color)
{
    this->position = {x, y};
    this->dimensions = {width, height};
    this->color = color;
    this->isBlocking = isBlocking;
}

Vector2 EnvironmentItem::getPosition() const
{
    return this->position;
}

Vector2 EnvironmentItem::getDimensions() const
{
    return this->dimensions;
}

bool EnvironmentItem::getIsBlocking() const
{
    return this->isBlocking;
}

Color EnvironmentItem::getColor() const
{
    return this->color;
}

Rectangle EnvironmentItem::getRectangle() const
{
    return {
        this->getPosition().x,
        this->getPosition().y,
        this->getDimensions().x,
        this->getDimensions().y,
    };
}

void EnvironmentItem::setPosition(float x, float y)
{
    this->position = {x, y};
}

void EnvironmentItem::setDimensions(float width, float height)
{
    this->position = {width, height};
}

void EnvironmentItem::setIsBlocking(bool value)
{
    this->isBlocking = value;
}

void EnvironmentItem::setColor(Color value)
{
    this->color = value;
}