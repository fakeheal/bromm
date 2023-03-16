#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "Player.h"

Player::Player(float x, float y, float width, float height)
{
    this->position = {x, y};
    this->dimensions = {width, height};
    this->speed = PLAYER_MOVE_SPEED;
}

void Player::setPositionX(float unit)
{
    this->setPosition(unit, this->getPosition().y);
}

void Player::setPositionY(float unit)
{
    this->setPosition(this->getPosition().x, unit);
}

void Player::draw() const
{
    const float x = this->getPosition().x - (this->getDimensions().x / 2);
    const float y = this->getPosition().y - this->getDimensions().y;

    DrawRectangleV({x, y}, this->getDimensions(), SKYBLUE);
}

Vector2 Player::getPosition() const
{
    return this->position;
}

Vector2 Player::getDimensions() const
{
    return this->dimensions;
}

bool Player::getCanJump() const
{
    return this->canJump;
}

float Player::getSpeed() const
{
    return this->speed;
}

Rectangle Player::getRectangle() const
{
    return {
        this->getPosition().x,
        this->getPosition().y,
        this->getDimensions().x,
        this->getDimensions().y,
    };
}

void Player::setCanJump(bool value)
{
    this->canJump = value;
}

void Player::setSpeed(float value)
{
    this->speed = value;
}

void Player::setPosition(float x, float y)
{
    this->position = {x, y};
}

std::ostream &operator<<(std::ostream &out, const Player &p)
{
    out << "Player (" << &p << ") :: Speed: "
        << p.getSpeed() << ", X: "
        << p.getPosition().x
        << ", Y: "
        << p.getPosition().y
        << ", Can Jump: "
        << (p.getCanJump() ? "Yes" : "No");

    return out;
}