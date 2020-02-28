// HTW_main_file.cpp
// Justyn Durnford
// Izac Lorimer
// Created on 2/27/2020
// Last updated on 2/27/2020


#include "tilemap.hpp"

/**
 * Sum numbers in a vector.
 *
 * @param tex the texture to use for this TileMap
 * @param tileSize How big each tile should be drawn on screen
 * @param tiles Map of textures to be drawn
 * @param width Width of the texture map in tiles
 * @param height Height of the texture map in tiles.
 * @return if the loading of the map was successful
 */
bool TileMap::load(const char* tilesetPath, int tileSize, const int* tiles,
  unsigned int width, unsigned int height)
{
  tileset.loadFromFile(tilesetPath);
  // resize the vertex array to fit the level size
  vertices.setPrimitiveType(sf::Quads);
  vertices.resize(width * height * 4);

  // populate the vertex array, with one quad per tile
  for (unsigned int i = 0; i < width; ++i) {
    for (unsigned int j = 0; j < height; ++j) {
      // get the current tile number
      int tileNumber = tiles[i + j * width];

      // find its position in the tileset texture
      int tx = tileNumber * tileset.getSize().y;
      int ty = 0;

      // get a pointer to the current tile's quad
      sf::Vertex* quad = &vertices[(i + j * width) * 4];

      // define its 4 corners
      quad[0].position = sf::Vector2f(i * tileSize, j * tileSize);
      quad[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
      quad[2].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);
      quad[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);

      // define its 4 texture coordinates
      quad[0].texCoords = sf::Vector2f(tx, ty);
      quad[1].texCoords = sf::Vector2f(tx + tileset.getSize().y, ty);
      quad[2].texCoords = sf::Vector2f(tx + tileset.getSize().y, ty + tileset.getSize().y);
      quad[3].texCoords = sf::Vector2f(tx, ty + tileset.getSize().y);
    }
  }
  return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // apply the transform
  states.transform *= getTransform();

  // apply the tileset texture
  states.texture = &tileset;

  // draw the vertex array
  target.draw(vertices, states);
}
