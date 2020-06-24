//
// Created by 吴波 on 2020/6/24.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM

class projects
{
protected:
    struct project
    {
        string P_ID,P_name;
        vector<string> PIC_name,PIC_ID,S_ID;//person in charge
        string intro;
        int E_mount,E_accomplished;
    };
    vector<project> a;
public:
    projects();
    ~projects();
};



