/* demo.cpp */
/* Demonstration of strlib.hpp
 * Copyright 2013 Ankit Pati <ankitpati@gmail.com>
 */

#include <iostream>
#include <cstdlib>
#include "libs/strlib.hpp"
using namespace std;

int main()
{
    cString cst1, cst2, tmp;
    char *ext;
    int num;
    cout<<"+-----------------------------------------------------------+"<<endl
        <<"|                Demonstration of strlib.hpp                |"<<endl
        <<"+-----------------------------------------------------------+"<<endl
        <<endl;

    cout<<"Enter 2 strings"<<endl;
    cin>>cst1>>cst2;

    cout<<"Enter an integer: ";
    cin>>tmp;

    num=(int)tmp;
    tmp=cst1;
    ext=(char *)cst2;

    cout<<endl
        <<"Parameters"<<endl
        <<"String 1   : "<<cst1<<endl
        <<"String 2   : "<<cst2<<endl
        <<"char Array : "<<ext<<endl
        <<"int        : "<<num<<endl;
    cout<<"Press enter to continue...";
    cin.get();

    cout<<endl
        <<"Class Operations"<<endl
        <<"<String 1> operator <String 2>"<<endl;
    cout<<"$ (==) : "<<(cst1==cst2?"true":"false")<<endl;
    cout<<"$ (!=) : "<<(cst1!=cst2?"true":"false")<<endl;
    cout<<"$ (< ) : "<<(cst1< cst2?"true":"false")<<endl;
    cout<<"$ (> ) : "<<(cst1> cst2?"true":"false")<<endl;
    cout<<"$ (<=) : "<<(cst1<=cst2?"true":"false")<<endl;
    cout<<"$ (>=) : "<<(cst1>=cst2?"true":"false")<<endl;
    cout<<"$ (+ ) : "<<(cst1+ cst2)<<endl;
    cout<<"$ (- ) : "<<(cst1- cst2)<<endl;
    cout<<"$ (/ ) : "<<(cst1/ cst2)<<endl;
    cout<<"$ (+=) : "<<(cst1+=cst2)<<endl;
    cout<<"$ (-=) : "<<(cst1-=cst2)<<endl;
    cout<<"$ (/=) : "<<(cst1/=cst2)<<endl;
    cout<<"$ ( =) : "<<(cst1 =cst2)<<endl;
    cout<<"Press enter to continue...";
    cin.get();

    cst1=tmp;
    cout<<endl
        <<"Array Operations"<<endl
        <<"<String 1> operator <char Array>"<<endl;
    cout<<"$ (==) : "<<(cst1==ext ?"true":"false")<<endl;
    cout<<"$ (!=) : "<<(cst1!=ext ?"true":"false")<<endl;
    cout<<"$ (< ) : "<<(cst1< ext ?"true":"false")<<endl;
    cout<<"$ (> ) : "<<(cst1> ext ?"true":"false")<<endl;
    cout<<"$ (<=) : "<<(cst1<=ext ?"true":"false")<<endl;
    cout<<"$ (>=) : "<<(cst1>=ext ?"true":"false")<<endl;
    cout<<"$ (+ ) : "<<(cst1+ ext )<<endl;
    cout<<"$ (- ) : "<<(cst1- ext )<<endl;
    cout<<"$ (/ ) : "<<(cst1/ ext )<<endl;
    cout<<"$ (+=) : "<<(cst1+=ext )<<endl;
    cout<<"$ (-=) : "<<(cst1-=ext )<<endl;
    cout<<"$ (/=) : "<<(cst1/=ext )<<endl;
    cout<<"$ ( =) : "<<(cst1 =ext )<<endl;
    cout<<"Press enter to continue...";
    cin.get();

    cst1=tmp;
    cout<<endl
        <<"Array Operations"<<endl
        <<"<char Array> operator <String 1>"<<endl;
    cout<<"$ (==) : "<<(ext==cst1 ?"true":"false")<<endl;
    cout<<"$ (!=) : "<<(ext!=cst1 ?"true":"false")<<endl;
    cout<<"$ (< ) : "<<(ext< cst1 ?"true":"false")<<endl;
    cout<<"$ (> ) : "<<(ext> cst1 ?"true":"false")<<endl;
    cout<<"$ (<=) : "<<(ext<=cst1 ?"true":"false")<<endl;
    cout<<"$ (>=) : "<<(ext>=cst1 ?"true":"false")<<endl;
    cout<<"Press enter to continue...";
    cin.get();

    cst1=tmp;
    cout<<endl
        <<"Integer Operations"<<endl
        <<"<String 1> operator <int>"<<endl;
    cout<<"$ (==) : "<<(cst1==num ?"true":"false")<<endl;
    cout<<"$ (!=) : "<<(cst1!=num ?"true":"false")<<endl;
    cout<<"$ (< ) : "<<(cst1< num ?"true":"false")<<endl;
    cout<<"$ (> ) : "<<(cst1> num ?"true":"false")<<endl;
    cout<<"$ (<=) : "<<(cst1<=num ?"true":"false")<<endl;
    cout<<"$ (>=) : "<<(cst1>=num ?"true":"false")<<endl;
    cout<<"$ (+ ) : "<<(cst1+ num )<<endl;
    cout<<"$ (- ) : "<<(cst1- num )<<endl;
    cout<<"$ (/ ) : "<<(cst1/ num )<<endl;
    cout<<"$ (+=) : "<<(cst1+=num )<<endl;
    cout<<"$ (-=) : "<<(cst1-=num )<<endl;
    cout<<"$ (/=) : "<<(cst1/=num )<<endl;
    cout<<"$ ( =) : "<<(cst1 =num )<<endl;
    cout<<"Press enter to continue...";
    cin.get();

    cst1=tmp;
    cout<<endl
        <<"Integer Operations"<<endl
        <<"<int> operator <String 1>"<<endl;
    cout<<"$ (==) : "<<(num==cst1 ?"true":"false")<<endl;
    cout<<"$ (!=) : "<<(num!=cst1 ?"true":"false")<<endl;
    cout<<"$ (< ) : "<<(num< cst1 ?"true":"false")<<endl;
    cout<<"$ (> ) : "<<(num> cst1 ?"true":"false")<<endl;
    cout<<"$ (<=) : "<<(num<=cst1 ?"true":"false")<<endl;
    cout<<"$ (>=) : "<<(num>=cst1 ?"true":"false")<<endl;

    cout<<endl
        <<"+-----------------------------------------------------------+"<<endl
        <<"|                   End of Demonstration                    |"<<endl
        <<"+-----------------------------------------------------------+"<<endl;
    cin.get();
    return 0;
}
/* end of demo.cpp */
