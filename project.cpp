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
projects::projects()
{
    ifstream pd;
    pd.open("projects_database.txt",ios::in);
    int all;
    pd>>all;
    string P_ID;
    string P_NAME;
    vector<string> PIC_NAME;
    vector<string> PIC_ID;
    vector<string> S_ID;
    string INTRO;
    int E_AMOUNT,E_ACCOMPLISHED;
    bool STATUS;
    double PRICE;
    for(int i=1;i<=all;i++)
    {
        pd>>P_ID>>P_NAME>>PIC_NAME>>PIC_ID>>S_ID>>INTRO>>E_AMOUNT>>E_ACCOMPLISHED>>STATUS>>PRICE;
        a.push_back(project(P_ID,P_NAME,PIC_NAME,PIC_ID,S_ID,INTRO,E_AMOUNT,E_ACCOMPLISHED,STATUS,PRICE));
    }
    pd.close();
    cout<<"项目文件读取完毕！"<<endl;
}
projects::~projects()
{
    ofstream pd;
    pd.open("book_database.txt",ios::out);
    int all=a.size();
    pd<<all<<endl;
    project tmp;
    for(vector<project>::iterator i=a.begin();i!=a.end();i++)
    {
        tmp=*i;
        pd<<tmp.P_ID<<endl
          <<tmp.P_NAME<<endl
          <<tmp.PIC_NAME<<endl
          <<tmp.PIC_ID<<endl
          <<tmp.S_ID<<endl
          <<tmp.INTRO<<endl
          <<tmp.E_AMOUNT<<endl
          <<tmp.E_ACCOMPLISHED<<endl
          <<tmp.STATUS<<endl
          <<tmp.PRICE<<endl;
    }
    pd.close();
    cout<<"项目文件保存完成！"<<endl;
}
