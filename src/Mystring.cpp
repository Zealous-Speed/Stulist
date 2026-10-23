#include<string.h>
#include"Mystring.h"
using namespace std;

Mystring::Mystring(const char * p): _len(0) {
    if (p == nullptr)
        _start = new char[1] {'\0'};
    else{
        _len = strlen(p);
        _start = new char[_len + 1];
        strcpy(_start, p);
    }
}

Mystring::Mystring(const Mystring & s): _len(s._len) {
    _start = new char[_len + 1];
    strcpy(_start, s._start);
}
Mystring::Mystring(Mystring && s)
    : _len(s._len), _start(s._start) {
        s._len = 0;
        s._start = nullptr;
    }

Mystring & Mystring::operator = (const Mystring & x) {
    if (this != &x){
        delete[] _start;
        _len = x._len;
        _start = new char[_len + 1];
        strcpy(_start, x._start);
    }
    return *this;
}
Mystring & Mystring::operator=(Mystring && s){
    if (this != &s){
        delete[] _start;
        _len = s._len;
        _start = s._start;
        s._start = nullptr;
        s._len = 0;
    }
    return *this;
}

Mystring & Mystring::set_string(const char * p){
    if (_start != p){
        char * q =  _start;
        if (p == nullptr){
            _len = 0;
            _start = new char[1] {'\0'};
        }
        else{
            _len = strlen(p);
            _start = new char[_len + 1];
            strcpy(_start, p);
        }
        delete[] q;
    }
    return *this;
}

Mystring & Mystring::append(const char * p){
    if (p != nullptr){
        int delta;
        for (delta = 0; p[delta] != '\0'; delta ++);
        char *p0 = new char[_len + delta + 1];
        for (int i = 0; i < _len; i ++)
            p0[i] = _start[i];
        for (int i = _len; i <= _len + delta; i ++)
            p0[i] = p[i-_len];
        _len += delta;
        delete[] _start;
        _start = p0;
    }
    return *this;
}