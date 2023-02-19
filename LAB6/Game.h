#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Insect.h"

class Insect;

class Game
{
private:
  int generateRandomNumber(int startRange, int endRange) const; //random number generator

public:
  Game();  //generic
  Game(const Game& g1); //copy constructor
//  ~Game(); //desctructor
  int timeStepCount;  //counts for my time step in my public function startgame
  void startGame(); //starts and populates my grid
  void takeTimeStep();  //next game
  void printstats() const;
  void printWorld() const;  //prints the grid
  //insector pointer from main that creates a grid of 20 x 20;
  Insect* grid[20][20];

};

#endif // GAME_H_INCLUDED
