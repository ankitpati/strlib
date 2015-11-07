/* strlib.hpp */
/* String handling class library for C++
 *
 * Copyright 2013 Ankit Pati <ankitpati@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the  terms of the GNU Lesser General Public License as published by the  Free
 * Software Foundation; either version 3 of the License, or (at your option) any
 * later version.
 *
 * This  library is distributed in the hope that it will be useful, but  WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You  should  have received a copy of the GNU Lesser  General  Public  License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef apSTRLIB_HPP
#define apSTRLIB_HPP

#include <fstream>
#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>

class cString{
    char *str;
    size_t len;

    void srealloc(size_t) throw(std::bad_alloc);
public:
     cString(               ),
     cString(const cString &),
     cString(char *         ),
     cString(int            ),
    ~cString(               ),
    operator char *(        ) const throw(std::bad_alloc),
    operator int   (        ) const;

    void operator~ ();

    char &operator[](size_t);

    bool operator==(const cString &) const,
         operator==(char *         ) const,
         operator==(int            ) const,
         operator!=(const cString &) const,
         operator!=(char *         ) const,
         operator!=(int            ) const,
         operator<=(const cString &) const,
         operator<=(char *         ) const,
         operator<=(int            ) const,
         operator>=(const cString &) const,
         operator>=(char *         ) const,
         operator>=(int            ) const,
         operator< (const cString &) const,
         operator< (char *         ) const,
         operator< (int            ) const,
         operator> (const cString &) const,
         operator> (char *         ) const,
         operator> (int            ) const,
         operator! (               ) const;

    cString &operator =(const cString &),
            &operator =(char *         ),
            &operator =(int            ),
             operator+ (const cString &),
             operator+ (char *         ),
             operator+ (int            ),
            &operator+=(const cString &),
            &operator+=(char *         ),
            &operator+=(int            ),
             operator- (const cString &),
             operator- (char *         ),
             operator- (int            ),
            &operator-=(const cString &),
            &operator-=(char *         ),
            &operator-=(int            ),
             operator/ (const cString &),
             operator/ (char *         ),
             operator/ (int            ),
            &operator/=(const cString &),
            &operator/=(char *         ),
            &operator/=(int            ),
            &getstr(std::istream &, int, size_t),
            &revstr();

    friend bool operator==(char *, const cString &),
                operator==(int   , const cString &),
                operator!=(char *, const cString &),
                operator!=(int   , const cString &),
                operator<=(char *, const cString &),
                operator<=(int   , const cString &),
                operator>=(char *, const cString &),
                operator>=(int   , const cString &),
                operator< (char *, const cString &),
                operator< (int   , const cString &),
                operator> (char *, const cString &),
                operator> (int   , const cString &);

    friend std::istream &operator>>(std::istream &fin , const cString &ob);

    friend std::ostream &operator<<(std::ostream &fout, const cString &ob);
};

void cString::srealloc(size_t m) throw(std::bad_alloc)
{
    size_t i;
    char *dst;
    dst=new char[m];
    if(str && len+1){
        for(i=0; i<len+1 && i<m; ++i) dst[i]=str[i];
        delete []str;
    }
    str=dst;
}

cString::cString()
{
    str=NULL;
    len=0;
}

cString::cString(const cString &ob)
{
    str=NULL;
    len=0;
    if(!ob.str) return;
    len=ob.len;
    srealloc(ob.len+1);
    ::strcpy(str, ob.str);
}

cString::cString(char *s)
{
    str=NULL;
    len=0;
    if(!s) return;
    len=::strlen(s);
    srealloc(len+1);
    ::strcpy(str, s);
}

cString::cString(int num)
{
    size_t i, j;
    char *hnd, temp;
    str=NULL;
    len=0;
    if(num<0){
        srealloc(len+2);
        str[len++]='-';
        str[len]='\0';
        num=-num;
        i=j=1;
    }
    else i=j=0;
    do{
        srealloc(len+2);
        str[len++]='0'+num%10;
        ++j;
    } while(num/=10);
    str[len]='\0';
    hnd=str+len-j;
    for(--j; i<j; ++i, --j){
        temp=hnd[i];
        hnd[i]=hnd[j];
        hnd[j]=temp;
    }
}

cString::~cString()
{
    if(str) delete []str;
}

cString::operator char *() const throw(std::bad_alloc)
{
    char *cpys, *cpyd, *ret;
    if(!str) return NULL;
    ret=new char[len+1];
    cpys=str;
    cpyd=ret;
    while((*cpyd++=*cpys++));
    return ret;
}

cString::operator int() const
{
    if(!str) return 0;
    return ::atoi(str);
}

void cString::operator~()
{
    if(str) delete []str;
    str=NULL;
    len=0;
}

char &cString::operator[](size_t ind)
{
    static char enull;
    if(ind<len) return str[ind];
    return enull='\0';
}

bool cString::operator==(const cString &ob) const
{
    size_t n;
    if(!str || !ob.str) return false;
    if(len!=ob.len) return false;
    for(n=0; n<len; ++n)
        if(str[n]!=ob.str[n]) return false;
    return true;
}

bool cString::operator==(char *s) const
{
    cString tmp(s);
    return *this==tmp;
}

bool cString::operator==(int num) const
{
    cString tmp(num);
    return *this==tmp;
}

bool cString::operator!=(const cString &ob) const
{
    return !(*this==ob);
}

bool cString::operator!=(char *s) const
{
    cString tmp(s);
    return *this!=tmp;
}

bool cString::operator!=(int num) const
{
    cString tmp(num);
    return *this!=tmp;
}

bool cString::operator<(const cString &ob) const
{
    size_t n;
    if(!str || !ob.str) return false;
    for(n=0; n<len && n<ob.len; ++n)
        if(str[n]!=ob.str[n]) break;
    if(str[n]-ob.str[n]<0) return true;
    return false;
}

bool cString::operator<(char *s) const
{
    cString tmp(s);
    return *this<tmp;
}

bool cString::operator<(int num) const
{
    cString tmp(num);
    return *this<tmp;
}

bool cString::operator>(const cString &ob) const
{
    return *this!=ob && !(*this<ob);
}

bool cString::operator>(char *s) const
{
    cString tmp(s);
    return *this>tmp;
}

bool cString::operator>(int num) const
{
    cString tmp(num);
    return *this>tmp;
}

bool cString::operator<=(const cString &ob) const
{
    return !(*this>ob);
}

bool cString::operator<=(char *s) const
{
    cString tmp(s);
    return *this<=tmp;
}

bool cString::operator<=(int num) const
{
    cString tmp(num);
    return *this<=tmp;
}

bool cString::operator>=(const cString &ob) const
{
    return !(*this<ob);
}

bool cString::operator>=(char *s) const
{
    cString tmp(s);
    return *this>=tmp;
}

bool cString::operator>=(int num) const
{
    cString tmp(num);
    return *this>=tmp;
}

bool cString::operator!() const
{
    return str?false:true;
}

cString &cString::operator=(const cString &ob)
{
    ~*this;
    return *this+=ob;
}

cString &cString::operator=(char *s)
{
    ~*this;
    return *this+=s;
}

cString &cString::operator=(int num)
{
    ~*this;
    return *this+=num;
}

cString cString::operator+(const cString &ob)
{
    cString ret(*this);
    return ret+=ob;
}

cString cString::operator+(char *s)
{
    cString ret(*this);
    return ret+=s;
}

cString cString::operator+(int num)
{
    cString ret(*this);
    return ret+=num;
}

cString &cString::operator+=(const cString &ob)
{
    char *cpys, *cpyd;
    if(!ob.str) return *this;
    srealloc(len+ob.len+1);
    cpys=ob.str;
    cpyd=str+len;
    while((*cpyd++=*cpys++));
    len+=ob.len;
    return *this;
}

cString &cString::operator+=(char *s)
{
    cString tmp(s);
    return *this+=tmp;
}

cString &cString::operator+=(int num)
{
    cString tmp(num);
    return *this+=tmp;
}

cString cString::operator-(const cString &ob)
{
    cString ret(*this);
    return ret-=ob;
}

cString cString::operator-(char *s)
{
    cString ret(*this);
    return ret-=s;
}

cString cString::operator-(int num)
{
    cString ret(*this);
    return ret-=num;
}

cString &cString::operator-=(const cString &ob)
{
    char *occd, *occs;
    if(!str || !ob.str || len<ob.len || !*ob.str) return *this;
    if((occd=::strstr(str+len-ob.len, ob.str))){
        occs=occd+ob.len;
        while((*occd++=*occs++));
        len-=ob.len;
        srealloc(len+1);
    }
    return *this;
}

cString &cString::operator-=(char *s)
{
    cString tmp(s);
    return *this-=tmp;
}

cString &cString::operator-=(int num)
{
    cString tmp(num);
    return *this-=tmp;
}

cString cString::operator/(const cString &ob)
{
    cString ret(*this);
    return ret/=ob;
}

cString cString::operator/(char *s)
{
    cString ret(*this);
    return ret/=s;
}

cString cString::operator/(int num)
{
    cString ret(*this);
    return ret/=num;
}

cString &cString::operator/=(const cString &ob)
{
    char *occd, *occs;
    if(!str || !ob.str || !*ob.str) return *this;
    while((occd=::strstr(str, ob.str))){
        occs=occd+ob.len;
        while((*occd++=*occs++));
        len-=ob.len;
        srealloc(len+1);
    }
    return *this;
}

cString &cString::operator/=(char *s)
{
    cString tmp(s);
    return *this/=tmp;
}

cString &cString::operator/=(int num)
{
    cString tmp(num);
    return *this/=tmp;
}

cString &cString::getstr(std::istream &fin=std::cin, int delim='\n',
                         size_t bytes=~(size_t)0)
{
    char c;
    srealloc(1);
    for(len=0; (c=fin.get())!=delim && !fin.eof() && len<bytes; str[len++]=c)
        srealloc(len+2);
    str[len]='\0';
    return *this;
}

cString &cString::revstr()
{
    size_t i, j;
    char tmp;
    for(i=0, j=len; i<j; ++i){
        tmp=str[i];
        str[i]=str[--j];
        str[j]=tmp;
    }
    return *this;
}

bool operator==(char *s, const cString &ob)
{
    return ob==s;
}

bool operator==(int num, const cString &ob)
{
    return ob==num;
}

bool operator!=(char *s, const cString &ob)
{
    return ob!=s;
}

bool operator!=(int num, const cString &ob)
{
    return ob!=num;
}

bool operator<(char *s, const cString &ob)
{
    return ob<s;
}

bool operator<(int num, const cString &ob)
{
    return ob<num;
}

bool operator>(char *s, const cString &ob)
{
    return ob>s;
}

bool operator>(int num, const cString &ob)
{
    return ob>num;
}

bool operator<=(char *s, const cString &ob)
{
    return ob<=s;
}

bool operator<=(int num, const cString &ob)
{
    return ob<=num;
}

bool operator>=(char *s, const cString &ob)
{
    return ob>=s;
}

bool operator>=(int num, const cString &ob)
{
    return ob>=num;
}

std::istream &operator>>(std::istream &fin, cString &ob)
{
    ob.getstr(fin);
    return fin;
}

std::ostream &operator<<(std::ostream &fout, const cString &ob)
{
    if(ob.str) fout<<ob.str;
    return fout;
}

#endif
/* end of strlib.hpp */
