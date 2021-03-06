#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

class Tile;
class Entity;
class Position;

// A Maze is a grid of Tile objects.
class Maze {
private:
  // TODO: add fields
  int width;
  int height;
  std::vector<Tile *> *maze; // the 2D representation of the maze
  
  // disallow copy ctor and assignment operator
  Maze(const Maze &);
  Maze &operator=(const Maze &);

public:
  Maze(int width, int height);
  ~Maze();

  // Get the width of the Maze
  int getWidth() const;

  // Get the height of the Maze
  int getHeight() const;

  // Return true if the specified position is in bounds
  // according to the Maze's width and height.
  bool inBounds(const Position &pos) const;

  // Set a Tile at the specified Position.  The Maze assumes responsibility
  // for deleting the Tile.
  void setTile(const Position &pos, Tile *tile);

  // Get the Tile at the specified Position.
  const Tile *getTile(const Position &pos) const;

  // Read a description of a Maze from specified istream, and return it.
  static Maze *read(std::istream &in);

private:
  // Add your own private member functions

  // Convert a 2D position into its corresponding 1D index.
  int get1DPos(const Position &pos) const;
  
  // Get the x coordinate given a 1D index.
  int getRow(int i) const;
  
  // Get the y coordinate given a 1D index.
  int getCol(int i) const;

};

#endif
