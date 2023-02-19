/*
 * main.ccp
 *
 *  Created on: April 17, 2021
 *      Author: Jorge Jurado-Garcia
 *  Markups: 4/19 create dynamic memory
 *                for shapes objects and for choice 3
 *
 */
#include <string>
#include "Shape.h"
#include "TwoDShape.h"
#include "ThreeDShape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Box.h"
#include "Sphere.h"
#include <vector>

using namespace std;

int main()
{
//creating dynamic memory for rectnagle, circle, box, and square
int choice; //variable for first menu
bool gameon = true;
vector<Shape*> shape; //vector of base shapes pointers
Shape* shape_ptr;
//user is playing the game
while( gameon != false){
cout<<"//////////////////////////////////////////\n";
cout<<"1 - Insert.\n";
cout<<"2 - Help.\n";
cout<<"3 - Start.\n";
cout<<"4 - History.\n";
cout<<"5 - Exit.\n";
cout<<"Please enter your choice and press enter:";
cin>>choice;
cout<<"///////////////////////////////////////////\n";
if(choice == 1){
//coding for selecting objects
//calles the shape the user is going to input
int shape_choice;
cout<<"Please select Shape choice.\n";
cout<<"1 - Rectangle.\n";
cout<<"2 - Circle.\n";
cout<<"3 - Box.\n";
cout<<"4 - Sphere.\n";
cout<<"Choice: ";
cin>>shape_choice;
if(shape_choice==1){
float length;
float width;
cout<<"length: ";
cin>>length;
cout<<"width: ";
cin>>width;
Rectangle *R = new Rectangle(0,0,"Rectangle");
R->set_length(length);
R->set_width(width);
shape_ptr = R; //shape pointer points to the address of R;
shape.push_back(shape_ptr);
}
else if(shape_choice==2){
float radius;
cout<<"radius: ";
cin>>radius;
Circle *C = new Circle(0,"Circle");
C->set_radius(radius);
shape_ptr = C; //shape pointer points to the address of C;
shape.push_back(shape_ptr);
}
else if(shape_choice==3){
float length;
float width;
float height;
cout<<"length: ";
cin>>length;
cout<<"width: ";
cin>>width;
cout<<"height: ";
cin>>height;
Box *B = new Box(0,0,0,"Box");
B->set_length(length);
B->set_width(width);
B->set_height(height);
shape_ptr = B; //shape pointer points to the address of B;
shape.push_back(shape_ptr);
}
else if(shape_choice==4){
float radius;
cout<<"radius: ";
cin>>radius;
Sphere *S = new Sphere(radius,"Sphere");
shape_ptr = S; //shape pointer points to the address of S;
shape.push_back(shape_ptr);
}
}
if(choice == 2){
    cout<<"This program wil allow the user to create any number of circles,rectnagle,boxes, and spheres.";
    cout<<"All of the data will be stored and once the user us ready.\n";
    cout<<"Insert allows the user to insert a shape as data.\n";
    cout<<"Start will not let the user input any new data and will start the process.\n";
    cout<<"History will tell the user all the shapes he has chosen.\n";
    cout<<"Exit will close the problem out.\n";
    cout<<"Thank you playing."<<endl;
}
if(choice == 3){
    cout<<"Calculating Shapes..."<<endl;

    for(int j=0; j<shape.size(); j++){
       shape[j]->calculateAll();
    }
    cout<<"Done.\n";
    cout<<"Outputting information.\n";
    for(int j=0; j<shape.size();j++){
        cout<<shape[j]->to_string()<<endl;
        }
    }
if(choice == 4){
//conduct a for loop of the array
       for(int j=0; j< shape.size();j++){
        cout<<shape[j]->Shape::to_string()<<endl;
       }

}
if(choice == 5){
    gameon = false;
}//end if
}//end while
    cout<<"game is done\n";
    for(int j=0; j< shape.size();j++){
     delete shape[j];
    }
//vectors are always deleted afterwards

//user stops the game does nothing
/*
A virtual destructor
- it enables a dynamic dispatch mechanism that makes sure destruction works
fix this by creating shape destructor as a virtual
*/
}
