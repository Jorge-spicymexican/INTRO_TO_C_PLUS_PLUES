#include <iostream>
#include <sstream>
#include <time.h> //time
#include <stdlib.h> //srand and rand
#include <string>

#include "Game.h"
#include "Insect.h"
#include "Ladybug.h"
#include "Aphids.h"

Game::Game(){
  srand(time(NULL)); //random seed genrator
  timeStepCount = 0;  //game is started so rimestep is 0
  //creates a 20 by 20 array of null pointers
  for (int x = 0; x < 20; x++)
    for (int y = 0; y < 20; y++)
      grid[x][y] = nullptr;
}

Game::Game(const Game& g1)
{
    timeStepCount = g1.timeStepCount;
    for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      grid[x][y] = g1.grid[x][y];
    }
    }
}

void Game::startGame(){
  int x,y;  //x and y coordiniates for grid
  int aphidcount = 0;
  int ladybugcount = 0;

  //while function ladybug_count is set to 20
  while (ladybugcount < 10){
    //uses game genrate function to create a random number
    x = generateRandomNumber(0, 20 - 1);
    y = generateRandomNumber(0, 20 - 1);
    //example: grid[1][1] = ladybug or aphid then thats it
    //if not populate it with a ladybug
    if (grid[x][y] == nullptr)
    {
    grid[x][y] = new Ladybug(this, x, y);
    ladybugcount++;
    }
  }

  while (aphidcount < 100){
    x = generateRandomNumber(0, 20 - 1);
    y = generateRandomNumber(0, 20 - 1);
    if (grid[x][y] == nullptr){
    //example: grid[1][1] = ladybug or aphid then thats it
    //if not populate it with a aphid
    grid[x][y] = new Aphid(this, x, y);
    aphidcount++;
    }
  }
}

void Game::takeTimeStep(){
  timeStepCount++;

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if( grid[x][y] == nullptr)
      {

      }//end if
      else if (grid[x][y]->getInsect() == 2) //ladybug
      {
           grid[x][y]->movement();
            std::cout<<"ladybug movement function done\n";
      }//end else if
      else if(grid[x][y]->getInsect() == 1)
      {
           grid[x][y]->movement();
            std::cout<<"Aphid movement function done\n";
      } //end else if
      else{
          std::cout<<"N";
      } //end else
      }//end for
  }

 std::cout<<"lady bug done";

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if( grid[x][y] == nullptr)
      {

      }//end if
      else if (grid[x][y]->getInsect() == 2) //ladybug
      {
             grid[x][y]->breed(); //this function works
             std::cout<<"ladybug breed done\n";
             grid[x][y]->death(); //this function works
              std::cout<<"ladybug death done\n";
      }//end else if
      else if(grid[x][y]->getInsect() == 1)
      {
           grid[x][y]->breed(); //this function worls
           std::cout<<"aphid breed done\n";
           grid[x][y]->death(); //this function works
           std::cout<<"aphid death done\n";
      } //end else if
      else{
          std::cout<<"N";
      } //end else
      }//end for
  }
   std::cout<<"aphid done";

 }//end program

void Game::printWorld() const
{
  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (grid[x][y] == nullptr)
        std::cout << '_';
      else if (grid[x][y]->getInsect() == 1)
        std::cout << 'O';
      else  //world[x][y]->getType() == LADYBUG
       std:: cout << 'X';
    }
    std::cout << std::endl;
  }
}

void Game:: printstats() const
{
int num=1;
for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
        //grid is a insect* so in order to check what inside
        // i used getInsect and if its object of ladybug then
        //it will return a value of 2;
        if( (grid[x][y] == nullptr) )
           {
           }
        else
        {
        if( (grid[x][y]->getInsect()) == 2)
        {
            std::string result;
            result = grid[x][y]->stats();
            std::cout<<"Ladybug["<<num<<"]"<<result;
            num++;
        }
        }
    }
    }
}

int Game::generateRandomNumber(int startRange, int endRange) const
{
  return rand() % (endRange - startRange + 1) + startRange;
}
