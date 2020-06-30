//
// Created by 吴波 on 2020/6/24.
//

#include "employee.h"

employee::employee(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,double WAGE,double CUR_WAGE)
{
    id=ID;
    name=NAME;
    sex=SEX;
    phone_number=PHONE_NUMBER;
    hash=HASH;
    wage=WAGE;
    cur_wage=CUR_WAGE;
}
temp_employee::temp_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,double WAGE,double CUR_WAGE):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    p_id=P_ID;
    s_id=S_ID;
    task_status=true;
}
normal_employee::normal_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,double WAGE,double CUR_WAGE,int CUR_STOCK): temp_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE)
{
    p_name=P_NAME;
    cur_stock=CUR_STOCK;
}
section_chief::section_chief(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,double WAGE,double CUR_WAGE,int CUR_STOCK):normal_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE,CUR_STOCK)
{

}
general_manager::general_manager(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,double WAGE,double CUR_WAGE,int CUR_STOCK):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    cur_stock=CUR_STOCK;
}
int employee::get_hash(){return hash;}//返回密码的哈希值
bool temp_employee::get_task_status(){return task_status;}
string employee::get_name(){return name;}//返回员工姓名
string temp_employee::get_p_id(){return p_id;}//返回项目ID
string temp_employee::get_s_id(){return s_id;}//返回科室ID
string employee::get_id() {return id;}//返回员工ID
double employee::get_cur_wage() {return cur_wage;}//获取员工工资
int normal_employee::get_stock(){return cur_stock;}//获取持股数
int general_manager::get_stock(){return cur_stock;}
void normal_employee::stock_sale(int amount){cur_wage-=amount;}//股票卖出
void general_manager::stock_sale(int amount){cur_wage-=amount;}
void temp_employee::task_confirm(){task_status=true;}//确认任务完成
void temp_employee::project_update(double p_price){p_id="";p_name="";cur_wage+=(wage+p_price*0.125)}//工程结束后临时工信息更新
void normal_employee::project_update(double p_price,double s_price){p_id="";p_name="";cur_wage+=(wage+p_price*0.125+s_price*cur_stock*0.1);}//工程结束后普通雇员信息更新
void section_chief::project_update(double p_price,double s_price){p_id="";p_name="";cur_wage+=(wage+p_price*0.25+s_price*cur_stock*0.1);}//科长
void general_manager::project_update(double p_price, double s_price){cur_wage+=(wage+p_price*0.5+s_price*cur_stock*0.1);}//总经理
void temp_employee::section_update(string S_ID){s_id=S_ID;}//科室信息更新
void temp_employee::section_dismiss(){s_id="";}//科室解散员工信息更新
void employee::hash_update(int HASH){hash=HASH;}
string employee::get_sex() {return sex;}
string employee::get_phone_number() {return phone_number;}
double employee::get_wage() {return wage;}
string temp_employee::get_p_name() {return p_name;}
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
void employee::inf_change(string NAME, string SEX, string PHONE_NUMBER)
{
    if(NAME[0]!='1')name=NAME;
    if(SEX[0]!='1')sex=SEX;
    if(PHONE_NUMBER[0]!='1')phone_number=PHONE_NUMBER;
}
void normal_employee::stock_buy(double price,double stock_price)
{
    int amount=(price/stock_price);
    cur_stock+=amount;
    cur_wage-=price;
}
void general_manager::stock_buy(double price, double stock_price)
{
    int amount=(price/stock_price);
    cur_stock+=amount;
    cur_wage-=price;
}
void temp_employee::project_start(string P_ID, string P_NAME)
{
    p_id=P_ID;
    p_name=P_NAME;
    task_status=false;
}