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
     * Load spritesheet
     *
     * @param tex the path to the texture to use for this TileMap
     * @param tileSize Size the tiles should be drawn on-screen
     * @param width Width of the map
     * @param height Height of the map
     * @return if the loading of the map was successful
     */
    bool load(const char * tex, int tileSize, int width, int height);

    /**
     * Sets the map of the TileMap
     *
     * @param tiles Map of textures to be drawn
     */
    void set(const int* tiles);

  private:
  virtual void draw (sf::RenderTarget& target, sf::RenderStates states) const;
  sf::VertexArray vertices;
  sf::Texture tileset;
  int width = 0;
  int height = 0;
  int tileSize = 0;
};

#endif
