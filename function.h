//
// Created by 吴波 on 2020/6/27.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<set>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

#include"employee.h"
#include"stock.h"
#include"project.h"

string get_passwd();
inline int BKDRHash(string a);
void main_page();
bool admin_check();
void admin_page();
void login();
void passwd();
void temp_employee_page(string id);
void normal_employee_page(string id);
void section_chief_page(string id);
void general_manager_page(string id);
string enter_passwd();
void employee_add();//员工添加
void employee_delete();//员工删除
void INF_change();//员工信息修改
void INF_search();//员工信息查询
void wage_statistic();//员工工资统计
void Stock_show();//查看当前股票交易情况
void Stock_get();//股票购买
void Stock_sale();//股票出售
void TS_update(string s_id,vector<normal_employee> NE,vector<temp_employee> TE);//工作状态更新
void INF_update(string p_id,projects &P);//结束项目
void Project_start(vector<section_chief> SC,projects &P);//启动立项
void Office_add(string SC_id,set<string> E_id,vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC);//科室增加(需要一名科长的ID与至少一名普通员工的ID)
void Office_dismiss(string s_id,vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC);//科室解散(需要科室ID)

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
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"* 欢迎来到公司员工信息管理系统 *"<<endl;
    cout<<"*       1.管理员入口       *"<<endl;
    cout<<"*       2.员工入口         *"<<endl;
    cout<<"*       0.退出            *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

bool admin_check()
{
    string id;
    int hash;
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*   欢迎进入管理员登陆菜单   *"<<endl;
    cout<<"**************************"<<endl;
    hash = BKDRHash(enter_passwd());
    if (hash == admin_passwd)//管理员密码
    {
        return true;
    }
    else
    {
        return false;
    }
}

void admin_page()
{
    cout<<"**************************"<<endl;
    cout<<"*     欢迎进入管理员菜单     *"<<endl;
    cout<<"*       1.添加员工         *"<<endl;
    cout<<"*       2.删除员工         *"<<endl;
    cout<<"*       3.修改员工信息      *"<<endl;
    cout<<"*       4.查询员工信息      *"<<endl;
    cout<<"*       5.员工工资统计      *"<<endl;
    cout<<"*       6.股票交易情况      *"<<endl;
    cout<<"*       0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void login()
{
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入员工登陆菜单    *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请输入您的员工id:";
}

string enter_passwd()
{
    cout<<"请输入密码： "<<endl;
    string password;
    char ch;
    while ((ch=getchar())!=13)
    {
        password+=ch;//string对象重载了+=
        cout<<"*";
    }
    return password;
}

void temp_employee_page()
{
    int n;
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入临时雇员菜单    *"<<endl;
    cout<<"*      1.查询个人信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void normal_employee_page()
{
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入正式雇员菜单    *"<<endl;
    cout<<"*      1.查询个人信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.确认工作完成       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void section_chief_page()
{
    cout<<"**************************"<<endl;
    cout<<"*      欢迎进入科长菜单     *"<<endl;
    cout<<"*      1.查询科室信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.确认工作完成       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void general_manager_page()
{
    cout<<"**************************"<<endl;
    cout<<"*      欢迎进入科长菜单     *"<<endl;
    cout<<"*      1.查询全体员工信息   *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.结束项目          *"<<endl;
    cout<<"*      6.启动立项          *"<<endl;
    cout<<"*      7.增加科室          *"<<endl;
    cout<<"*      8.解散科室          *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}