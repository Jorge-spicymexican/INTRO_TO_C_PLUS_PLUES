/*
 * Team_functions.ccp
 *
 *  Created on: April 3, 2021
 *      Author: Jorge Jurado-Garcia
 *
 * Defines the functions for Team.h hile
 *
 */

 #include "Team.h"
 #include "Player.h"
 #include <stdio.h>
 #include <string>
 #include <vector>
 #include <math.h>
 #include <iostream>
 #include <sstream>

 using namespace std;
string Team:: get_name() const{
string Name;
    int sizel = Roster.size();
    for(int i=0; i< sizel; ++i){
            Name = Name+Roster[i].get_name();
    }
    return Name;
}
int Team:: total()const{
    int total = 0;
    int sizel = Roster.size();
    for(int i=0; i< sizel; ++i){
            total = Roster[i].total()+total;
    }
    return total;
}
 Team::Team(){
     cout<<"***In default constructor****"<<endl;
     //need to create a roster of zero players
     vector<Player> Roster(0);

 }
 Team::Team(vector<Player> NewRoster){
   //here we are given a vector of player from main
   //creating a team for them
   cout<<"***In parameter constructor***"<<endl;
    set_Roster( NewRoster );
 }
Team::Team(Team &otherTeamCopy){
    //going to have to have a Team called otherTeamcopy and that will have
    //a vector full of players
    cout<<"**copy constructor***"<<endl;
   this->Roster = otherTeamCopy.Roster;
}
 Team:: set_Roster(vector<Player> R){
    //sizing the roster vector to the size of R vector
    Roster.resize(R.size());
    for(unsigned int i=0; i < R.size(); i++){
        //items in vec2 will be in roster copy
        Roster[i] = R[i];
    }
return 0;
}
vector<Player> Team::get_Roster(){
    //return the vector of
    return Roster;
}
 Team:: ~Team(){
 }
 const Team& Team::operator+=(const Player& Ply){
    this->Roster.push_back(Ply);
    return *this;
 }
const Team& Team:: operator-=(const Player& Ply){
    for(auto i = Roster.begin(); i != Roster.end(); ++i){
        if(*i == Ply){
        this->Roster.erase(i);
        }
    }
cout<<"Size of Vector after removal:"<<Roster.size()<<endl;
return *this;
}
const Team& Team:: operator=(const Team& tobj){
    if(this != &tobj){
        Roster = tobj.Roster;
    }
    return *this;
}
Team:: clearPlayers(){
    Roster.clear();
    return 0;
}
Team:: to_string() const{
    vector<Player>::const_iterator iter;
    for(iter = Roster.begin(); iter != Roster.end(); iter++){
        cout<<"\t"<<(*iter).to_string()<<endl;
    }
    return 0;
}
bool Team:: operator<(const Team& tobj) const{
    int total2 = tobj.total();
    int total1 = this->total();
    if(total1 < total2){
        return true;
    }
    else{
        return false;
    }
}
bool Team:: operator>(const Team& tobj) const{
    int total2 = tobj.total();
    int total1 = this->total();
    if(total1 > total2){
        return true;
    }
    else{
        return false;
    }
}
bool Team:: operator==(const Team& tobj) const{
    bool out;
    int size1 = this->Roster.size();
    int size2 = tobj.Roster.size();
    if(size1 == size2){
        for(int i=0; i< size1; ++i){
            if(this->Roster[i]== tobj.Roster[i]){
                //if the player are the same then do nothing;
                out = true;
            }
            else{
                return false;
            }
        }
        return out;
    }
    else{
        return false;
    }
}
bool Team:: operator<=(const Team& tobj) const{
    string name1 = this->get_name();
    string name2 = tobj.get_name();
    int total1 = this->total();
    int total2 = tobj.total();
    if( ( (total1 < total2) || (total1==total2) ) &&  (name1.compare(name2)==0) ){
        return true;
    }
    else if((total1 < total2) || (total1==total2) ){
        return true;
    }
    else{
        return false;
    }
}
bool Team:: operator>=(const Team& tobj) const{
    string name1 = this->get_name();
    string name2 = tobj.get_name();
    int total1 = this->total();
    int total2 = tobj.total();
    if( ( (total1 > total2) || (total1==total2) ) &&  (name1.compare(name2)==0) ){
        return true;
    }
    else if((total1 > total2) || (total1==total2) ){
        return true;
    }
    else{
        return false;
    }
}

