//
// Created by 吴波 on 2020/6/24.
//

#include "project.h"

projects::project::project(string P_ID,string P_NAME,vector<string> PIC_NAME,vector<string> PIC_ID,vector<string> S_ID,string INTRO,int E_AMOUNT,int E_ACCOMPLISHED)
{
    p_id=P_ID;
    p_name=P_NAME;
    pic_name=PIC_NAME;
    pic_id=PIC_ID;
    s_id=S_ID;
    intro=INTRO;
    E_amount=E_AMOUNT;
    E_accomplished=E_ACCOMPLISHED;
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
            double rate=((double)tmp.E_accomplished)/((double)tmp.E_amount)*100;
            cout.precision(2);
            cout<<"任务已完成"<<rate<<"%"<<endl;
        }
    }
}