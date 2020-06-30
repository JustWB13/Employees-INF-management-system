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
    void delete_update(string p_id);
};