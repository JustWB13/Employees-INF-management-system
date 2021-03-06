//
// Created by 吴波 on 2020/6/27.
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

#include"employee.cpp"
#include"stock.cpp"
#include"project.cpp"

string get_passwd();
inline int BKDRHash(string a);
void main_page();
bool admin_check();
void admin_page();
void login();
void passwd();
void temp_employee_page();
void normal_employee_page();
void section_chief_page();
void general_manager_page();
string enter_passwd();
void employee_write(vector<general_manager> GM,vector<section_chief> SC,vector<normal_employee> NE,vector<temp_employee> TE);//用户信息写入文件
void employee_load(vector<general_manager> &GM,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE);//员工信息读入（从文件中）
void employee_add(set<string> id_check,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM);//员工添加
void employee_delete(stocks &S,projects &P,set<string> id_check,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM);//员工删除
void INF_change(string u_id,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM);//员工信息修改
void INF_search(string u_id,vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC,vector<general_manager> GM);//员工信息查询
void wage_statistic(vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC,vector<general_manager> GM);//员工工资统计
void Stock_get(string u_id,stocks &S,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM);//股票购买
void Stock_sale(string u_id,stocks &S,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM);//股票出售
void TS_update(string s_id,projects &P,vector<normal_employee> NE,vector<temp_employee> TE);//工作状态更新
void project_end(string p_id,string gm_id,projects &P,stocks &S,vector<general_manager> &GM,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE);//结束任务并更新员工状态
void Project_start(projects &P,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE);//启动立项
void Office_add(vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC);//科室增加(需要一名科长的ID与至少一名普通员工的ID)
void Office_dismiss(string s_id,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC);//科室解散(需要科室ID)

void employee_write(vector<general_manager> GM,vector<section_chief> SC,vector<normal_employee> NE,vector<temp_employee> TE)//用户信息写入文件
{
    ofstream write;
    write.open("TE.txt",ios::out);
    int n=TE.size();
    for(int i=0;i<n;i++)
    {
        write<<TE[i].get_id()<<endl
             <<TE[i].get_name()<<endl
             <<TE[i].get_sex()<<endl
             <<TE[i].get_phone_number()<<endl
             <<TE[i].get_hash()<<endl
             <<TE[i].get_wage()<<endl
             <<TE[i].get_cur_wage()<<endl
             <<TE[i].get_p_name()<<endl
             <<TE[i].get_p_id()<<endl
             <<TE[i].get_s_id()<<endl
             <<TE[i].get_task_status()<<endl;
    }
    write.close();
    write.open("NE.txt",ios::out);
    n=NE.size();
    for(int i=0;i<n;i++)
    {
        write<<NE[i].get_id()<<endl
             <<NE[i].get_name()<<endl
             <<NE[i].get_sex()<<endl
             <<NE[i].get_phone_number()<<endl
             <<NE[i].get_hash()<<endl
             <<NE[i].get_wage()<<endl
             <<NE[i].get_cur_wage()<<endl
             <<NE[i].get_p_name()<<endl
             <<NE[i].get_p_id()<<endl
             <<NE[i].get_s_id()<<endl
             <<NE[i].get_task_status()<<endl
             <<NE[i].get_stock()<<endl;
    }
    write.close();
    write.open("SC.txt",ios::out);
    n=SC.size();
    for(int i=0;i<n;i++)
    {
        write<<SC[i].get_id()<<endl
             <<SC[i].get_name()<<endl
             <<SC[i].get_sex()<<endl
             <<SC[i].get_phone_number()<<endl
             <<SC[i].get_hash()<<endl
             <<SC[i].get_wage()<<endl
             <<SC[i].get_cur_wage()<<endl
             <<SC[i].get_p_name()<<endl
             <<SC[i].get_p_id()<<endl
             <<SC[i].get_s_id()<<endl
             <<SC[i].get_task_status()<<endl
             <<SC[i].get_stock()<<endl;
    }
    write.close();
    write.open("GM.txt",ios::out);
    n=GM.size();
    for(int i=0;i<n;i++)
    {
        write<<GM[i].get_id()<<endl
             <<GM[i].get_name()<<endl
             <<GM[i].get_sex()<<endl
             <<GM[i].get_phone_number()<<endl
             <<GM[i].get_hash()<<endl
             <<GM[i].get_wage()<<endl
             <<GM[i].get_stock()<<endl;
    }
}

void employee_load(vector<general_manager> &GM,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE)//员工信息读入（从文件中）
{
    ifstream load;
    load.open("TE.txt",ios::in);
    int n;
    string id,name,sex,phone_number;
    int hash,cur_stock;
    double wage,cur_wage;
    string p_name,p_id,s_id;
    bool task_status;
    load>>n;
    for(int i=1;i<=n;i++)
    {
        load>>id>>name>>sex>>phone_number>>hash>>wage>>cur_wage>>p_name>>p_id>>s_id>>task_status;
        TE.push_back(temp_employee(id,name,sex,phone_number,p_name,p_id,s_id,hash,wage,cur_wage));
    }
    load.close();
    load.open("NE.txt",ios::in);
    load>>n;
    for(int i=1;i<=n;i++)
    {
        load>>id>>name>>sex>>phone_number>>hash>>wage>>cur_wage>>p_name>>p_id>>s_id>>task_status>>cur_stock;
        NE.push_back(normal_employee(id,name,sex,phone_number,p_name,p_id,s_id,hash,wage,cur_wage,cur_stock));
    }
    load.close();
    load.open("SC.txt",ios::in);
    load>>n;
    for(int i=1;i<=n;i++)
    {
        load>>id>>name>>sex>>phone_number>>hash>>wage>>cur_wage>>p_name>>p_id>>s_id>>task_status>>cur_stock;
        SC.push_back(section_chief(id,name,sex,phone_number,p_name,p_id,s_id,hash,wage,cur_wage,cur_stock));
    }
    load.close();
    load.open("GM.txt",ios::in);
    load>>n;
    for(int i=1;i<=n;i++)
    {
        load>>id>>name>>sex>>phone_number>>hash>>wage>>cur_wage>>cur_stock;
        GM.push_back(general_manager(id,name,sex,phone_number,hash,wage,cur_wage,cur_stock));
    }
}

void Project_start(projects &P,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE)//启动立项
{
    string id;
    cout<<"请输入项目ID:";
    cin>>id;
    if(!P.id_check(id))
    {
        cout<<"项目ID已存在,项目创建失败!"<<endl;
        cout<<"请输入任意数字继续:";
        cin>>id;
        return;
    }
    string name;
    cout<<"请输入项目名称:";
    cin>>name;
    string intro;
    cout<<"请输入项目简介:";
    cin>>intro;
    double price;
    cout<<"请输入项目资金:";
    cin>>price;
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if((*i).get_p_id()=="")(*i).INF_print();
    vector<string> pic_id,pic_name,s_id;
    set<string> pic_id_check,s_id_check;
    cout<<"以上是目前无正在进行项目的科长列表,请输入参与此项目的科长ID(输入0结束):"<<endl;
    while(true)
    {
        string tmp;
        cin>>tmp;
        if(tmp[0]=='0')break;
        pic_id.push_back(tmp);
        pic_id_check.insert(tmp);
    }
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if(pic_id_check.count((*i).get_p_id()))
        {
            (*i).project_start(id,name);
            s_id.push_back((*i).get_s_id());
            pic_name.push_back((*i).get_name());
            s_id_check.insert((*i).get_s_id());
        }
    int nec=0,tec=0;
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        if(s_id_check.count((*i).get_s_id()))(*i).project_start(id,name),nec++;
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        if(s_id_check.count((*i).get_s_id()))(*i).project_start(id,name),tec++;
    P.project_add(id,name,pic_name,pic_id,s_id,intro,pic_id.size()+nec+tec,0,false,price);
    cout<<"立项成功!"<<endl;
}

void Office_dismiss(string s_id,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC)//科室解散(需要科室ID)
{
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if((*i).get_s_id()==s_id)
        {
            if((*i).get_task_status())(*i).section_dismiss();
            else
            {
                cout<<"科室现有工程尚未完成,无法解散!"<<endl;
                cout<<"输入任意数字继续:";
                getchar();
                break;
            }
        }
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        if((*i).get_s_id()==s_id)
            (*i).section_dismiss();
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        if((*i).get_s_id()==s_id)
            (*i).section_dismiss();
    cout<<"解散成功!"<<endl;
    return;
}

void Office_add(vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC)//科室增加(需要一名科长的ID与至少一名普通员工的ID)
{
    string s_id;
    cout<<"请输入新科室的科室ID:";
    cin>>s_id;
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if((*i).get_s_id()==s_id)
        {
            cout<<"该科室ID已存在,科室创建失败!"<<endl;
            cout<<"输入任意数字继续:";
            cin>>s_id;
            return;
        }
    string SC_id;
    set<string> E_id;
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if((*i).get_s_id()=="")
            (*i).INF_print();
    cout<<"以上是目前尚未组建科室的科长,请输入其中一名科长的ID:";
    cin>>SC_id;
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        if((*i).get_s_id()=="")
            (*i).INF_print();
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        if((*i).get_s_id()=="")
            (*i).INF_print();
    cout<<"以上是尚未加入科室的普通雇员和临时雇员,请输入需要添加进新科室的员工的ID(输入0结束)::"<<endl;
    while(true)
    {
        string tempid;
        cin>>tempid;
        if(tempid[0]='0')break;
        E_id.insert(tempid);
    }
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        if((*i).get_p_id()==SC_id)
        {
            (*i).section_update(s_id);
            break;
        }
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        if(E_id.count((*i).get_p_id()))
            (*i).section_update(s_id);
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        if(E_id.count((*i).get_p_id()))
            (*i).section_update(s_id);
    cout<<"科室创建成功!"<<endl;
    return;
}

void project_end(string p_id,string gm_id,projects &P,stocks &S,vector<general_manager> &GM,vector<section_chief> &SC,vector<normal_employee> &NE,vector<temp_employee> &TE)//结束任务并更新员工状态
{
    double p_price=P.get_price(p_id);
    double s_price=S.get_sp();
    if(P.project_over(p_id))
    {
        for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
        {
            if((*i).get_id()==gm_id)
                (*i).project_update(p_price,s_price);
        }
        for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        {
            if((*i).get_p_id()==p_id)
                (*i).project_update(p_price,s_price);
        }
        for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        {
            if((*i).get_p_id()==p_id)
                (*i).project_update(p_price,s_price);
        }
        for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        {
            if((*i).get_p_id()==p_id)
                (*i).project_update(p_price);
        }
    }
    else return;
}

void TS_update(string s_id,projects &P,vector<normal_employee> NE,vector<temp_employee> TE)//工作状态更新
{
    int amount=0;
    string p_id;
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
    {
        if((*i).get_s_id()==s_id)
        {
            p_id=(*i).get_p_id();
            if((*i).get_task_status())amount++;
            else
            {
                cout<<"员工任务未全部完成,任务状态更新失败!"<<endl;
                cout<<"请输入任意数字继续:";
                cin>>amount;
                return;
            }
        }
    }
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
    {
        if((*i).get_s_id()==s_id)
        {
            p_id=(*i).get_p_id();
            if((*i).get_task_status())amount++;
            else
            {
                cout<<"员工任务未全部完成,任务状态更新失败!"<<endl;
                cout<<"请输入任意数字继续:";
                cin>>amount;
                return;
            }
        }
    }
    P.SC_update(p_id,amount+1);
}

void Stock_sale(string u_id,stocks &S,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM)//股票出售函数
{
    int amount;
    cout<<"请输入卖出数量:";
    cin>>amount;
    if(u_id[0]=='1')
    {
        for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                if(amount<=(*i).get_stock())
                {
                    (*i).stock_sale(amount);
                    S.stock_sale(u_id,amount);
                    break;
                }
                else
                {
                    cout<<"持股不足,上架失败!"<<endl;
                    cout<<"请输入任意数字继续:";
                    cin>>amount;
                    break;
                }
            }
        }
    }
    else if(u_id[0]=='2')
    {
        for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                if(amount<=(*i).get_stock())
                {
                    (*i).stock_sale(amount);
                    S.stock_sale(u_id,amount);
                    break;
                }
                else
                {
                    cout<<"持股不足,上架失败!"<<endl;
                    cout<<"请输入任意数字继续:";
                    cin>>amount;
                    break;
                }
            }
        }
    }
    else if(u_id[0]=='3')
    {
        for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                if(amount<=(*i).get_stock())
                {
                    (*i).stock_sale(amount);
                    S.stock_sale(u_id,amount);
                    break;
                }
                else
                {
                    cout<<"持股不足,上架失败!"<<endl;
                    cout<<"请输入任意数字继续:";
                    cin>>amount;
                    break;
                }
            }
        }
    }
}

void Stock_get(string u_id,stocks &S,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM)//股票购买
{
    string st_id;
    cout<<"请输入交易ID:";
    cin>>st_id;
    if(u_id[0]=='1')
    {
        for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                double price=S.stock_buy(st_id,(*i).get_cur_wage());
                if(price==-1)return;
                (*i).stock_buy(price,S.get_sp());
                break;
            }
        }
    }
    else if(u_id[0]=='2')
    {
        for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                double price=S.stock_buy(st_id,(*i).get_cur_wage());
                if(price==-1)return;
                (*i).stock_buy(price,S.get_sp());
                break;
            }
        }
    }
    else if(u_id[0]=='3')
    {
        for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        {
            if((*i).get_id()==u_id)
            {
                double price=S.stock_buy(st_id,(*i).get_cur_wage());
                if(price==-1)return;
                (*i).stock_buy(price,S.get_sp());
                break;
            }
        }
    }
}

void wage_statistic(vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC,vector<general_manager> GM)//员工工资统计
{
    double te=0,ne=0,sc=0,gm=0;
    for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)gm+=(*i).get_cur_wage();
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)gm+=(*i).get_cur_wage();
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)gm+=(*i).get_cur_wage();
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)gm+=(*i).get_cur_wage();
    cout<<"总经理现有平均工资:"<<(gm/GM.size())<<endl;
    cout<<"科长现有平均工资:"<<(sc/SC.size())<<endl;
    cout<<"普通雇员现有工资:"<<(ne/NE.size())<<endl;
    cout<<"临时雇员现有工资:"<<(te/TE.size())<<endl;
    cout<<"全体员工现有平均工资:"<<((te+ne+sc+gm)/(GM.size()+SC.size()+NE.size()+TE.size()))<<endl;
}

void INF_change(string u_id,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM)//员工信息修改
{
    string name,sex,phone_number;
    cout<<"请输入更改后姓名(若无需修改则输入1):";
    cin>>name;
    cout<<"请输入更改后性别(若无需修改则输入1):";
    cin>>sex;
    cout<<"请输入更改后电话号码(若无需修改则输入1):";
    cin>>phone_number;
    if(u_id[0]=='1')
    {
        for (vector<general_manager>::iterator i = GM.begin(); i != GM.end(); i++)
        {
            if ((*i).get_id() == u_id)
            {
                (*i).inf_change(name, sex, phone_number);
                break;
            }
        }
    }
    else if(u_id[0]=='2')
    {
        for (vector<section_chief>::iterator i = SC.begin(); i != SC.end(); i++)
        {
            if ((*i).get_id() == u_id)
            {
                (*i).inf_change(name, sex, phone_number);
                break;
            }
        }
    }
    else if(u_id[0]=='3')
    {
        for (vector<normal_employee>::iterator i = NE.begin(); i != NE.end(); i++)
        {
            if ((*i).get_id() == u_id)
            {
                (*i).inf_change(name, sex, phone_number);
                break;
            }
        }
    }
    else if(u_id[0]=='4')
    {
        for (vector<temp_employee>::iterator i = TE.begin(); i != TE.end(); i++)
        {
            if ((*i).get_id() == u_id)
            {
                (*i).inf_change(name, sex, phone_number);
                break;
            }
        }
    }
}

void INF_search(string u_id,vector<temp_employee> TE,vector<normal_employee> NE,vector<section_chief> SC,vector<general_manager> GM)//员工信息查询
{
    if(u_id[0]=='1')//总经理
    {
        for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
        {
            if(u_id==(*i).get_id())
            {
                (*i).INF_print();
                break;
            }
        }
    }
    else if(u_id[0]=='2')//科长
    {
        for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
        {
            if(u_id==(*i).get_id())
            {
                (*i).INF_print();
                break;
            }
        }
    }
    else if(u_id[0]=='3')//普通雇员
    {
        for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
        {
            if(u_id==(*i).get_id())
            {
                (*i).INF_print();
                break;
            }
        }
    }
    else if(u_id[0]=='4')//临时工
    {
        for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
        {
            if(u_id==(*i).get_id())
            {
                (*i).INF_print();
                break;
            }
        }
    }
}

void employee_delete(stocks &S,projects &P,set<string> id_check,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM)//员工删除
{
    string id;
    cout<<"请输入要删除的用户ID:";
    cin>>id;
    if(!id_check.count(id))
    {
        cout<<"id不存在!"<<endl;
        cout<<"输入任意数字继续:";
        cin>>id;
        return;
    }
    for(vector<temp_employee>::iterator i=TE.begin();i!=TE.end();i++)
    {
        temp_employee tmp=(*i);
        if(tmp.get_id()==id)
        {
            P.delete_update(tmp.get_p_id());
            S.delete_update(tmp.get_id());
            TE.erase(i);
            break;
        }
    }
    for(vector<normal_employee>::iterator i=NE.begin();i!=NE.end();i++)
    {
        normal_employee tmp=(*i);
        if(tmp.get_id()==id)
        {
            P.delete_update(tmp.get_p_id());
            S.delete_update(tmp.get_id());
            NE.erase(i);
            break;
        }
    }
    for(vector<section_chief>::iterator i=SC.begin();i!=SC.end();i++)
    {
        section_chief tmp=(*i);
        if(tmp.get_id()==id)
        {
            P.delete_update(tmp.get_p_id());
            S.delete_update(tmp.get_id());
            SC.erase(i);
            break;
        }
    }
    for(vector<general_manager>::iterator i=GM.begin();i!=GM.end();i++)
    {
        general_manager tmp=(*i);
        if(tmp.get_id()==id)
        {
            S.delete_update(tmp.get_id());
            GM.erase(i);
            break;
        }
    }
    id_check.erase(id);
}

void employee_add(set<string> id_check,vector<temp_employee> &TE,vector<normal_employee> &NE,vector<section_chief> &SC,vector<general_manager> &GM)//员工添加
{
    int opt;
    cout<<"请选择注册用户类型:"<<endl
    <<"1.总经理"<<endl
    <<"2.科长"<<endl
    <<"3.普通雇员"<<endl
    <<"4.临时雇员"<<endl;
    cout<<"请输入:";
    cin>>opt;
    if(opt==1)
    {
        string id;
        cout<<"请输入用户ID(总经理ID需以1开头):";
        cin>>id;
        if(id[0]!='1' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        GM.push_back(general_manager(id,name,sex,phone_number,-1,12000,0,0));
    }
    else if(opt==2)
    {
        string id;
        cout<<"请输入用户ID(科长ID需以2开头):";
        cin>>id;
        if(id[0]!='2' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        SC.push_back(section_chief(id,name,sex,phone_number,"","","",-1,8000,0,0));
    }
    else if(opt==3)
    {
        string id;
        cout<<"请输入用户ID(普通雇员ID需以3开头):";
        cin>>id;
        if(id[0]!='3' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        NE.push_back(normal_employee(id,name,sex,phone_number,"","","",-1,5000,0,0));
    }
    else if(opt==4)
    {
        string id;
        cout<<"请输入用户ID(临时雇员ID需以4开头):";
        cin>>id;
        if(id[0]!='4' or id_check.count(id))
        {
            cout << "用户ID不合法或ID已存在,用户创建失败!" << endl;
            cout<<"输入任意数字继续:";
            cin>>opt;
            return;
        }
        string name,sex,phone_number;
        cout<<"请输入用户姓名:";
        cin>>name;
        cout<<"请输入用户性别:";
        cin>>sex;
        cout<<"请输入用户手机号:";
        cin>>phone_number;
        TE.push_back(temp_employee(id,name,sex,phone_number,"","","",-1,3000,0));
    }
    cout<<"用户创建成功!"<<endl;
    cout<<"输入任意数字返回:";
    cin>>opt;
    return;
}

inline int BKDRHash(string a)
{
    long long hash=0;
    int ch=0;
    string::iterator i;
    i=a.begin();
    while(ch=(int)(*i++))
        hash=((hash*31)%999911659+ch)%999911659;
    return hash;
}

string get_passwd()//输入密码在终端不显示字符
{
    string tmp;
    system("stty -echo");
    cin>>tmp;
    system("stty echo");
    return tmp;
}

void main_page()
{
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"* 欢迎来到公司员工信息管理系统 *"<<endl;
    cout<<"*       1.管理员入口       *"<<endl;
    cout<<"*       2.员工入口         *"<<endl;
    cout<<"*       0.退出            *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

bool admin_check()
{
    string id;
    int hash;
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*   欢迎进入管理员登陆菜单   *"<<endl;
    cout<<"**************************"<<endl;
    hash = BKDRHash(enter_passwd());
    if (hash == 46792755)//管理员密码:12345
    {
        return true;
    }
    else
    {
        return false;
    }
}

void admin_page()
{
    cout<<"**************************"<<endl;
    cout<<"*     欢迎进入管理员菜单     *"<<endl;
    cout<<"*       1.添加员工         *"<<endl;
    cout<<"*       2.删除员工         *"<<endl;
    cout<<"*       3.修改员工信息      *"<<endl;
    cout<<"*       4.查询员工信息      *"<<endl;
    cout<<"*       5.员工工资统计      *"<<endl;
    cout<<"*       6.股票交易情况      *"<<endl;
    cout<<"*       0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void login()
{
    system("CLS");
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入员工登陆菜单    *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请输入您的员工id:";
}

string enter_passwd()
{
    cout<<"请输入密码： "<<endl;
    string password;
    char ch;
    while ((ch=getchar())!=13)
    {
        password+=ch;//string对象重载了+=
        cout<<"*";
    }
    return password;
}

void temp_employee_page()
{
    int n;
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入临时雇员菜单    *"<<endl;
    cout<<"*      1.查询个人信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void normal_employee_page()
{
    cout<<"**************************"<<endl;
    cout<<"*    欢迎进入正式雇员菜单    *"<<endl;
    cout<<"*      1.查询个人信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.确认工作完成       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void section_chief_page()
{
    cout<<"**************************"<<endl;
    cout<<"*      欢迎进入科长菜单     *"<<endl;
    cout<<"*      1.查询科室信息       *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.确认工作完成       *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}

void general_manager_page()
{
    cout<<"**************************"<<endl;
    cout<<"*      欢迎进入科长菜单     *"<<endl;
    cout<<"*      1.查询全体员工信息   *"<<endl;
    cout<<"*      2.更改个人信息       *"<<endl;
    cout<<"*      3.购买股票          *"<<endl;
    cout<<"*      4.卖出股票          *"<<endl;
    cout<<"*      5.结束项目          *"<<endl;
    cout<<"*      6.启动立项          *"<<endl;
    cout<<"*      7.增加科室          *"<<endl;
    cout<<"*      8.解散科室          *"<<endl;
    cout<<"*      0.返回主界面        *"<<endl;
    cout<<"**************************"<<endl;
    cout<<"请选择:";
}