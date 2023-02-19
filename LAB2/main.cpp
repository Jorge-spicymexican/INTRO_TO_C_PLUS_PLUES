/*
  main.cpp

    Created on: Mar 17, 2021
        Author: Jorge Jurado-Garcia

    Creating a program that reads an input file
    and uses the information in the text file to create objects
    should display the values stored in the data members,
    call member functions and display the results of the member functions

 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> //exit function prototype

#include <string>
using namespace std;

#include "rectangle.h"
#include "MyBox.h"

int Request();
string convert(int number, string filename);

int main()
{
    //The program you write should be able to support any number of boxes and rectangles (from 0 to N), and
    //it should be able to process the file with the boxes and rectangles listed in any order.
while(1){
    int request;
    cout << "Hello world!" << endl;

    //creating this string that can never be change
    string filename;
    filename = "input";

    //file name being returned
    string file;

    //the file the user wants to read is selected by this function
    request = Request();

    file = convert(request,filename);


    //ifsteam constructor opens the file name
    //for this example we are opening a file named input and whatever integer precessed it
   ifstream input(file + ".txt",ios::in);

     //reading information in from a file
    cout<<"Reading the file"<<endl;

    //data being collected type for characters
    string data;

    //open a file for inputs only using ios::in
    if(input.is_open() ){
    cout<<"your file input1 is open"<<endl;

    //data type being captured for line 1 and line 2
    int R_amount; //amount of rectangles needed
    int B_amount; //amount of boxes needed

    //these variables is how we will compare are objects made vs objects created
    int boxes = 0;
    int rect = 0;

    //reading line 1
    input>>R_amount;

    //reading line 2
    input>>B_amount;

    //notions for console
    cout<<"reading the file and determining the box and rectangle needed"<<endl;

    //creating the objects
    Rectangle empArr1[R_amount]; //dynamic memory
    //here we are creating an array of the amount of objects needed
    cout<<"creating "<<R_amount<<" rectangles"<<endl;


    MyBox empArr2[B_amount]; //dynamic memory
    cout<<"creating "<<B_amount<<" MyBoxes"<<endl;

    while( !input.eof() ){
        input>>data;
        cout<<"data in string: "<<data<<endl;
        //since the string always has the B or R in front we can use this
         if(data == "B"){
            //this where we can get are height,length,widgth for MyBox
            cout<<"This is Box"<<endl;

            //amount of integers in the line
            int num[3];

            for(int i=0; i<3; i++){ //read the values in the array

                input>>num[i];
            }//end for

            //next we want to select the parts of the array and save it
            //as part length,width, and height for are object[s]
            empArr2[boxes].length = num[0];
            empArr2[boxes].width = num[1];
            empArr2[boxes].height = num[2];

            cout<<"length: "<<empArr2[boxes].length<<endl;
            cout<<"width: "<<empArr2[boxes].width<<endl;
            cout<<"Height: "<<empArr2[boxes].height<<endl;

            cout<< empArr2[boxes].getSurfaceArea()<<endl;
            cout<<empArr2[boxes].getVolume()<<endl;

             if( boxes == B_amount){
                break;
                }//end if
             else{
                boxes = boxes+1;
             }//end else
         }//end if
        else if(data == "R"){
            //this is rectangle need length and width
            cout<<"This is a Rectangle"<<endl;
            int num[2];
              for(int i=0; i<2; i++){
                //reads the value as a number
                input>>num[i];
              }//end for

            //next we want to select the parts of the array and save it
            //as part length,width, and height
            empArr1[rect].length = num[0];
            empArr1[rect].width = num[1];
            cout<<"length: "<<empArr1[rect].length<<endl;
            cout<<"width: "<<empArr1[rect].width<<endl;
            cout<< empArr1[rect].getArea()<<endl;
            cout<< empArr1[rect].getPerimeter()<<endl;

             if( rect == R_amount){
                break;
             }//end if
             else{
                rect = rect+1;
             }//end else

            }// end else if

        } //end while

        /*//just to verify that the object[s] where created
             //we will do a for loop and send out the information again
             for(int i = 0; i< B_amount; i++){
                cout<<"verifying the information printed below for each Box"<<endl;
                 cout<<"["<<empArr2[i].length<<","<<empArr2[i].width<<","<<empArr2[i].height<<"]"<<endl;
                cout<<empArr2[i].getSurfaceArea()<<endl;
                cout<<empArr2[i].getVolume()<<endl;
             }//end for loop

            //problem some of the data gets into a different array because of the rading functions takes
            //the last character in the file
            //will have to ask professor on how to fix this issue
             for(int i = 0; i< R_amount; i++){
               cout<<"verifying the information printed below for each Rectangle"<<endl;
               cout<<"["<<empArr1[i].length<<","<<empArr1[i].width<<"]"<<endl;
                cout<<empArr1[i].getArea()<<endl;
                cout<<empArr1[i].getPerimeter()<<endl;

                }//end for loop
                */
 input.close();
    } //end if file is open
    else{
        //exit program if ifsream could not open
          cerr<<"file could not be opened"<<endl;
        exit(1);
    }
    cout<<"\n All Done,"<<endl;
    }

}
int Request(){
    int value;
    cout<<"enter the file you want to read"<<endl
        <<"1-intput1.txt file"<<endl
        <<"2-input2.txt file"<<endl
        <<"3-input3.txt file"<<endl;
    cin>>value;
    return value;
}

string convert(int number,string filename){
     //this code is for converting any value into a string
     string file;
        stringstream ss;
        ss << number;
        string str = ss.str();
        file = filename+ str;
        cout<<file<<endl;
        return file;
}

