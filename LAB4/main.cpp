/*
Created: Jorge Jurado-Garcia
Date: 4/10/21
modifications:

*/

#include <iostream>
#include "Player.h"
#include "Team.h"
#include <vector>
using namespace std;

int main()
{
    Player P1("Bob",80,20,40,10);
    Player P2("Cat",10,10,10,0);
    Player P3("Rich",20,10,50,100);
    Player P4("Steve",0,1,0,1);
    Player Pc_add;
    Player Pc_sub;

    Pc_add = P1+P2;
    Pc_sub = P1-P2;
    cout<<"Pl stats:"<<P1.to_string()<<endl;
    cout<<"P2 stats:"<<P2.to_string()<<endl;
    cout<<"Pc+ stats:"<<Pc_add.to_string()<<endl;
    cout<<"Pc- stats"<<Pc_sub.to_string()<<endl;
    cout<<"P3 stats"<<P3.to_string()<<endl;
    cout<<"Making P3 equal to player Pc_sub"<<endl;
    P3 = Pc_sub;
    cout<<"P3 stats"<<P3.to_string()<<endl;
    cout<<"checking if P3 is equal to Pc_sub 1-true and 0-false"<<endl;
    bool x = P3==Pc_sub;
    bool y = P1==P2;
    cout<<x<<endl;
    cout<<"checing if P1 and P2 are equal 1-true 0-false"<<endl;
    cout<<y<<endl;
    cout<<"compare if P1>P2 1=true 0-false"<<endl;
    bool z = P1>P2;
    cout<<z<<endl;
    cout<<"compare if P1<P2 1=true 0-false"<<endl;
    bool zz = P1<P2;
    cout<<zz<<endl;
    cout<<"comparing if P3<=Pc_sub 1-true 0-false"<<endl;
    bool zzz = P3<=Pc_sub;
    cout<<zzz<<endl;
    cout<<"this would the same for P3>=Pc_sub since they are the same players essentially"<<endl;
    bool zzzz = P3>=Pc_sub;
    cout<<zzzz<<endl;

    vector<Player> Roster1{P1,P2,P3};
    Team T1(Roster1);
    T1.to_string();
    cout<<"Adding a Player"<<endl;
    T1+=P4;
    T1.to_string();

    cout<<"subtracting a Player"<<endl;
    T1-=P1;
    T1-=P2;

    cout<<"Team 1 are:"<<endl;
    T1.to_string();
    int y2 = T1.total();
    cout<<y2<<endl;

    cout<<"Team 2 are:"<<endl;
    vector<Player> Roster2{P1,P2};
    Team T2(Roster2 );
    T2.to_string();
    int y3 = T2.total();
    cout<<y3<<endl;

    bool out;
    out = T2<T1;
    cout<<"Team2<Team1 1-true 0-false"<<endl<<out<<endl;

     bool out2;
    out2 = T2>T1;
    cout<<"Team2>Team1 1-true 0-false"<<endl<<out2<<endl;

    bool out4;
    out4 = T2==T1;
    cout<<"is T2==T1 1-true 0-false"<<endl<<out4<<endl;

    cout<<"clearing Team2"<<endl;
    T2.clearPlayers();
    T2.to_string();

     cout<<"Team2 = Team1 is"<<endl;
    T2 = T1;
    T2.to_string();
    bool out5;
    out5 = T1==T2;
    cout<<"is T2==T1? 1-true 0-false"<<endl<<out5<<endl;

    cout<<"comparing teams"<<endl;
    Player P20("Jorge",1,1,1,1);
    Player P30("Carl",100,100,100,100);
    Player P50("Pancho",10,23,10,0);
    Player P60("Crazy_Carl",100,100,100,100);
    Player P70("Carl",1,1,1,1);
    Player P80("Carl",2,2,2,2);

    vector<Player> R1{P20,P30,P70,P50,P60};
    vector<Player> R2{P20,P30,P70,P50,P60};
    Team T3(R1);
    Team T4(R2);
    cout<<"Team 3 size||"<<endl;
    T3.to_string();
    cout<<"Team 4 size||"<<endl;
    T4.to_string();

    bool out7;
    out7 = T3 >= T4;
    cout<<"when T3 >= T4 the answer is 1-true 0-false: "<<out7<<endl;

    bool out8;
    out8 = T3 <= T4;
    cout<<"when T3 <= T4 the answer is 1-true 0-false: "<<out8<<endl;
    cout<<"taking out carl(1,1,1,1) and replacing carl(2,2,2,2)"<<endl;
    T4 -=P70;

    T4 += P80;
    T4.to_string();

    bool out9;
    out9 = T3<=T4;
    cout<<"when T3 <= T4 the answer is 1-true 0-false: "<<out9<<endl;

    bool out6;
    out6 = T3 >= T4;
    cout<<"when T3 >= T4 the answer is 1-true 0-false: "<<out6<<endl;
    return 0;
}
