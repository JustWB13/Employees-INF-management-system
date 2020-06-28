//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM_EMPLOYEE_H

class employee
{
protected:
<<<<<<< HEAD
    string id,name,sex,phone_number;
    int hash,wage,cur_wage;
public:
    employee(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE);
=======
    string ID,name,sex,phone_number;
    int hash,wage,cur_wage;
public:
    employee();
    ~employee();
>>>>>>> origin/master
};

class temp_employee: public employee
{
protected:
<<<<<<< HEAD
    string p_name,p_id,s_id;
    bool task_status;
public:
    temp_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE);
=======
    string P_name,P_ID,S_ID;
    bool task_status;
public:
>>>>>>> origin/master
};

class normal_employee: public temp_employee
{
protected:
    int cur_stock;
public:
<<<<<<< HEAD
    normal_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
=======
>>>>>>> origin/master
};

class section_chief: public normal_employee
{
protected:
public:
<<<<<<< HEAD
    section_chief(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
=======
>>>>>>> origin/master
};

class general_manager: public employee
{
protected:
    int cur_stock;
public:
<<<<<<< HEAD
    general_manager(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK);
=======
>>>>>>> origin/master
};
