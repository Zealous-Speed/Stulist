#include<iostream>
#include<iomanip>
#include<string.h>
#include"StudentList.h"
using namespace std;

int main(){
    cout << "--------- 欢迎进入学生信息管理系统！---------\n";
    StudentList stul;
    int t0 = 1;
    while (t0){
        int t1;
        cout << "系统现有人数：" << stul.List_len() << '\n';
        cout << "系统容量：" << stul.List_size() << '\n';
        cout << "\n请输入您需要执行的操作；\n";
        cout << "1. 录入学生信息；\n";
        cout << "2. 删除学生；\n";
        cout << "3. 显示学生信息；\n";
        cout << "4. 修改学生信息；\n";
        cout << "5. 结束程序；\n";
        cin >> t1;
        switch (t1){
            case 1 : {
                cout << "\n请输入学生的完整信息：\n格式：学号（8位，确保不重复），姓名（字符<=100），专业（字符<=100，分数（0<=数值<=100）\n";
                int num;
                double score;
                char name[1005], prof[1005];
                cin >> num >> name >> prof >> score;
                while (num < 10000000 || num > 99999999){
                    cout << "学号必须是8位！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (stul.search_i_student(num) != -1){
                    cout << "学号重复！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (strlen(name) > 100){
                    cout << "姓名过长！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (strlen(prof) > 100){
                    cout << "姓名过长！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (score < 0 || score > 100){
                    cout << "分数超出数据范围！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                Mystring n, p;
                n.set_string(name);
                p.set_string(prof);
                Student s(num, Mystring(n), Mystring(p), score);
                int i = stul.new_student(s);
                if (i == 0)
                    cout << "系统空间不足！请稍后尝试。\n";
                else 
                    cout << "录入成功！\n\n";
                break;
            }

            case 2 : {
                cout << "\n本系统目前只支持 按照学号 唯一 删除学生 全部 信息！\n";
                cout << "请输入要删除学生的学号：";
                int num;
                cin >> num;
                while (num < 10000000 || num > 99999999){
                    cout << "学号必须是8位！请重新输入。\n";
                    cin >> num;
                }
                Student s;
                int i = stul.delete_student(num, s);
                if (i == 0)
                    cout << "目前学生列表为空，无法进行删除操作。\n";
                else if (i == -1)
                    cout << "未找到学号为：" << num << "的学生，无法进行删除操作。\n";
                else 
                    cout << "学生：" << setw(10) << s.get_id() 
                    << setw(10) << s.get_name().get_string() 
                    << setw(10) << s.get_prof().get_string() 
                    << setw(10) << s.get_score() 
                    << "删除成功！\n";
                break;
            }
            case 3 : {
                int t2;
                cout << "\n请选择查询方式：\n";
                cout << "1. 查询所有学生信息；\n"; 
                cout << "2. 按分数查询；\n"; 
                cout << "3. 按学号查询；\n";
                cout << "4. 按姓名查询；\n";
                cout << "5. 按专业查询；\n";
                cin >> t2;
                switch (t2) {
                    case 1 : {
                        Student *sp;
                        int i = stul.show_student(sp);
                        if (i == 0){
                            cout << "无符合条件的学生！\n";
                        }
                        else{
                            cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                            for (int j = 0; j < i; j ++)
                                cout << setw(10) << sp[j].get_id() 
                                << setw(10) << sp[j].get_name().get_string() 
                                << setw(10) << sp[j].get_prof().get_string() 
                                << setw(10) << sp[j].get_score() << "\n";
                        }
                        break;
                    }
                    case 2 : {
                        int t3;
                        cout << "\n请继续选择查询方式：\n";
                        cout << "1. 按某一分数查询；\n"; 
                        cout << "2. 按分数范围查询；\n";
                        cin >> t3;
                        switch(t3) {
                            case 1 :{
                                Student *sp;
                                double score;
                                cout << "请输入分数：";
                                cin >> score;
                                while (score < 0 || score > 100){
                                    cout << "分数超出数据范围！请重新输入。\n";
                                    cin >> score;
                                }
                                int i = stul.show_student(score, sp);
                                if (i == 0)
                                    cout << "无符合条件的学生！\n";
                                else {
                                    cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                                    for (int j = 0; j < i; j ++)
                                        cout << setw(10) << sp[j].get_id() 
                                        << setw(10) << sp[j].get_name().get_string() 
                                        << setw(10) << sp[j].get_prof().get_string() 
                                        << setw(10) << sp[j].get_score() << "\n";
                                    delete[] sp;
                                    sp = nullptr;
                                }
                                break;
                            }

                            case 2 :{
                                Student *sp;
                                double min, max;                     
                                cout << "请输入分数下限：";
                                cin >> min;
                                while (min < 0 || min > 100){
                                    cout << "分数超出数据范围！请重新输入。\n";
                                    cin >> min;
                                }                                
                                cout << "请输入分数上限：";
                                cin >> max;
                                while (max < 0 || max > 100){
                                    cout << "分数超出数据范围！请重新输入。\n";
                                    cin >> max;
                                } 
                                int i = stul.show_student(sp, min, max);
                                if (i == 0)
                                    cout << "无符合条件的学生！\n";
                                else {
                                    cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                                    for (int j = 0; j < i; j ++)
                                        cout << setw(10) << sp[j].get_id() 
                                        << setw(10) << sp[j].get_name().get_string() 
                                        << setw(10) << sp[j].get_prof().get_string() 
                                        << setw(10) << sp[j].get_score() << "\n";
                                    delete[] sp;
                                    sp = nullptr;
                                }
                                break;
                            }
                            default : { 
                                cout << "请输入1~2之间的数字！\n";
                                cin.clear();
                                cin.ignore(100000, '\n');
                                break;
                            }
                        }
                        break;
                    }
                    case 3 : {
                        int num;
                        cout << "请输入学号：";
                        cin >> num;
                        while (num < 10000000 || num > 99999999){
                            cout << "学号必须是8位！请重新输入。\n";
                            cin >> num;
                        }
                        if (stul.search_i_student(num) == -1){
                            cout << "无符合条件的学生！\n";
                            break;
                        }
                        Student s = stul.show_student(num);
                        cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                        cout << setw(10) << s.get_id() 
                        << setw(10) << s.get_name().get_string() 
                        << setw(10) << s.get_prof().get_string() 
                        << setw(10) << s.get_score() << "\n";                     
                        break;
                    }
                    case 4 :{
                        Student *sp;
                        char name[1005];
                        cout << "请输入姓名：";
                        cin >> name;
                        while (strlen(name) > 100){
                            cout << "姓名过长！请重新输入。\n";
                            cin >> name;
                        }
                        int i = stul.show_student(Mystring(name), sp);
                        if (i == 0)
                            cout << "无符合条件的学生！\n";
                        else {
                            cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                            for (int j = 0; j < i; j ++)
                                cout << setw(10) << sp[j].get_id() 
                                << setw(10) << sp[j].get_name().get_string() 
                                << setw(10) << sp[j].get_prof().get_string() 
                                << setw(10) << sp[j].get_score() << "\n";
                            delete[] sp;
                            sp = nullptr;
                        }
                        break;
                    }
                    case 5 :{
                        Student *sp;
                        char prof[1005];
                        cout << "请输入专业：";
                        cin >> prof;
                        while (strlen(prof) > 100){
                            cout << "姓名过长！请重新输入。\n";
                            cin >> prof;
                        }
                        int i = stul.show_student(sp, Mystring(prof));
                        if (i == 0)
                            cout << "无符合条件的学生！\n";
                        else {
                            cout << setw(10) << "学号" << setw(10) << "姓名"
                                 << setw(10) << "专业" << setw(10) << "分数" << '\n';
                            for (int j = 0; j < i; j ++)
                                cout << setw(10) << sp[j].get_id() 
                                << setw(10) << sp[j].get_name().get_string() 
                                << setw(10) << sp[j].get_prof().get_string() 
                                << setw(10) << sp[j].get_score() << "\n";
                            delete[] sp;
                            sp = nullptr;
                        }
                        break;
                    }
                    default :{
                        cout << "请输入1~5之间的数字！\n";
                        cin.clear();
                        cin.ignore(100000, '\n');
                        break;
                    }
                }
                break;
            }
            case 4 : {
                cout << "\n本系统目前只支持 按照学号 唯一 修改学生 全部 信息！\n";
                cout << "请输入要修改的学生学号：";
                int num0;
                cin >> num0;
                while (num0 < 10000000 || num0 > 99999999){
                    cout << "学号必须是8位！请重新输入。\n";
                    cin >> num0;
                }
                cout << "请输入修改后的学生信息：";
                int num;
                double score;
                char name[1005], prof[1005];
                cin >> num >> name >> prof >> score;
                while (num < 10000000 || num > 99999999){
                    cout << "学号必须是8位！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (stul.search_i_student(num) != -1 && num != num0){
                    cout << "学号重复！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (strlen(name) > 100){
                    cout << "姓名过长！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (strlen(prof) > 100){
                    cout << "姓名过长！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                while (score < 0 || score > 100){
                    cout << "分数超出数据范围！请重新输入。\n";
                    cin >> num >> name >> prof >> score;
                }
                Student s(num, Mystring(name), Mystring(prof), score);
                bool i = stul.modify_student(num0, s);
                if (i == 0)
                    cout << "未找到学号为：" << num0 << "的学生，无法进行修改操作。\n";
                else 
                    cout << "学生：" << setw(10) << s.get_id() 
                    << setw(10) << s.get_name().get_string() 
                    << setw(10) << s.get_prof().get_string() 
                    << setw(10) << s.get_score() << "修改成功！\n";
                break;
            }
            case 5 : {
                t0 = 0;
                break;
            }
            default : {
                cout << "请输入1~5的数字！\n";
                cin.clear();
                cin.ignore(100000, '\n');
                break;
            }
        }
    }
    return 0;
}