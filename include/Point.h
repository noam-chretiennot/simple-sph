#ifndef POINT_H
#define POINT_H
#include <SFML/Graphics.hpp>

class Point
{
public:
    Point(float x, float y, float size, float density, float pressure, float mass, float ax, float ay, float vx, float vy);
    Point();

    float size;
    float density, pressure, mass;
    float x, y;
    float ax, ay;
    float vx, vy;

    void update(float dt);
    void display(sf::RenderWindow& window);
    void display_updated(sf::RenderWindow& window, float dt);
};
#endif
