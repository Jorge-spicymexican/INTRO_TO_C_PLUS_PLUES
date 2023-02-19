/*
File created by: Jorge Jurado-Garcia
Name: ladybug.ccp file
Date: 5/02/21
Modifications:
All rights reserved
Educational purposes
*/

#include <iostream>
#include <sstream>
#include <string>

#include "Ladybug.h"

//generic constructor
Ladybug:: Ladybug()
{

  food_count = 3;
  life = 0;
  offspring = 0;
  moves = 0;
  consumption = 0;
  breed_count = 8;
}

//parameter constructor
Ladybug::Ladybug(Game* current_game, int X_coord, int Y_coord)
 :Insect(current_game,X_coord,Y_coord)
{
    breed_count = 8;
    food_count = 3;
    life = 0;
    offspring = 0;
    moves = 0;
    consumption = 0;
}

  //death of aphid
void Ladybug:: death()
 {
    if(food_count<=0){
        current_game->grid[X_coord][Y_coord] = nullptr;
    }
   return;
 }

 //breed function
void Ladybug:: breed()
{
    std::cout<<"in breed function\n";
     if(breed_count != 0){
        std::cout<<"breed count is not zero\n";
        return;
    }

    if(breed_count != 0){
        return;
    }
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
        current_game->grid[New_X_coord][New_Y_coord] = new Ladybug(current_game,New_X_coord,New_Y_coord);
        std::cout<<"beed count accomplushed";
     i = 5;
     }
}//end for
}

int Ladybug:: getInsect()
{
    return 2;
}

//stats function
std:: string Ladybug:: stats()
{
    std::string ret;
    std::ostringstream out1;
    std::ostringstream out2;
    std::ostringstream out3;
    std::ostringstream out4;
    std::ostringstream out5;
    out1<<life;
    out2<<offspring;
    out3<<moves;
    out4<<consumption;
    out5<<food_count;
    ret = Insect::stats();
    ret = ret + "LadyBug STATS\n";
    ret = ret + "Life: " + out1.str() + "\n";
    ret = ret + "offspring: " + out2.str() + "\n";
    ret = ret + "moves: " + out3.str() + "\n";
    ret = ret + "consumption: " + out4.str() + "\n";
    ret = ret + "food_count: " + out5.str() + "\n";
    return ret;
}

void Ladybug:: movement()
{
    if(timestepcount == current_game->timeStepCount)
    {
        return;
    }
    timestepcount++;
    std::cout<<X_coord<<" "<<Y_coord<<std::endl;
   int ar[4];
    ar[0] = check(X_coord+1,Y_coord);  //down
    ar[1] = check(X_coord,Y_coord+1);  //right
    ar[2] = check(X_coord-1,Y_coord);  //up
    ar[3] = check(X_coord,Y_coord-1);  //left

    int New_X_coord;
    int New_Y_coord;
    int sum=0;
    int pp=0; //best choice of action

     for(int j=0;j<4;j++){
     sum = ar[j]+ sum;

     if(ar[j] == 2){
        if( j == 0 ){
            j = 4;
        }
            pp = j;
     }
     std::cout<<"ar["<<j<<"]"<<ar[j]<<"\n";
    } //end for
    std::cout<<"sum: "<<sum<<"\n";

    if(sum==0){
        return;
     }

    if(pp == 0)
    {

    for(int i = 0; i<4;i++)
    {

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

     if( ar[i] == 1 ){  //aphid in its place
        //make the current position to a null ptr
        std::cout<<X_coord<<" "<<Y_coord<<std::endl;
        current_game->grid[New_X_coord][New_Y_coord] = nullptr;
        current_game->grid[X_coord][Y_coord] = nullptr;
        current_game->grid[New_X_coord][New_Y_coord] = this;
        X_coord = New_X_coord;
        Y_coord = New_Y_coord;
        moves++;
        food_count--;
        i == 4; //stop for loop
     }//end if

    }// end for

    }//end if
    else
    {
        if(pp==4){
         New_X_coord = X_coord+1;
         New_Y_coord = Y_coord;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
        else if(pp==1){
         New_X_coord = X_coord;
         New_Y_coord = Y_coord+1;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
     }
        else if(pp==2){
         New_X_coord = X_coord-1;
         New_Y_coord = Y_coord;
         std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
        }
        else{
        New_X_coord = X_coord;
        New_Y_coord = Y_coord-1;
        std::cout<<New_X_coord<<" "<<New_Y_coord<<"\n";
        }//end of else statement

        //make the current position to a null ptr
        std::cout<<X_coord<<" "<<Y_coord<<std::endl;
        current_game->grid[New_X_coord][New_Y_coord] = nullptr;
        current_game->grid[X_coord][Y_coord] = nullptr;
        current_game->grid[New_X_coord][New_Y_coord] = this;
        X_coord = New_X_coord;
        Y_coord = New_Y_coord;
        moves++;
        consumption++;

    }//end else
}//end function

//check function
int Ladybug:: check(int x, int y)
{
int out;
    //this is to check if the user who imported x value between 0-20
    //bool out is a way to check what will happen if if its outofscope
    //then the check function is null
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
        std::cout<<"null pointer\n";
        out = 1;
    }
    else if(current_game->grid[x][y]->getInsect() == 2)
    {
        std::cout<<"ladbug found\n";
         out = 0;
    }
    else{
        std::cout<<"aphid found pointer\n";
         out = 2;
    }
    return out;
}

