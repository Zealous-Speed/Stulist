#include<iostream>
#ifndef _MYSTRING
#define _MYSTRING

class Mystring{
    public:
        Mystring() : _len(0), _start(nullptr) {}
        Mystring(const char * p);
        Mystring(const Mystring & s);
        Mystring(Mystring && s);
        Mystring & operator = (const Mystring & x);
        Mystring & operator = (Mystring && x);
        bool operator == (const Mystring & x) const;
        ~Mystring() { delete[] _start; }

        const char * get_string() const { return _start; }
        Mystring & set_string(const char * p = nullptr);
        Mystring & append(const char * p);
        Mystring & append(Mystring &s) {
            append(s._start);
            return *this;
        }
        int get_length() const { return _len; }

    private:
        char * _start;
        int _len;
};

inline bool Mystring::operator==(const Mystring & x) const {
    if (_len != x._len)
        return 0;
    else {
        for (int i = 0; i < _len; i ++)
            if (_start[i] != x._start[i])
                return 0;
        return 1;
    }
}

#endif