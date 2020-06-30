//
// Created by 吴波 on 2020/6/24.
//

#include "stock.h"
stocks::stock::stock(bool STATUS,int AMOUNT,string USER_ID,string ST_ID,double PRICE)
{
    status=STATUS;
    amount=AMOUNT;
    user_ID=USER_ID;
    st_id=ST_ID;
    price=PRICE;
}
void stocks::show(bool admin_tag)
{
    for(vector<stock>::iterator i=a.begin();i!=a.end();i++)
    {
        stock tmp=(*i);
        if(tmp.status)
            if(!admin_tag)continue;
        cout<<"订单ID:"<<tmp.st_id<<endl;
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
void stocks::delete_update(string u_id)
{
    for(vector<stock>::iterator i=a.begin();i!=a.end();i++)
    {
        stock tmp=(*i);
        if(tmp.user_ID==u_id)
        {
            a.erase(i);
            break;
        }
    }
}
double stocks::stock_buy(string ST_ID, double money)
{
    for(vector<stock>::iterator i=a.begin();i!=a.end();i++)
    {
        stock tmp=(*i);
        if(tmp.status)continue;
        if(tmp.st_id==ST_ID)
        {
            if(money>=stock_price*tmp.amount)
            {
                (*i).price=tmp.amount*stock_price;
                (*i).status=true;
                return (*i).price;
            }
            else
            {
                cout<<"余额不足,购买失败!"<<endl;
                return -1;
            }
        }
    }
    cout<<"ID不存在,购买失败!"<<endl;
    return -1;
}
int stocks::stock_sale(string u_id, int amount)
{
    int tmp=++st_amount;
    string st_id;
    char orz[10];
    for(int i=0;tmp!=0;tmp>>=1,i++)
    {
        orz[i]=(tmp%10+'0');
    }
    a.push_back(stock(false,amount,u_id,st_id,0));
}
double stocks::get_sp() {return stock_price;}
stocks::stocks()
{
    ifstream sd;
    sd.open("stock_database.txt",ios::in);
    int all;
    sd>>all;
    static double stock_price;
    static int st_amount;
    bool status;
    int amount;
    double price;
    string user_ID,st_id;
    for(int i=1;i<=all;i++)
    {
        sd>>status>>amount>>user_ID>>st_id>>price;
        a.push_back(stock(status,amount,user_ID,st_id,price));
    }
    sd.close();
    cout<<"股票文件读取完毕！"<<endl;
}
stocks::~stocks()
{
    ofstream sd;
    sd.open("stock_database.txt",ios::out);
    int all=a.size();
    sd<<all<<endl;
    stock tmp;
    for(vector<stock>::iterator i=a.begin();i!=a.end();i++)
    {
        tmp=*i;
        sd<<tmp.status<<endl
          <<tmp.amount<<endl
          <<tmp.user_ID<<endl
          <<tmp.st_id<<endl
          <<tmp.price<<endl;
    }
    sd.close();
    cout<<"股票文件保存完成！"<<endl;
}