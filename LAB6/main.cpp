#include <string>
#include <stdlib.h>
#include "Game.h"
#include "iostream"

using namespace std;

void intro(){
std::cout<<"**************************************"<<std::endl;
std::cout<<"**  Ladybugs & Aphids Game ~EE2510  **"<<std::endl;
std::cout<<"** created by: Jorge Jurado-Garcia  **"<<std::endl;
std::cout<<"**************************************"<<std::endl;
}

int main()
{
    intro();
    Game g1;
    g1.startGame();
    g1.printWorld();
    while(1){
    cout<<"Please press enter 1 for one timestep sequence or 2 for user selected timestep";
    cout<<"anything else to abort."<<endl;
    int user_input;
    cin>>user_input;
    if(user_input == 1)
    {
        g1.takeTimeStep();
       system("CLS");
       intro();
       g1.printWorld();
    }
    else if(user_input == 2)
    {
      int num;
      cout<<"please input time step amount.";
      cin>>num;
      cout<<endl;
      cout<<"timestep amount: "<<num<<endl;
      for(int i=0; i<num; i++)
      {
            g1.takeTimeStep();
      }
      system("CLS");
      intro();
      g1.printWorld();

    }
    else
    {
        system("CLS");
        intro();
        cout<<"Game finished."<<endl;
        g1.printstats();
        return 0;
    } //end elss
    } //end while
} //end main
