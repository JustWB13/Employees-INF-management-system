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

class projects
{
protected:
    struct project
    {
        string p_id,p_name;
        vector<string> pic_name,pic_id,s_id;//person in charge
        string intro;
        int E_amount,E_accomplished;
        bool status;
        double price;
        project(string P_ID,string P_NAME,vector<string> PIC_NAME,vector<string> PIC_ID,vector<string> S_ID,string INTRO,int E_AMOUNT,int E_ACCOMPLISHED,bool STATUS,double PRICE);
    };
    vector<project> a;
public:
    projects();
    ~projects();
    void show_ROP(string P_ID);//rate of progress
    void delete_update(string p_id);//删除用户时更新项目状态
    void SC_update(string P_ID,int amount);//科长更新任务状态时调用
    bool project_over(string P_ID);//结束工程
    double get_price(string p_id);
    bool id_check(string p_id);//检查项目ID是否存在
    void project_add(string id,string name,vector<string> PIC_NAME,vector<string> PIC_ID,vector<string> S_ID,string INTRO,int E_AMOUNT,int E_ACCOMPLISHED,bool STATUS,double PRICE);
};