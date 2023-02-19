/*
  main.cpp

    Created on: Mar 24, 2021
        Author: Jorge Jurado-Garcia

    Create a program that demonstrates the complete functionality of both classes.
    The program must create at least one object of each class, display the values
    stored in the properties of each object, call all class methods on each object,
    and display the results of the methods. Your program must also demonstrate the
    use of the copy constructor. To do that, your program must contain at least
    one function that has a class object as a parameter,
    or a function that returns a class object.

Extra Credit Opportunity:
To optionally earn extra credit, follow the instructions on Canvas to setup a
and install SFML, and link it to your Code
Blocks project (SFML stands for Simple and Fast
Multimedia Library – you can use it to create graphics).
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <math.h>
#include <string>
using namespace std;

#include "DairyCow.h"
#include "HayField.h"

float printCowData(DairyCow Cow);
int  printHayFieldData(HayField Hay);
int MarketAnalysis(int demand[], int supply[], int price,float milk);
//In my code ill use some economics so that the farmer
//knows how much he should make it depending on supply and demand curves
int main(){
    int bd,sloped,bs,slopes;
    //infor for classes
    float water, food, fieldsize, balesize;
    int balecount;

    while(1){
    int i;
    cin>>i;

    for(int j=1;j<3;j++){
    cout<<"Day"<<j<<endl;
    fieldsize = ((rand() %120+2)+0.0)/ (rand()%10+1);
    balesize = ((rand() %120+2)+0.0)/(rand()%8+1);
    balecount = rand() %10+1;
    float drymatter = 0.8;

    water = ((rand() %99+2)+0.0)/ (rand()%10+1);
    food = ((rand() %101+2)+0.0)/(rand()%8+1);
    int price_dairy = 0;

    int *demand = new int[i];
    int *supply = new int[i];
    //generates number from 1 and 10;
    bd = rand() %100+1;
    bs = -(rand() %5+1);
    sloped = -(rand() %5+1);
    slopes = rand() %7+1;

    HayField hay1;
    hay1.set_fieldsize(25.2);
    hay1.set_baleCount(10);
    hay1.set_balesize(5.9);
    hay1.set_drymatter(0.80);
    cout<<"Jorges "<<hay1.calculateYield()<<endl;
    cout<<"Jorge "<<hay1.calculatCarbonCapture()<<endl;

    HayField hay2(fieldsize,balecount,balesize,drymatter);
     printHayFieldData(hay2);
    cout<<"Carl "<<hay2.calculateYield()<<endl;
    cout<<"Carl "<<hay2.calculatCarbonCapture()<<endl;

    cout<<"PRICE FOR DAIRY IN BELOIT,WI TODAY"<<endl;
    for(int price=0; price<i;price++){

    float k = bd+sloped*(price);
    float kk = bs+slopes*(price);
    demand[price]=k;
    supply[price]=kk;
    cout<<"price: $"<<price<<"||"<<"demand: "<<demand[price]<<"||"<<"supply: "<<supply[price]<<endl;

    if(k==kk){
        price_dairy = price;
        cout<<"price equilibrlum is: "<<price_dairy<<endl;
        }
    }
    price_dairy = ((bd-bs)/(slopes-sloped));
    cout<<"price equilibrium found: "<<price_dairy<<endl;


     cout<<"farmer Jorge"<<endl;
    DairyCow Jorge(food,water);
    float milk1 = printCowData(Jorge);
    if(price_dairy>i){
        int l = bs+slopes*(price_dairy);
        cout<<"cannot compute how much to produce must have more data."<<endl;
         cout<<"potential supply:"<<l<<"units"<<endl;
    }
    else{
    MarketAnalysis(demand,supply,price_dairy,milk1);
    }

    cout<<"farmer Carl"<<endl;
    DairyCow Carl;
    Carl.set_food(rand()%10+1);
    Carl.set_water(rand()%10+1);
    float milk2 = printCowData(Carl);
     if(price_dairy>i){
        int l = bs+slopes*(price_dairy);
        cout<<"cannot compute how much to produce must have more data."<<endl;
        cout<<"potential supply:"<<l<<"units"<<endl;
    }
    else{
    MarketAnalysis(demand,supply,price_dairy,milk2);
    }
    //now we will find farmer has excess supply or excess demand
    //and where or not they should create more milk or produce les
    delete[] demand;
    delete[] supply;
        }
    }

    return 0;
}

float printCowData(DairyCow Cow){
    cout<<Cow.get_water()<<"||"<<Cow.get_food()<<endl;
    cout<<"Dairy Produced: "<<Cow.calculateMilkProduced()<<"L"<<endl;
    cout<<"Waste Produced: "<<Cow.calculateWasteProduced()<<"Kg"<<endl;
    return Cow.calculateMilkProduced();
}
int MarketAnalysis(int demand[], int supply[], int price,float milk){
    if(supply[price] == milk){
        cout<<"the amount of milk produced is the right amount sell at: $"<<price<<endl;
    }
    else if( supply[price] < milk){
        cout<<"produced too much milk!";
        cout<<"try to produce: "<<supply[price]<<"[L]"<<endl;
        cout<<"or reduce price to: $"<<price<<endl;
    }
    else{
        cout<<"produced not enough milk!";
        cout<<"try to produce: "<<supply[price]<<"[L]"<<endl;
        cout<<"or increase price to: $"<<price<<endl;
    }
    return 0;
}
int  printHayFieldData(HayField Hay){
    cout<<"field size: "<<Hay.get_fieldSize()<<"||"<<"bale size: "<<Hay.get_balsize()<<endl;
    cout<<"bale count: "<<Hay.get_baleCount()<<"||"<<"dry matter: "<<Hay.get_drymatter()<<endl;
    return 0;
}
