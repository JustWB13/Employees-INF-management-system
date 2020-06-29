//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

class stocks
{
protected:
    static double stock_price;
    struct stock
    {
        bool status;
        int amount;
        double price;
        string user_ID;
        stock(bool STATUS,int AMOUNT,string USER_ID,double PRICE);
    };
    vector<stock> a;
public:
    stocks();
    ~stocks();
    void show(bool admin_tag);
};



