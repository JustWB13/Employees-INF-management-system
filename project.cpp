//
// Created by 吴波 on 2020/6/24.
//

#include "project.h"

projects::project::project(string P_ID,string P_NAME,vector<string> PIC_NAME,vector<string> PIC_ID,vector<string> S_ID,string INTRO,int E_AMOUNT,int E_ACCOMPLISHED,bool STATUS,double PRICE)
{
    p_id=P_ID;
    p_name=P_NAME;
    pic_name=PIC_NAME;
    pic_id=PIC_ID;
    s_id=S_ID;
    intro=INTRO;
    E_amount=E_AMOUNT;
    E_accomplished=E_ACCOMPLISHED;
    status=false;
    price=PRICE;
}
void projects::delete_update(string p_id)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        project tmp=(*i);
        if(tmp.p_id==p_id)
        {
            tmp.E_accomplished--;
            tmp.E_amount--;
            break;
        }
    }
}
void projects::show_ROP(string P_ID)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        if((*i).p_id==P_ID)
        {
            project tmp=*i;
            if(tmp.E_amount==tmp.E_accomplished)
            {
                cout<<"项目已结束"<<endl;
                break;
            }
            double ac=tmp.E_accomplished,am=tmp.E_amount;
            if(ac<0)ac=0;
            double rate=(ac)/(am)*100;
            cout.precision(2);
            cout<<"任务已完成"<<rate<<"%"<<endl;
        }
    }
}
void projects::SC_update(string P_ID, int amount)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        if((*i).p_id==P_ID)
        {
            (*i).E_accomplished+=amount;
            return;
        }
    }
}
bool projects::project_over(string P_ID)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        if((*i).p_id==P_ID)
        {
            if((*i).E_accomplished==(*i).E_amount)
            {
                (*i).status=true;
                cout<<"工程已确认结束!"<<endl;
                return true;
            }
            else
            {
                cout<<"工程尚未完成!"<<endl;
                return false;
            }
        }
    }
}
double projects::get_price(string p_id)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        if((*i).p_id==p_id)
            return (*i).price;
    }
}
bool projects::id_check(string p_id)
{
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
        if((*i).p_id==p_id)return false;
    return true;
}
void projects::project_add(string id, string name, vector<string> PIC_NAME, vector<string> PIC_ID, vector<string> S_ID, string INTRO, int E_AMOUNT, int E_ACCOMPLISHED, bool STATUS, double PRICE){a.push_back(project(id,name,PIC_NAME,PIC_ID,S_ID,INTRO,E_AMOUNT,E_ACCOMPLISHED,false,PRICE));}
