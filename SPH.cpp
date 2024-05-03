#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Point.h"
#include "SPH.h"



void SPH::addGrid(int n, float density, float start_x, float start_y, float pressure, float mass, float size)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            points.emplace_back(start_x + i * density+ density*(j%2)/2, start_y + j * density, size, density, pressure, mass, 0, 0, 0, 0);
        }
    }
}

void SPH::addRandom(int n, float density, float pressure, float mass, float size)
{
    for (int i = 0; i < n; i++)
    {
        points.emplace_back(rand()%800, rand()%600, size, density, pressure, mass, 0, 0, 0, 0);
    }
}

void SPH::display(sf::RenderWindow& window)
{
    for (int i = 0; i < points.size(); i++)
    {
        points[i].display(window);
    } 
}

void SPH::update(float dt)
{
    for (int i = 0; i < points.size(); i++)
    {
        points[i].ax = 0;
        points[i].ay = gravity;

        for (int j = 0; j < points.size(); j++)
        {
            if (i != j)
            {
                float* gradient = kernelGradient(points[i], points[j]);

                points[i].ax += gradient[0];
                points[i].ay += gradient[1];
                //std::cout << "ax :" << points[i].ax << " ay :" << points[i].ay << std::endl;
                
                delete[] gradient;
            }
        }
    }
    for (int i = 0; i < points.size(); i++)
    {
        points[i].update(dt);
    }
}

void SPH::display_updated(sf::RenderWindow& window, float dt)
{
    update(dt);
    display(window);
}

float* SPH::kernelGradient(Point p1, Point p2)
{
    float* gradient = new float[2];
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dxy = sqrt(dx*dx + dy*dy);
    float h = 0.5;
    int dense = p1.density;

    if (dxy < p1.density)
    {
        gradient[0] = h*p2.mass*(-2*dx/pow(dense,2) + dx*dxy*3/pow(dense,3)); // factored by 3/pi = 1
        gradient[1] = h*p2.mass*(-2*dy/pow(dense,2) + dy*dxy*3/pow(dense,3));
        // std::cout << "h :" << h << " mass :" << p2.mass << " dx :" << dx << " dy :" << dy << " dxy :" << dxy << " gradient[0] :" << gradient[0] << " gradient[1] :" << gradient[1] << std::endl;
    } else if (dxy < 2*p1.density)
    {
        // gradient of (2-dxy)^3 * 3/12pi
        gradient[0] = -h*p2.mass*dx*pow(2-dxy/dense,2)/(2*dxy*dense)/8;
        gradient[1] = -h*p2.mass*dy*pow(2-dxy/dense,2)/(2*dxy*dense)/8;

    } else
    {
        gradient[0] = 0;
        gradient[1] = 0;
    }
    

    return gradient;
}