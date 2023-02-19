#include "calculatorfunctions.h"
#include <iostream>
#include <string>


using namespace std;

int my_basic_math(int num, int op1, int op2, float*store){
     //created a variable called sum
     //this variable is only for this function
    float sum;

    //+ property
    if(num==1){
        sum = op1 + op2;
    }
    //- property
    else if(num==2){
        sum = op1 - op2;
    }
    //multiplication function that i created
    else if(num==3){
        sum = op1 * op2;
    }

    //division with division 0 not possible
    else if(num==4){
        if(op2==0){
            cout<<"cannot divide by zero try again"<<endl;
            return 1;
        }
        else{
            sum = (float)op1 / (float)op2;
        }
    }
    else if(num==5){
        //making op2 as the power that is being raised to;
        if(op2>0){
            sum = 1;
            for(int j=0; j<op2; j++){
            sum = (op1*sum);
            }
        }
        else if(op2<0){   
             int demon = 1;
                for(int k=0; k>op2; k--){
                demon = (op1*demon);
                }
                sum = 1.0/demon;
        }
        //if exponent is 0 then value is 1
        else{
            sum = 1;
        }
    }
    else{
        cout<<"oops there was error nothing will be given\n"<<endl;
        return 1;
    }
    *store = sum;
     cout<<"your result is:\n"<<*store<<endl;
    return 0;
}


int my_average(int arr[], int length, float* output){
   //passed in the address of new array starting point and declared it
   //as a integer
   if(length ==0){
    cout<<"garbage result"<<endl;
        return 1;
   }
   float total = 0.0;
    for(int j=0; j<length;j++){
        total = arr[j] + total;
    }
    *output = total/length;
    cout<<"your result is:\n"<<*output<<endl;
    return 0;
}

int my_find_large_small(int arr[], int length, int* largest, int* smallest){
    int small;
    int large;
    int final_large = 0 ;
    int final_small = 0 ;
    int index;

    if( length ==0){
        cout<<"garbage result"<<endl;
        return 1;
    }
    //display the array
    for(int j=0; j<length;j++){   //[1,0,8]
        //first value in the array
        index = arr[j];
        //if f1>s2 then save as large if not small
            if(final_large < index){
                final_large = index;
            }
            else{
                final_large = final_large;
            }
            if(final_small > index){
                final_small = index;
            }
            else{
                final_small = final_small;
            }
    }
    *largest = final_large;
    *smallest = final_small;
    cout<<"largest value is: \n"<<*largest<<endl;
    cout<<"smallest value is: \n"<<*smallest<<endl;

    return 0;
}

int my_series_parallel(int arr[], int length, int configure, float* output){
    float total_res;
    if(configure ==1){
        cout<<"you picked series circuit!\n"<<endl;
        for(int i = 0; i < length; i++){
            total_res = arr[i]+total_res;
        }
    }

    else if(configure ==2){
        cout<<"you picked parallel circuit!\n"<<endl;
        for(int i = 0; i < length; i++){
            total_res = (1.0/arr[i])+total_res;
        }
        total_res = 1.0/total_res;
    }
    else{
        cout<<"not a valid configuration for sorry\n"<<endl;
        return 1;
    }
    *output =  total_res;
    cout<<"the total resistance is: \n"<<*output<<endl;
    return 0;
}
