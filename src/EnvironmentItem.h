
#include <raylib.h>
#ifndef ENVIRONMENT_ITEM_H
#define ENVIRONMENT_ITEM_H

class EnvironmentItem
{

public:
    EnvironmentItem(float x, float y, float width, float height, bool isBlocking, Color color);

    Vector2 getPosition() const;
    Vector2 getDimensions() const;
    bool getIsBlocking() const;
    Color getColor() const;
    Rectangle getRectangle() const;

    void setPosition(float x, float y);
    void setDimensions(float width, float height);
    void setIsBlocking(bool value);
    void setColor(Color value);

private:
    Vector2 position;
    Vector2 dimensions;
    bool isBlocking;
    Color color;
};

#endif