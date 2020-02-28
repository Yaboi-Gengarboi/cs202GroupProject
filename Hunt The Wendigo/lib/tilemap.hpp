// HTW_main_file.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 2/27/2020
// Last updated on 2/27/2020


#ifndef TILEMAP_INCLUDE
#define TILEMAP_INCLUDE

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
  public:
    /**
     * Sum numbers in a vector.
     *
     * @param tex the path to the texture to use for this TileMap
     * @param tileSize How big each tile should be drawn on screen
     * @param tiles Map of textures to be drawn
     * @param width Width of the texture map in tiles
     * @param height Height of the texture map in tiles.
     * @return if the loading of the map was successful
     */
    bool load(const char * tilesetPath, int tileSize, const int* tiles,
      unsigned int width, unsigned int height);

  private:
  virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray vertices;
  sf::Texture tileset;
};

#endif
