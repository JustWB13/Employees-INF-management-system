//
// Created by 吴波 on 2020/6/27.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM
string get_passwd();
inline int BKDRHash(string a);
void main_page();
void admin_check();
void admin_page();
void login();
void passwd();
void temp_employee();
void normal_employee();
void section_chief();
void general_manager();
string enter_passwd();

inline int BKDRHash(string a)
{
    long long hash=0;
    int ch=0;
    string::iterator i;
    i=a.begin();
    while(ch=(int)(*i++))
        hash=((hash*31)%999911659+ch)%999911659;
    return hash;
}

string get_passwd()//输入密码在终端不显示字符
{
    string tmp;
    system("stty -echo");
    cin>>tmp;
    system("stty echo");
    return tmp;
}

void main_page()
{
    int n;
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"* 欢迎来到公司员工信息管理系统 *"<<endl;
    cout<<"*       1.管理员入口       *"<<endl;
    cout<<"*       2.员工入口         *"<<endl;
    cout<<"*       0.退出            *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
    cin>>n;
    switch(n)
    {
        case 1:admin_check();break;
        case 2:login();break;
        case 0:break;
        default:
            cout<<"该选项不存在！请重新选择！"<<endl;
            getchar();getchar();
            main_page();
            break;
    }
}

void admin_check()
{
    //密码
    admin_page();
}

void admin_page()
{
    int n;
    cout<<"**************************"<<endl;
    cout<<"*     欢迎进入管理员菜单     *"<<endl;
    cout<<"*       1.添加员工         *"<<endl;
    cout<<"*       2.删除员工         *"<<endl;
    cout<<"*       3.修改员工信息      *"<<endl;
    cout<<"*       4.查询员工信息      *"<<endl;
    cout<<"*       5.员工工资统计      *"<<endl;
    cout<<"*       6.股票交易情况      *"<<endl;
    cout<<"*       0.退出            *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
    cin>>n;
    switch(n)
    {
        case 1:employee_add();break;
        case 2:employee_delete();break;
        case 3:INF_change();break;
        case 4:INF_search();break;
        case 5:wage_statistic();break;
        case 6:Stock_show();break;
        case 0:break;
        default:
            cout<<"该选项不存在！请重新选择！"<<endl;
            getchar();getchar();
            admin_page();
            break;
    }
}

void login()
{
    string id;
    char fir_id;
    int hash;
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入员工登陆菜单    *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请输入您的员工id:"
    cin>>id;
    fir_id=id.at(0);
    switch(fir_id):
    {
        case 1:
            for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
            {
                if(id==(*i).)
                {
                    hash = BKDRHash(enter_passwd());
                    if (hash == general_manager[i].gethash()) {
                        cout << "密码正确！欢迎总经理" << general_manager[i].getname() << "!" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        general_manager();
                    }
                    else
                    {
                        cout << "密码错误！返回主菜单！" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        main_page();
                    }
                }
            }
            if(i==general_manager.size())
            {
                cout<<"该员工不存在!返回主菜单！"<<endl;
                cout << "按任意键继续" << endl;
                getchar();
                system("CLS");
                main_page();
            }
            break;
    }
}

string enter_passwd()
{
    cout<<"请输入密码： "<<endl;
    string password;
    int i=0;
    char ch;
    while ((ch=_getch())!=13)
    {
        password+=ch;//string对象重载了+=
        cout<<"*";
    }
    return password;
}