/*
Created: Jorge Jurado-Garcia
Date: 4/3/21
modifications:
4/8/21 create code for operator of += -= =
4/11/21 creating the functions needed for bool operators
*/

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"

using namespace std;

class Team{
private:
    vector<Player> Roster;

public:
    string get_name() const;
    int total()const;
    Team(); //default constructor
    Team(vector<Player> NewRoster); //creating a new roster
    Team(Team &otherTeamCopy); //copy constructor)
    virtual ~Team(); //destructor

    //will need set and get functions for roaster;
    set_Roster(vector<Player> R);
    vector<Player> get_Roster();

    const Team& operator+=(const Player& Ply);
    const Team& operator-=(const Player& Ply);
    const Team& operator=(const Team& tobj);

    bool operator==(const Team& tobj) const;
    bool operator<(const Team& tobj) const;
    bool operator>(const Team& tobj) const;
    bool operator<=(const Team& tobj) const;
    bool operator>=(const Team& tobj) const;

    clearPlayers();
    to_string() const;
};
#endif // TEAM_H_INCLUDED
