#include <SFML/Graphics.hpp>

#include "Point.h"
#include "SPH.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SPH");
    //center the window 
    sf::VideoMode screenSize = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(screenSize.width/2-400, screenSize.height/2-300));

    SPH sph(0);

    int n = 5000;
    float density = 10;
    float pressure = 1;
    float mass = 0.1;
    float size = 2;
    float start_x = 100;
    float start_y = 100;

    sph.addRandom(n, density, pressure, mass, size);
    //sph.addGrid(n, density, start_x, start_y, pressure, mass, size);
    
    /* sph.addGrid(4, density, 0, 560, pressure, mass, size);
    for (int i = -20; i < (int) 800/20; i++)
    {
        sph.addGrid(4, density, i*20, 500, pressure, mass, size);
    }*/


    float dt = 10;
    int cpt = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        sph.display_updated(window, dt);
        window.display();
        cpt++;
    }

    
    return 0;
}
