//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<set>
using namespace std;
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM_EMPLOYEE_H

class employee
{
protected:
    string id,name,sex,phone_number;
    int hash,wage,cur_wage;
public:
    employee(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE);
    int get_hash();
    string get_name();
    string get_id();
    virtual void INF_print()=0;
    void inf_change(string NAME,string SEX,string PHONE_NUMBER);
    double get_cur_wage();
    void hash_update(int HASH);
};

class temp_employee: public employee//临时工
{
protected:
    string p_name,p_id,s_id;
    bool task_status;
public:
    temp_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE);
    string get_p_id();
    string get_s_id();
    bool get_task_status();
    void task_confirm();
    virtual void project_update(double p_price);
    void section_update(string S_ID);
    void section_dismiss();
    void project_start(string P_ID,string P_NAME);
    virtual void INF_print();
};

/*
 临时工文件结构
 总临时工数n
 id
 name
 sex
 phone_number
 hash
 wage
 cur_wage
 p_name
 p_id
 s_id
 task_status
 ...*n
 */

class normal_employee: public temp_employee//普通员工
{
protected:
    int cur_stock;
public:
    normal_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
    virtual void INF_print();
    void stock_buy(double price,double stock_price);
    void stock_sale(int amount);
    int get_stock();
    virtual void project_update(double p_price,double s_price);
};

class section_chief: public normal_employee//科长
{
protected:
public:
    section_chief(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
    virtual void INF_print();
    virtual void project_update(double p_price,double s_price);
};

class general_manager: public employee//总经理
{
protected:
    int cur_stock;
public:
    general_manager(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
    virtual void INF_print();
    void stock_buy(double price,double stock_price);
    void stock_sale(int amount);
    int get_stock();
    void project_update(double p_price,double s_price);
};
