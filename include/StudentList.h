#include"Student.h"
#ifndef _STUDENTLIST
#define _STUDENTLIST

class StudentList{
    public :
        // 默认构造函数：初始化
        StudentList() : _len(0), _size(0), _list(nullptr) {}        
        // 转型构造函数：参数为（Student数组首地址，数组长度）
        StudentList(Student *p, int n);                             
        // 复制构造函数：参数为（StudentList对象的左值引用）
        StudentList(const StudentList & s);                         
        // 移动构造函数：参数为（StudentList对象右值引用，可以是临时对象）
        StudentList(StudentList && s) noexcept 
            : _len(s._len), _size(s._size), _list(s._list) {
                s._len = 0;
                s._size = 0;
                s._list = nullptr;
        }                            

        // 复制复制运算符函数：参数为（StudentList对象的左值引用）
        StudentList & operator = (const StudentList & s);           
        // 移动赋值运算符函数：参数为（StudentList对象右值引用，可以是临时对象）
        StudentList & operator = (StudentList && s) noexcept {
            if (this != &s) {
                delete[] _list;
                _len = s._len;
                _size = s._size;
                _list = s._list;
                s._len = 0;
                s._size = 0;
                s._list = nullptr;
            }
            return *this;
        }                

        // 析构函数
        ~StudentList() { delete[] _list; }                          

        // 在StudentList对象中新增新的学生，参数为（Student对象）
        int new_student(Student &s);                                

        // 在StudentList对象中查找学号为num的学生，参数为（int 学号），返回值为该学生对应下标
        int search_i_student(int num);                              

        // 在StudentList对象中删除学号为num的学生，并将其信息保存在s中，参数为（int 学号，Student对象），返回值为状态码
        int delete_student(int num, Student &s);                    

        // 显示在StudentList对象中学号为num的学生，并将其信息返回，参数为（int 学号），返回值为Student对象
        Student & show_student(int num);                            
        // 显示在StudentList对象中姓名为name的学生，并将其信息保存在s中，参数为（Mystring对象，Student对象的指针引用），返回值为符合条件人数
        int show_student(Mystring name, Student *&s);               
        // 显示在StudentList对象中分数为score的学生，并将其信息保存在s中，参数为（double分数，Student对象的指针引用），返回值为符合条件人数
        int show_student(double score, Student *&s);                
        // 显示在StudentList对象中专业为prof的学生，并将其信息保存在s中，参数为（Mystring对象，Student对象的指针引用），返回值为符合条件人数
        int show_student(Student *&s, Mystring prof);               
        // 显示在StudentList对象中分数在min和max之间（包含边界值）的学生，并将其信息保存在s中，参数为（Student对象的指针引用，double分数下限，double分数上限），返回值为符合条件人数
        int show_student(Student *&s, double min = 0, double max = 100);  

        // 在StudentList对象中修改学号为num的学生，参数为（int 学号，Student对象），返回值为状态码
        bool modify_student(int num, Student &s); 

        int List_len() { return _len; }
        int List_size() { return _size; }

    private :
        Student *_list;
        int _len;
        int _size;
};

#endif