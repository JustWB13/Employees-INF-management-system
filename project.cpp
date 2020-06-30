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
projects::projects()
{
    ifstream load;
    load.open("projects.txt",ios::in);
    int n;
    string p_id,p_name;
    int m;
    vector<string> pic_name,pic_id,s_id:
    string intro;
    int E_amount,E_accomplished;
    bool status;
    double price;
    load>>n;
    for(int i=1;i<=n;i++)
    {
        load>>p_id>>p_name>>m;
        for(int i=1;i<=m;i++)
        {
            string pn,pi,si;
            load>>pn>>pi>>si;
            pic_name.push_back(pn);
            pic_id.push_back(pi);
            s_id.push_back(si);
        }
        load>>intro>>E_amount>>E_accomplished>>status>>price;
        a.push_back(project(p_id,p_name,pic_name,pic_id,s_id,intro,E_amount,E_accomplished,status,price));
    }
}
projects::~projects()
{
    ofstream save;
    save.open("project.txt",ios::in);
    int n=a.size(),m;
    save<<n<<endl;
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        project tmp=(*i);
        save<<tmp.p_id<<endl<<tmp.p_name<<endl;
        save<<(m=tmp.pic_id.size())<<endl;
        for(int j=0;j<m;j++)
        {
            save<<tmp.pic_name[j]<<endl
                <<tmp.pic_id[j]<<endl
                <<tmp.s_id[j]<<endl;
        }
        save<<tmp.intro<<endl
            <<tmp.E_amount<<endl
            <<tmp.E_accomplished<<endl
            <<tmp.status<<endl
            <<tmp.price<<endl;
    }
}