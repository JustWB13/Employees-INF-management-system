//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

class stocks
{
protected:
    static double stock_price;
    static int st_amount;
    struct stock
    {
        bool status;
        int amount;
        double price;
        string user_ID,st_id;
        stock(bool STATUS,int AMOUNT,string USER_ID,string ST_ID,double PRICE);
    };
    vector<stock> a;
public:
    stocks();
    ~stocks();
    void show(bool admin_tag);
    void delete_update(string u_id);
    double stock_buy(string ST_ID,double money);
    int stock_sale(string u_id,int amount);
    double get_sp();
};