//
// Created by 吴波 on 2020/6/27.
//

#ifndef EMPLOYEES_INF_MANAGEMENT_SYSTEM
#define EMPLOYEES_INF_MANAGEMENT_SYSTEM
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#endif //EMPLOYEES_INF_MANAGEMENT_SYSTEM
string get_passwd();
inline int BKDRHash(string a);
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