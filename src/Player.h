class Player
{
public:
    Player(float x, float y);
    void moveLeft(float unit);
    void moveRight(float unit);
    void moveUp(float unit);
    void moveDown(float unit);

    Vector2 getPosition();

private:
    Vector2 position;
};