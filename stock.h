//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

class stocks
{
protected:
    static double stock_price;
    struct stock
    {
        bool status;
        int mount;
        string user_ID;
        stock();
    };
    vector<stock> a;
public:
    stocks();
    ~stocks();
};



