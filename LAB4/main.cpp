#include <iostream>
#include "Shark.h"

using namespace std;

int main()
{
    int teeth;
    cout << "input teeth for shark lost per day" << endl;
    cin<<teeth;
    cout<<"input age of shark can be a float data type and in years"<<endl;
    float gg;;
    cin<<gg;
    cout<<"teeth"<<teeth<<"age"<<gg<<endl;
    Shark Sharkey(teeth,gg);
    float cal = Shark.calculate();
    cout<<"Calculation for Shark is: "<<cal;

    return 0;
}
