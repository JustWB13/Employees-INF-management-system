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
    string ID,name,sex,phone_number;
    int hash,wage,cur_wage;
public:
    employee();
    ~employee();
};

class temp_employee: public employee
{
protected:
    string P_name,P_ID,S_ID;
    bool task_status;
public:
};

class normal_employee: public temp_employee
{
protected:
    int cur_stock;
public:
};

class section_chief: public normal_employee
{
protected:
public:
};

class general_manager: public employee
{
protected:
    int cur_stock;
public:
};
