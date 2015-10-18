/* strlib.cpp */
/* Demonstration of strlib.hpp
 *
 * Copyright 2013 Ankit Pati <ankitpati@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation;  either version 3 of the License, or (at your option)  any  later
 * version.
 *
 * This  program is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR  A  PARTICULAR  PURPOSE.  See the GNU General  Public  License  for  more
 * details.
 *
 * You should have received a copy of the GNU General Public License along  with
 * this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * The GPL v3 text can be found at <./gpl.txt>.
 */

#include <iostream>
#include <cstdlib>
#include "strlib.hpp"
using namespace std;

int main()
{
    cString cst1, cst2, tmp;
    char *ext;
    int num;
    cout<<"+-----------------------------------------------------------+"<<endl
        <<"|                Demonstration of strlib.hpp                |"<<endl
        <<"+-----------------------------------------------------------+"<<endl
        <<endl
        <<"Enter 2 strings"<<endl;
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
        <<"char String: "<<ext<<endl
        <<"int        : "<<num<<endl
        <<"All following operations are of the form"<<endl
        <<"<String 1> operator <String 2 | char String | int>"
        <<endl;
    cout<<"Press enter to continue...";
    cin.get();
    cout<<endl
        <<"Class Operations"<<endl;
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
        <<"Array Operations"<<endl;
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
        <<"Integer Operations"<<endl;
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
    cout<<"$ ( =) : "<<(cst1 =num )<<endl
        <<endl;
    cout<<"+-----------------------------------------------------------+"<<endl
        <<"|                   End of Demonstration                    |"<<endl
        <<"+-----------------------------------------------------------+"<<endl;
    cin.get();
    return 0;
}
/* end of strlib.cpp */
