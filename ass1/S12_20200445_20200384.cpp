/*
                     Solution of Assignment 1
                            Group A
  Made by
        Name                              ID            Section
        Mohamed Samy Abdelsalam Elsebaey  20200445      12
        Fouad Sayed Fouad Sayed           20200384      12

*/
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
#ifndef SETCOLORFUN_H_INCLUDED
#define SETCOLORFUN_H_INCLUDED
// Function to Set Color to the Output
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

/*
Name         | Value
             |
Black        |   0
Blue         |   1
Green        |   2
Cyan         |   3
Red          |   4
Magenta      |   5
Brown        |   6
Light Gray   |   7
Dark Gray    |   8
Light Blue   |   9
Light Green  |   10
Light Cyan   |   11
Light Red    |   12
Light Magenta|   13
Yellow       |   14
White        |   15
*/

#endif // SETCOLORFUN_H_INCLUDED
//My Class

class ColoredBox{
private:
    int length,width,color;
    char boxCharacter;
    char **theBox;
public:
    static int getMaxAreaValue ;
    static int static_length,static_width;
    ColoredBox(int userLength , int userWidth,int userColor,char userChar):
        boxCharacter(userChar),length(userLength),width(userWidth){setBox();setChar(boxCharacter);setColor(userColor);static_length=length;static_width=width;}
    ColoredBox(int userLength , int userWidth):
        length(userLength),width(userWidth){setBox();setChar('#');setColor(15);static_width=width;static_length=length;}

    void setBox(){
        theBox=new char *[length];
        for(int i=0; i<length; i++){
            theBox[i] = new char[width];
        }

    }
    void setChar(char UserChar){
        boxCharacter=UserChar;
        for(int i=0;i<length;i++){
            for (int j=0;j<width;j++){
                theBox[i][j]=boxCharacter;
            }
        }
    }

    void setColor(int UserColor){
        color=UserColor;
    }
    char getChar(){
        return boxCharacter;
    }

    int getColor(){
        return color;
    }
    void displayTransposed(){
        SetColor(color);
        for(int i=0;i<width;i++){
            for (int j=0;j<length;j++){
                cout<<theBox[j][i];
            }
            cout<<"\n";
        }
                SetColor(15);

    }
    void display(){
        SetColor(color);
        cout<<endl;
        for(int i=0;i<length;i++){
            for (int j=0;j<width;j++){
                cout<<theBox[i][j];
            }
            cout<<"\n";
        }
        SetColor(15);
    }
    void displayWider(){
        SetColor(color);
        for(int i=0;i<length;i++){
            for (int j=0;j<width;j++){
                cout<<theBox[i][j]<<" ";
            }
            cout<<"\n";
        }
            SetColor(15);

    }
    int b=1;
    void displayChess(int chessColor){
    for(int i=0;i<length;i++){
            for (int j=0;j<width;j++){
                if(b%2==0){
                    SetColor(chessColor);
                }else{
                    SetColor(color);
                }
                cout<<theBox[i][j];
                b++;
            }
            cout<<"\n";
                    SetColor(15);
        }
    }


    int getArea(){
        return length*width;
    }


    ~ColoredBox(){
        for(int i=0;i<length;i++){
            delete[]theBox[i];
        }
        delete[]theBox;

    }
    static int getMaxArea(){
        if (static_length*static_width>getMaxAreaValue){
            getMaxAreaValue=static_length*static_width;
        }
        return  getMaxAreaValue;
    }
};
int ColoredBox::static_length=0;
int ColoredBox::static_width=0;
int ColoredBox::getMaxAreaValue=0;

//end of My Class
int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    cout<<"Displaying Transposed: "<<endl;
    cb1->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb1->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area="<<cb1->getArea();
    cout<<endl<<"Max Area="<<cb1->getMaxArea();
    delete cb1;

    cout<<"\n\nEnter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    cout<<"Displaying Transposed: "<<endl;
    cb2->displayTransposed();
    cout<<"Displaying Wider: "<<endl;
    cb2->displayWider();
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb2->displayChess(col2);
    cout<<"Displaying original again:"<<endl;
    cb2->display();
    cout<<endl<<"Area="<<cb2->getArea();
    cout<<endl<<"Max Area="<<cb2->getMaxArea();
    delete cb2;
    return 0;
}
