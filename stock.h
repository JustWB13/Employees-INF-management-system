//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<set>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

/*
 文件结构
 stock_price
 st_amount
 交易总数n
 status
 amount
 price
 user_ID
 st_id
 ...*n
 */

class stocks
{
protected:
    static double STOCK_PRICE;
    static int ST_AMOUNT;
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