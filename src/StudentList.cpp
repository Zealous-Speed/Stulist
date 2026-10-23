#include"StudentList.h"
#define DELTA 10

StudentList::StudentList(Student *p, int len)
    : _len(0), _size(0) {
    if (p == nullptr)
        _list = nullptr;
    else{
        _len = len;
        _list = new Student[_len];
        for (int i = 0; i < _len; i ++)
           _list[i] = p[i];
        _size = _len;
        // 复制长度并申请对应大小的空间，逐元素赋值
    }
}

StudentList::StudentList(const StudentList & s)
    : _len(s._len), _size(s._size) {
        _list = new Student[_size];
        for (int i = 0; i < _len; i ++)
            _list[i] = s._list[i];
    // 复制长度并申请对应大小的空间，逐元素赋值
}

StudentList & StudentList::operator = (const StudentList & s) {
    if (this != &s){
        delete[] _list;
        _len = s._len;
        _size = s._size;
        _list = new Student[_size];
        for (int i = 0; i < _len; i ++)
            _list[i] = s._list[i];
    }
    return *this;
}

int StudentList::new_student(Student &s){
    if (_len >= _size){
        Student * p = new Student[_len + DELTA];
        for (int i = 0; i < _len; i ++)
            p[i] = _list[i];
        delete[] _list;
        _list = p;
        _size = _len + DELTA;        
    }
    _list[_len] = s;
    _len ++;
    return 1;
}

int StudentList::search_i_student(int num){
    for (int i = 0; i < _len; i ++){
        if (_list[i].get_id() == num){
            return i;
        }
    }
    return -1;
}

int StudentList::delete_student(int num, Student &s){
    if (_len <= 0)
        return 0;
    else {
        int i = search_i_student(num);
        if (i != -1){
            s = _list[i];
            for (int j = i; j < _len - 1; j ++)
                _list[j] = _list[j+1];
            _len --;
            return 1;
        }
        else
            return -1;
    }
}

Student & StudentList::show_student(int num){
    int i = search_i_student(num);
    if (i != -1)
        return _list[i];
}

int StudentList::show_student(Mystring name, Student *&s){
    int num = 0;
    for (int i = 0; i < _len; i ++)
        if (name == _list[i].get_name())
            num ++;
    Student *p = new Student[num];
    s = p;
    for (int i = 0; i < _len; i ++)
        if (name == _list[i].get_name()){
            *p = _list[i];
            p ++;
        }
    return p-s;
}

int StudentList::show_student(Student *&s, Mystring prof){
    int num = 0;
    for (int i = 0; i < _len; i ++)
        if (prof == _list[i].get_prof())
            num ++;
    Student *p = new Student[num];
    s = p;
    for (int i = 0; i < _len; i ++)
        if (prof == _list[i].get_prof()){
            *p = _list[i];
            p ++;
        }
    return p-s;
}


int StudentList::show_student(double score, Student *&s){
    int num = 0;
    for (int i = 0; i < _len; i ++)
        if (score == _list[i].get_score())
            num ++;
    Student *p = new Student[num];
    s = p;
    for (int i = 0; i < _len; i ++)
        if (score == _list[i].get_score()){
            *p = _list[i];
            p ++;
        }
    return p-s;
}

int StudentList::show_student(Student *&s, double min, double max){
    int num = 0;
    for (int i = 0; i < _len; i ++)
        if (_list[i].get_score() >= min && _list[i].get_score() <= max)
            num ++;
    Student *p = new Student[num];
    s = p;
    for (int i = 0; i < _len; i ++)
        if (_list[i].get_score() >= min && _list[i].get_score() <= max){
            *p = _list[i];
            p ++;
        }
    return p-s;
}

bool StudentList::modify_student(int num, Student &s){
    int i = search_i_student(num);
    if (i == -1)
        return 0;
    _list[i] = s;
    return 1;
}