#ifndef PLAYER_H
#define PLAYER_H

#define PLAYER_SIZE 40.0f
#define PLAYER_JUMP_SPEED 350.0f
#define PLAYER_MOVE_SPEED 200.0f

class Player
{
public:
    Player(float x, float y, float width, float height);

    void draw() const;
    Vector2 getPosition() const;
    Vector2 getDimensions() const;
    bool getCanJump() const;
    float getSpeed() const;

    Rectangle getRectangle() const;

    void setCanJump(bool value);
    void setSpeed(float value);
    void setPosition(float x, float y);
    void setPositionX(float unit);
    void setPositionY(float unit);

    friend std::ostream &operator<<(std::ostream &out, const Player &p);

private:
    float speed;
    bool canJump;
    Vector2 position;
    Vector2 dimensions;
};

#endif