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
 *
 * The GPL v3 text can be found at <./gpl.txt>. The LGPL v3 text can be found at
 * <./lgpl.txt>.
 */

#ifndef apSTRLIB_HPP
#define apSTRLIB_HPP

#include <fstream>
#include <iostream>
#include <new>
#include <cstdlib>
#include <cctype>

class cString{
    char *str;
    size_t len;
    char *srealloc(char *, size_t, size_t) throw(std::bad_alloc),
         *strinstr(char *, char *);
    void snull();
public:
    cString(), cString(const cString &), cString(char *), cString(int),
    ~cString();
    cString &operator =(const cString &), &operator =(char *), &operator =(int),
             operator+ (const cString &),  operator+ (char *),  operator+ (int),
            &operator+=(const cString &), &operator+=(char *), &operator+=(int),
             operator- (const cString &),  operator- (char *),  operator- (int),
            &operator-=(const cString &), &operator-=(char *), &operator-=(int),
             operator/ (const cString &),  operator/ (char *),  operator/ (int),
            &operator/=(const cString &), &operator/=(char *), &operator/=(int),
            &getstr(std::istream &, int, size_t), &revstr();
    bool operator==(const cString &), operator==(char *), operator==(int),
         operator!=(const cString &), operator!=(char *), operator!=(int),
         operator<=(const cString &), operator<=(char *), operator<=(int),
         operator>=(const cString &), operator>=(char *), operator>=(int),
         operator< (const cString &), operator< (char *), operator< (int),
         operator> (const cString &), operator> (char *), operator> (int),
         operator! ();
    void operator~ ();
    char &at(size_t), *extract() throw(std::bad_alloc);
    int atoi();
    friend std::istream &operator>>(std::istream &fin , const cString &ob);
    friend std::ostream &operator<<(std::ostream &fout, const cString &ob);
};

char *cString::srealloc(char *s, size_t n, size_t m) throw(std::bad_alloc)
{
    size_t i;
    char *dst;
    dst=new char[m];
    if(s && n){
        for(i=0; i<n && i<m; ++i) dst[i]=s[i];
        delete []s;
    }
    return dst;
}

char *cString::strinstr(char *hay, char *ned)
{
    size_t pos, nlen, i;
    for(nlen=0; ned[nlen]; ++nlen);
    if(!nlen) return NULL;
    for(i=0; hay[i] && i<nlen; ++i);
    if(i!=nlen) return NULL;
    for(pos=0; hay[pos+nlen-1]; ++pos){
        for(i=0; i<nlen && (hay+pos)[i]==ned[i]; ++i);
        if(i==nlen) return hay+pos;
    }
    return NULL;
}

void cString::snull()
{
    if(str) delete []str;
    str=NULL;
    len=0;
}

cString::cString()
{
    str=NULL;
    len=0;
}

cString::cString(const cString &ob)
{
    char *cpys, *cpyd;
    str=NULL;
    len=0;
    if(!ob.str) return;
    len=ob.len;
    str=srealloc(str, len+1, ob.len+1);
    cpys=ob.str;
    cpyd=str;
    while((*cpyd++=*cpys++));
}

cString::cString(char *s)
{
    char *cpy;
    str=NULL;
    len=0;
    if(!s) return;
    for(len=0; s[len]; ++len);
    str=srealloc(str, len+1, len+1);
    cpy=str;
    while((*cpy++=*s++));
}

cString::cString(int num)
{
    size_t i, j;
    char *hnd, temp;
    str=NULL;
    len=0;
    if(num<0){
        str=srealloc(str, len+1, len+2);
        str[len++]='-';
        str[len]='\0';
        num=-num;
        i=j=1;
    }
    else i=j=0;
    do{
        str=srealloc(str, len+1, len+2);
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

cString &cString::operator=(const cString &ob)
{
    snull();
    return *this+=ob;
}

cString &cString::operator=(char *s)
{
    snull();
    return *this+=s;
}

cString &cString::operator=(int num)
{
    snull();
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
    str=srealloc(str, len+1, len+ob.len+1);
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
    if(!str || !ob.str || len<ob.len) return *this;
    if((occd=strinstr(str+len-ob.len, ob.str))){
        occs=occd+ob.len;
        while((*occd++=*occs++));
        len-=ob.len;
        str=srealloc(str, len+1, len+1);
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
    if(!str || !ob.str) return *this;
    while((occd=strinstr(str, ob.str))){
        occs=occd+ob.len;
        while((*occd++=*occs++));
        len-=ob.len;
        str=srealloc(str, len+1, len+1);
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

bool cString::operator==(const cString &ob)
{
    size_t n;
    if(!str || !ob.str) return false;
    if(len!=ob.len) return false;
    for(n=0; n<len; ++n)
        if(str[n]!=ob.str[n]) return false;
    return true;
}

bool cString::operator==(char *s)
{
    cString tmp(s);
    return *this==tmp;
}

bool cString::operator==(int num)
{
    cString tmp(num);
    return *this==tmp;
}

bool cString::operator!=(const cString &ob)
{
    return !(*this==ob);
}

bool cString::operator!=(char *s)
{
    cString tmp(s);
    return *this!=tmp;
}

bool cString::operator!=(int num)
{
    cString tmp(num);
    return *this!=tmp;
}

bool cString::operator<(const cString &ob)
{
    size_t n;
    if(!str || !ob.str) return false;
    for(n=0; n<len && n<ob.len; ++n)
        if(str[n]!=ob.str[n]) break;
    if(str[n]-ob.str[n]<0) return true;
    return false;
}

bool cString::operator<(char *s)
{
    cString tmp(s);
    return *this<tmp;
}

bool cString::operator<(int num)
{
    cString tmp(num);
    return *this<tmp;
}

bool cString::operator>(const cString &ob)
{
    return *this!=ob && !(*this<ob);
}

bool cString::operator>(char *s)
{
    cString tmp(s);
    return *this>tmp;
}

bool cString::operator>(int num)
{
    cString tmp(num);
    return *this>tmp;
}

bool cString::operator<=(const cString &ob)
{
    return !(*this>ob);
}

bool cString::operator<=(char *s)
{
    cString tmp(s);
    return *this<=tmp;
}

bool cString::operator<=(int num)
{
    cString tmp(num);
    return *this<=tmp;
}

bool cString::operator>=(const cString &ob)
{
    return !(*this<ob);
}

bool cString::operator>=(char *s)
{
    cString tmp(s);
    return *this>=tmp;
}

bool cString::operator>=(int num)
{
    cString tmp(num);
    return *this>=tmp;
}

bool cString::operator!()
{
    return str?false:true;
}

void cString::operator~()
{
    snull();
}

cString &cString::getstr(std::istream &fin=std::cin, int delim='\n',
                         size_t bytes=~(size_t)0)
{
    char c;
    str=srealloc(str, len+1, 1);
    for(len=0; (c=fin.get())!=delim && !fin.eof() && len<bytes; str[len++]=c)
        str=srealloc(str, len+1, len+2);
    str[len]='\0';
    return *this;
}

cString &cString::revstr()
{
    size_t i, j;
    char tmp;
    for(i=0, j=len; i<j; ++i){
        tmp   =str[i];
        str[i]=str[--j];
        str[j]=tmp;
    }
    return *this;
}

char &cString::at(size_t ind)
{
    static char enull;
    if(ind<len) return str[ind];
    return enull='\0';
}

char *cString::extract() throw(std::bad_alloc)
{
    char *cpys, *cpyd, *ret;
    if(!str) return NULL;
    ret=new char[len+1];
    cpys=str;
    cpyd=ret;
    while((*cpyd++=*cpys++));
    return ret;
}

int cString::atoi()
{
    size_t i;
    int sign, ret;
    for(i=0; isspace(str[i]); ++i);
    sign=(str[i]=='-')?-1:1;
    if(str[i]=='-' || str[i]=='+') ++i;
    for(ret=0; isdigit(str[i]) || isspace(str[i]) || str[i]==','; ++i)
        if(isdigit(str[i]))
            ret = ret*10 + (str[i]-'0');
    return sign*ret;
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
