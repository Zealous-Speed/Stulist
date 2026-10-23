#include"Mystring.h"
#ifndef _STUDENT
#define _STUDENT

class Student {
    public:
        Student(): _id(0), _score(0) {}
        Student(int id, const Mystring & name, const Mystring & prof, double score)
            : _id(id), _name(name), _prof(prof), _score(score) {}
        Student(const Student & s)
            : _id(s._id), _score(s._score), _name(s._name), _prof(s._prof) {}
        Student(Student && s) noexcept
            : _id(s._id), 
              _name(std::move(s._name)), 
              _prof(std::move(s._prof)), 
              _score(s._score) {
            s._id = 0;
            s._score = 0;
        }
        Student & operator = (const Student & s) = default;
        Student & operator = (Student && s) noexcept {
            if (this != &s) {
                _id = s._id;
                _name = std::move(s._name);
                _prof = std::move(s._prof);
                _score = s._score;
                s._id = 0;
                s._score = 0;
            }
            return *this;
        }
        ~Student() {}

        int get_id() const { return _id; };
        double get_score() const { return _score; };
        const Mystring & get_name() const { return _name; };
        const Mystring & get_prof() const { return _prof; };

    private :
        int _id;
        double _score;
        Mystring _name, _prof;
};

#endif