
#include "raymath.h"
#include "Player.h"

Player::Player(float x, float y)
{
    this->position = {x, y};
}

void Player::moveLeft(float unit)
{
    this->position.x += unit;
}

void Player::moveRight(float unit)
{
    this->position.x -= unit;
}

void Player::moveUp(float unit)
{
    this->position.y -= unit;
}

void Player::moveDown(float unit)
{
    this->position.y += unit;
}

Vector2 Player::getPosition() {
    return this->position;
}