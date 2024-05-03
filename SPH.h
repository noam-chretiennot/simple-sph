#ifndef SPH_H
#define SPH_H
#include <SFML/Graphics.hpp>
#include "Point.h"

class SPH
{
public:
    std::vector<Point> points;
    float gravity;
    
    SPH() : gravity(9.81) {}
    SPH(float gravity) : gravity(gravity) {}
    void addGrid(int n, float density, float start_x, float start_y, float pressure, float mass, float size);
    void addRandom(int n, float density, float pressure, float mass, float size);
    void display(sf::RenderWindow& window);
    void update(float dt);
    void display_updated(sf::RenderWindow& window, float dt);
    float* kernelGradient(Point p1, Point p2);
};
#endif
