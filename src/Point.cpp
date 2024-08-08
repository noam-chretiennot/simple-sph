#include "Point.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Point::Point(float x, float y, float size, float density, float pressure, float mass, float ax, float ay, float vx, float vy) 
: x(x), y(y), size(size), density(density), pressure(pressure), mass(mass), ax(ax), ay(ay), vx(vx), vy(vy) {}

Point::Point() : x(0), y(0), size(0), density(0), pressure(0), mass(0), ax(0), ay(0), vx(0), vy(0) {}

/*Point(const Point& p) 
: x(p.x), y(p.y), size(p.size), density(p.density), pressure(p.pressure), mass(p.mass) {
    ax = 0;
    ay = 0;
    vx = 0;
    vy = 0;
}*/


void Point::update(float dt)
{
    std::cout << "dx :" << vx * dt << " dy :" << vy * dt << std::endl;
    x += vx * dt;
    y += vy * dt;
    vx += ax * dt;
    vy += ay * dt;
    

    int dist = 0;
    if (x < dist) {
        //vx = -conservation*vx;
        x=dist;
    }
    if (x > 800-dist) {
        //vx = -conservation*vx;
        x=800-dist;
    }
    if (y < dist) {
        //vy = -conservation*vy;
        y=dist;
    }
    if (y > 600-dist) {
        //ay = -conservation*vy;
        y=600-dist;
    }
}

void Point::display(sf::RenderWindow& window)
{
    /*sf::CircleShape density_circle(density/2);
    density_circle.setFillColor(sf::Color::Red);
    density_circle.setPosition(x-density/2, y-density/2);
    window.draw(density_circle);*/

    sf::CircleShape circle(size);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(x-size, y-size);
    window.draw(circle);
}

void Point::display_updated(sf::RenderWindow& window, float dt)
{
    update(dt);
    display(window);
}
