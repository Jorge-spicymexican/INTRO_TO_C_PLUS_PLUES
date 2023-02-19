/*
File created by: Jorge Jurado-Garcia
Name: Aphids.ccp file
Abstract class
Date: 4/30/21
Modifications:
All rights reserved
Educational purposes
*/

#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "Aphids.h"

//generic constructor
Aphid:: Aphid()
{
   food_count = 3;
   breed_count = 3;
}

//parameter constructor
Aphid::Aphid(Game* curgame, int X_coord, int Y_coord)
  :Insect(curgame, X_coord, Y_coord)
{
    breed_count = 3;
    food_count = 3;
}

 //death of aphid
 void Aphid:: death()
 {
   if(food_count==0){
        current_game->grid[X_coord][Y_coord] = nullptr;
    }
   return;
 }

 //breed function
void Aphid:: breed()
{
    std::cout<<"in breed function\n";
     if(breed_count != 0){
        std::cout<<"breed count is not zero\n";
        return;
    }
    std::cout<<"breed count is zero";
    int ar[4];
    ar[0] = check(X_coord+1,Y_coord);  //down
    ar[1] = check(X_coord,Y_coord+1);  //right
    ar[2] = check(X_coord-1,Y_coord);  //up
    ar[3] = check(X_coord,Y_coord-1);  //left

    int New_X_coord;
    int New_Y_coord;

    for(int j = 0; j<4;j++)
    {
     int sum = ar[j]+ sum;
     std::cout<<ar[j];
     if(sum==0){
        return;
     }
    }

    for(int i=0;i<4;i++){
     if(i==0){
         New_X_coord = X_coord+1;
         New_Y_coord = Y_coord;
     }
     else if(i==1){
         New_X_coord = X_coord;
         New_Y_coord = Y_coord+1;
     }
     else if(i==2){
         New_X_coord = X_coord-1;
         New_Y_coord = Y_coord;
     }
     else{
        New_X_coord = X_coord;
        New_Y_coord = Y_coord-1;
     }
     if( ar[i] == 1 ){
        //make the current position to a null ptr
        offspring++;
        current_game->grid[X_coord][Y_coord] = this;
        current_game->grid[New_X_coord][New_Y_coord] = nullptr;
          std::cout<<"passed this\n";
        current_game->grid[New_X_coord][New_Y_coord] = new Aphid(current_game,New_X_coord,New_Y_coord);
        std::cout<<"beed count accomplushed";
     i = 5;
     }
}//end for

} //end function

//getInsect function
int Aphid:: getInsect()
{
    return 1;
}

int Aphid:: get_x()
{
    return X_coord;
}

int Aphid:: get_y()
{
    return Y_coord;
}

//stats function
std::string Aphid:: stats()
{
    std::string num;
    num = " ";
    return num;
}

//movement function
void Aphid:: movement()
{
  if(timestepcount==current_game->timeStepCount)
  {
      return;
  }
  timestepcount++;
  std::cout<<X_coord<<" "<<Y_coord<<"\n";
int ar[4];
    ar[0] = check(X_coord+1,Y_coord);  //down
    ar[1] = check(X_coord,Y_coord+1);  //right
    ar[2] = check(X_coord-1,Y_coord);  //up
    ar[3] = check(X_coord,Y_coord-1);  //left

    int New_X_coord;
    int New_Y_coord;
    int sum=0;
    for(int i = 0; i<4;i++)
    {
    for(int j=0;j<4;j++){
     sum = ar[j]+ sum;
     std::cout<<"ar["<<j<<"]"<<ar[j]<<"\n";
    }
    std::cout<<"sum: "<<sum<<"\n";
    if(sum==0){
        return;
     }
     if(i==0){
         New_X_coord = X_coord+1;
         New_Y_coord = Y_coord;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
     else if(i==1){
         New_X_coord = X_coord;
         New_Y_coord = Y_coord+1;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
     else if(i==2){
         New_X_coord = X_coord-1;
         New_Y_coord = Y_coord;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
     else{
        New_X_coord = X_coord;
        New_Y_coord = Y_coord-1;
        std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
      if( ar[i] == 1 ){
        std::cout<<New_X_coord<<" " <<New_Y_coord<<"\n";
        current_game->grid[New_X_coord][New_Y_coord] = nullptr;
        current_game->grid[X_coord][Y_coord] = nullptr;
        std::cout<<"passed all info\n";
        X_coord = New_X_coord;
        Y_coord = New_Y_coord;
        current_game->grid[New_X_coord][New_Y_coord] = this;
        std::cout<<"passed all info\n";
        i = 4; //stop the for loop
        std::cout<<"j is:"<<i<<"\n";
}//end if statement
}//end for
std::cout<<"done\n";
} //end movement

//check function
int Aphid:: check(int x, int y)
{

    //this is to check if the user who imported x value between 0-20
    //bool out is a way to check what will happen if if its outofscope
    //then the check function is null
    int out;
   if( (x<0 || (y<0)) )
   {
        out = 0;
        return out;
   }
   if( (x>19) || (y>19) )
   {
       out = 0;
       return out;
   }
    if(current_game->grid[x][y] == nullptr)
    {
        out = 1;
    }
    else if(current_game->grid[x][y]->getInsect() == 2) //ladybug
    {
         out = 0;
    }
    else //aphid
    {
         out = 0;
    }
    return out;

}

