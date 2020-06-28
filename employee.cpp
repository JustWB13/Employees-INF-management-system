//
// Created by 吴波 on 2020/6/24.
//

#include "employee.h"
<<<<<<< HEAD

employee::employee(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE)
{
    id=ID;
    name=NAME;
    sex=SEX;
    phone_number=PHONE_NUMBER;
    hash=HASH;
    wage=WAGE;
    cur_wage=CUR_WAGE;
}
temp_employee::temp_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    p_name=P_NAME;
    p_id=P_ID;
    s_id=S_ID;
    task_status=true;
}
normal_employee::normal_employee(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK): temp_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE)
{
    cur_stock=CUR_STOCK;
}
section_chief::section_chief(string ID,string NAME,string SEX,string PHONE_NUMBER,string P_NAME,string P_ID,string S_ID,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK):normal_employee(ID,NAME,SEX,PHONE_NUMBER,P_NAME,P_ID,S_ID,HASH,WAGE,CUR_WAGE,CUR_STOCK)
{

}
general_manager::general_manager(string ID,string NAME,string SEX,string PHONE_NUMBER,int HASH,int WAGE,int CUR_WAGE,int CUR_STOCK):employee(ID,NAME,SEX,PHONE_NUMBER,HASH,WAGE,CUR_WAGE)
{
    cur_stock=CUR_STOCK;
}
=======
>>>>>>> origin/master
