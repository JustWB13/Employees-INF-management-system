//
// Created by 吴波 on 2020/6/24.
//

#include "employee.h"

employee::employee(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE)
{
    id=ID;
    name=NAME;
    sex=SEX;
    phone_number=PHONE_NUMBER;
    hash=HASH;
    wage=WAGE;
    cur_wage=CUR_WAGE;
}
temp_employee::temp_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    p_id=P_ID;
    s_id=S_ID;
    task_status=true;
}
normal_employee::normal_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK): temp_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE)
{
    p_name=P_NAME;
    cur_stock=CUR_STOCK;
}
section_chief::section_chief(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK):normal_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE,CUR_STOCK)
{

}
general_manager::general_manager(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    cur_stock=CUR_STOCK;
}
int employee::get_hash(){return hash;}//返回密码的哈希值
string employee::get_name(){return name;}
string temp_employee::get_p_id(){return p_id;}
string employee::get_id() {return id;}
void temp_employee::INF_print()
{
    cout<<"----------------"<<endl;
    cout<<"员工ID:"<<id<<endl
        <<"员工姓名:"<<name<<endl
        <<"员工性别:"<<sex<<endl
        <<"员工电话号码:"<<phone_number<<endl
        <<"项目名称:"<<p_name<<endl
        <<"项目ID:"<<p_id<<endl;
    cout<<"工作完成情况:";
    if(task_status)cout<<"已完成";
    else cout<<"未完成";
    cout<<endl;
    cout<<"科室ID:"<<s_id<<endl
        <<"员工底薪:"<<wage<<endl
        <<"员工现有工资:"<<cur_wage<<endl;
    cout<<"----------------"<<endl;
}
void normal_employee::INF_print()
{
    cout<<"----------------"<<endl;
    cout<<"员工ID:"<<id<<endl
        <<"员工姓名:"<<name<<endl
        <<"员工性别:"<<sex<<endl
        <<"员工电话号码:"<<phone_number<<endl
        <<"项目名称:"<<p_name<<endl
        <<"项目ID:"<<p_id<<endl;
    cout<<"工作完成情况:";
    if(task_status)cout<<"已完成";
    else cout<<"未完成";
    cout<<endl;
    cout<<"科室ID:"<<s_id<<endl
        <<"现有持股:"<<cur_stock<<endl
        <<"员工底薪:"<<wage<<endl
        <<"员工现有工资:"<<cur_wage<<endl;
    cout<<"----------------"<<endl;
}
void section_chief::INF_print()
{
    cout<<"----------------"<<endl;
    cout<<"员工ID:"<<id<<endl
        <<"员工姓名:"<<name<<endl
        <<"员工性别:"<<sex<<endl
        <<"员工电话号码:"<<phone_number<<endl
        <<"项目名称:"<<p_name<<endl
        <<"项目ID:"<<p_id<<endl;
    cout<<"工作完成情况:";
    if(task_status)cout<<"已完成";
    else cout<<"未完成";
    cout<<endl;
    cout<<"科室ID:"<<s_id<<endl
        <<"现有持股:"<<cur_stock<<endl
        <<"员工底薪:"<<wage<<endl
        <<"员工现有工资:"<<cur_wage<<endl;
    cout<<"----------------"<<endl;
}
void general_manager::INF_print()
{
    cout<<"----------------"<<endl;
    cout<<"员工ID:"<<id<<endl
        <<"员工姓名:"<<name<<endl
        <<"员工性别:"<<sex<<endl
        <<"员工电话号码:"<<phone_number<<endl
        <<"现有持股:"<<cur_stock<<endl
        <<"员工底薪:"<<wage<<endl
        <<"员工现有工资:"<<cur_wage<<endl;
    cout<<"----------------"<<endl;
}