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
void admin_check();
void admin_page();
void login();
void passwd();
void temp_employee_page(string id);
void normal_employee_page(string id);
void section_chief_page(string id);
void general_manager_page(string id);
string enter_passwd();
void employee_add(set<string> id_check,vector<temp_employee> &a,vector<normal_employee> &b,vector<section_chief> &c,vector<general_manager> &d);//员工添加
void employee_delete(projects &P,vector<temp_employee> &a,vector<normal_employee> &b,vector<section_chief> &c,vector<general_manager> &d);//员工删除
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

void employee_delete(projects &P,vector<temp_employee> &a,vector<normal_employee> &b,vector<section_chief> &c,vector<general_manager> &d)//员工删除
{
    string id;
    cout<<"请输入要删除的用户ID:";
    cin>>id;
    for(vector<temp_employee>::iterator i=a.begin();i!=a.end();i++)
    {
        temp_employee tmp=(*i);
        if(tmp.get_id()==id)
        {

        }
    }
    for(vector<normal_employee>::iterator i=b.begin();i!=b.end();i++)
    {
        normal_employee tmp=(*i);
        if(tmp.get_id()==id)
        {

        }
    }
    for(vector<section_chief>::iterator i=c.begin();i!=c.end();i++)
    {
        section_chief tmp=(*i);
        if(tmp.get_id()==id)
        {

        }
    }
    for(vector<general_manager>::iterator i=d.begin();i!=d.end();i++)
    {
        general_manager tmp=(*i);
        if(tmp.get_id()==id)
        {

        }
    }
}

void employee_add(set<string> id_check,vector<temp_employee> &a,vector<normal_employee> &b,vector<section_chief> &c,vector<general_manager> &d)//员工添加
{
    int opt;
    cout<<"请选择注册用户类型:"<<endl
    <<"1.总经理"<<endl
    <<"2.科长"<<endl
    <<"3.普通雇员"<<endl
    <<"4.临时雇员"<<endl;
    cout<<"请输入:";
    cin>>opt;
    if(opt==1)
    {
        string id;
        cout<<"请输入用户ID(总经理ID需以1开头):";
        cin>>id;
        if(id[0]!='1' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        d.push_back(general_manager(id,name,sex,phone_number,-1,12000,0,0));
    }
    else if(opt==2)
    {
        string id;
        cout<<"请输入用户ID(科长ID需以2开头):";
        cin>>id;
        if(id[0]!='2' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        c.push_back(section_chief(id,name,sex,phone_number,"","","",-1,8000,0,0));
    }
    else if(opt==3)
    {
        string id;
        cout<<"请输入用户ID(普通雇员ID需以3开头):";
        cin>>id;
        if(id[0]!='3' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        b.push_back(normal_employee(id,name,sex,phone_number,"","","",-1,5000,0,0));
    }
    else if(opt==4)
    {
        string id;
        cout<<"请输入用户ID(临时雇员ID需以4开头):";
        cin>>id;
        if(id[0]!='4' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        a.push_back(temp_employee(id,name,sex,phone_number,"","","",-1,3000,0));
    }
    cout<<"用户创建成功!"<<endl;
    cout<<"输入任意数字返回:";
    cin>>opt;
    return;
}

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
    string id;
    int hash;
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*   欢迎进入管理员登陆菜单   *"<<endl;
    cout<<"**************************"<<endl;
    hash = BKDRHash(enter_passwd());
    if (hash == admin_passwd)//管理员密码
    {
        cout << "密码正确！欢迎管理员!" << endl;
        cout << "按任意键继续" << endl;
        getchar();
        system("CLS");
        admin_page();
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
    cout<<"*       0.返回主界面        *"<<endl;
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
        case 0:admin_page();break;
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
    cout<<"请输入您的员工id:";
    cin>>id;
    fir_id=id.at(0);
    switch(fir_id)
    {
        case 1:
            for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
            {
                if(id==(*i).id)
                {
                    general_manager tmp=*i;
                    hash = BKDRHash(enter_passwd());
                    if (hash == tmp.get_hash())
                    {
                        cout << "密码正确！欢迎总经理" << tmp.get_name() << "!" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        general_manager_page(id);
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
            cout<<"该员工不存在!返回主菜单！"<<endl;
            cout << "按任意键继续" << endl;
            getchar();
            system("CLS");
            main_page();
        case 2:
            for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
            {
                if(id==(*i).id)
                {
                    section_chief tmp=*i;
                    hash = BKDRHash(enter_passwd());
                    if (hash == tmp.get_hash())
                    {
                        cout << "密码正确！欢迎科长" << tmp.get_name() << "!" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        section_chief_page(id);
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
            cout<<"该员工不存在!返回主菜单！"<<endl;
            cout << "按任意键继续" << endl;
            getchar();
            system("CLS");
            main_page();
        case 3:
            for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
            {
                if(id==(*i).id)
                {
                    normal_employee tmp=*i;
                    hash = BKDRHash(enter_passwd());
                    if (hash == tmp.get_hash())
                    {
                        cout << "密码正确！欢迎普通雇员" << tmp.get_name() << "!" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        normal_employee_page(id);
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
            cout<<"该员工不存在!返回主菜单！"<<endl;
            cout << "按任意键继续" << endl;
            getchar();
            system("CLS");
            main_page();
        case 4:
            for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
            {
                if(id==(*i).id)
                {
                    temp_employee tmp=*i;
                    hash = BKDRHash(enter_passwd());
                    if (hash == tmp.get_hash())
                    {
                        cout << "密码正确！欢迎临时雇员" << tmp.get_name() << "!" << endl;
                        cout << "按任意键继续" << endl;
                        getchar();
                        system("CLS");
                        temp_employee_page(id);
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
            cout<<"该员工不存在!返回主菜单！"<<endl;
            cout << "按任意键继续" << endl;
            getchar();
            system("CLS");
            main_page();
        default:
            cout<<"该员工不存在!返回主菜单！"<<endl;
            cout << "按任意键继续" << endl;
            getchar();
            system("CLS");
            main_page();
    }
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
    cin>>n;
    switch(n)
    {
        case 1:INF_search();break;
        case 2:INF_change();break;
        case 3:main_page();break;
        default:
            cout<<"该选项不存在！请重新选择！"<<endl;
            getchar();getchar();
            temp_employee_page();
            break;
    }
}

void normal_employee_page()
{
    int n;
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
    cin>>n;
    switch(n)
    {
        case 1:INF_search();break;
        case 2:INF_change();break;
        case 3:Stock_show();Stock_get();break;
        case 4:Stock_sale();break;
        case 5:TS_update();break;
        case 0:main_page();break;
        default:
            cout<<"该选项不存在！请重新选择！"<<endl;
            getchar();getchar();
            normal_employee_page();
            break;
    }
}

void section_chief_page()
{
    int n;
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
    cin>>n;
    switch(n)
    {
        case 1:INF_search();break;
        case 2:INF_change();break;
        case 3:Stock_show();Stock_get();break;
        case 4:Stock_sale();break;
        case 5:TS_update();break;
        case 0:main_page();break;
        default:
        cout<<"该选项不存在！请重新选择！"<<endl;
        getchar();getchar();
        section_chief_page();
        break;
    }
}

void general_manager_page()
{
    int n;
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
    cin>>n;
    switch(n)
    {
        case 1:INF_search();break;
        case 2:INF_change();break;
        case 3:Stock_show();Stock_get();break;
        case 4:Stock_sale();break;
        case 5:TS_update();INF_update();break;
        case 6:Project_start();break;
        case 7:Office_add();break;
        case 8:Office_dismiss();break;
        case 0:main_page();break;
        default:
        cout<<"该选项不存在！请重新选择！"<<endl;
        getchar();getchar();
        section_chief_page();
        break;
    }
}