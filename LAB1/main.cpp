#include <iostream>
#include "calculatorfunctions.h"
using namespace std;

int main()
{
    cout << "Hello EE2510! This is your calacultor " << endl;
    //calculator operator
    int option;

    //number option for (1-5)
    int num1;
    //number option for (1-5)
    int num2;

    //output for any function
    float output;

    //return value
    int return_val;

    //new array pointer
    int *newarray;
    //length of array
    int length;

    //large and small integer values
    int large;
    int small;

    while(1){
    cout<<"Please select the option you want below\n"<<endl;
    cout<<" 1-addition\n 2-subtraction\n 3-multiplication\n 4-division\n 5-exponent\n";
    cout<<" 6-finding average\n 7-finding largest and smallest value in array\n";
    cout<<" 8-finding resistance of series or parallel circuit\n"<<endl;
    cin>>option;
    cout << "your option number is: "<<option <<endl;

        if( (option >0) && (option<6) ){
            cout<<"please select a number:"<<endl;
            cin>>num1;
            cout<<"please select another number"<<endl;
            cin>>num2;
            cout<<"number 1 is:"<<num1<<"\n"<<"number 2 is:"<<num2<<"\n"<<endl;

            return_val= my_basic_math(option,num1,num2,&output);
        }
        else{
         cout<<"please input your length:"<<endl;
                cin>>length;
                newarray = new(nothrow) int[length];
                if(newarray == 0){
                    cout<<"could not create array\n";
                }
                else{
                for(int i=0; i<length; i++){
                cout<<"enter values to be stored:"<<i+1<<":"<<endl;
                cin>>newarray[i];
			}
			cout<<"array values are are:"<<endl;

			cout<<"[";
			//prints out array values
			for(int j=0; j<length; j++){
				cout<<newarray[j]<<",";
                }
            cout<<"]"<<endl;
        if( option==6){
            //FUNCTIONS used for new values
            //where newarray is the address of my array
            return_val = my_average(newarray, length, &output);
            }
        if( option ==7){
            return_val = my_find_large_small(newarray, length, &large, &small);
        }
        if( option ==8){
            int selection;
            cout<<"please pick a selection 1-series, 2-parallel, any num for exit\n"<<endl;
            cin>>selection;
             return_val = my_series_parallel(newarray, length, selection, &output);
        }
                }
    delete[] newarray;
        }
        cout<<"return:"<<return_val<<endl;
    }
    return 0;
}

