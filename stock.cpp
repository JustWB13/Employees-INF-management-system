//
// Created by 吴波 on 2020/6/24.
//

#include "stock.h"
stocks::stock::stock(bool STATUS,int AMOUNT,string USER_ID,double PRICE)
{
    status=STATUS;
    amount=AMOUNT;
    user_ID=USER_ID;
    price=PRICE;
}
void stocks::show(bool admin_tag)
{
    for(vector<stock>::iterator i=a.begin();i!=a.end();i++)
    {
        stock tmp=(*i);
        if(tmp.status)
            if(!admin_tag)continue;
        cout<<"状态:";
        if(admin_tag)
            if(tmp.status)cout<<"已出售";
            else cout<<"待售";
        cout<<endl;
        cout<<"出售者ID:"<<tmp.user_ID<<endl;
        cout<<"数量:"<<tmp.amount<<endl;
        cout.precision(2);
        if(!tmp.status)cout<<"价格:"<<stock_price<<endl;
        else cout<<"成交价格:"<<tmp.price<<endl;
    }
}