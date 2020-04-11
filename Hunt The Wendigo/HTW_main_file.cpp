// HTW_main_file.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 2/27/2020
// Last updated on 2/27/2020

#include <iostream>

#include "lib/FastNoise/FastNoise.h"
#include "lib/tilemap.hpp"

int main()
{
    int posX = 0;
    int posY = 0;

    // create the window
    sf::RenderWindow window(sf::VideoMode(512, 512), "sfml floating");
    window.setPosition(sf::Vector2i(800, 50));

    // Limit the framerate to something a bit sane
    window.setFramerateLimit(60);

    // Define a simple static tilemap.
    int level[32*32];

    FastNoise noise;
    //noise.SetNoiseType(FastNoise::Perlin);
    int seed;
    std::cin >> seed;
    noise.SetSeed(seed);

    /*for (int x = 1; x <= 16; x++) {
        for (int y = 1; y <= 16; y++) {
           level[x * y + y - 1] = (int)(noise.GetValue(x * 16, y * 16, 0) + 1) * 3;
           std::cout << x*y+y-1 << ' ' << level[x*y+y] <<  "   ";
        }
        std::cout << std::endl;
    }*/

    // Generate the tilemap instance and load the sprites
    TileMap map;
    map.load("./assets/spritesheet.png", 16, 32, 32);
    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                posX--;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                posX++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                posY++;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                posY--;
            }
        }

        for (int i = 0; i < 32*32; i++) {
            level[i] = (noise.GetValue((i / 32 - posY) * 16, ((i % 32) + posX) * 16, 0) + 1) * 2;
            if (level[i] < 0) level[i] = 0;
            if (level[i] > 3) level[i] = 3;
        }


        map.set(level);

        // Clear the window with a white background
        window.clear(sf::Color(255, 255, 255, 255));

				// Draw the texture map to screen
        window.draw(map);

				// Refresh the window
        window.display();
    }

    return 0;
}
