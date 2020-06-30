//
// Created by 吴波 on 2020/6/22.
//
#include "function.h"
int main()//test
{
    set<string> id_check;
    vector<temp_employee> TE;
    vector<normal_employee> NE;
    vector<section_chief> SC;
    vector<general_manager> GM;
    stocks S;
    projects P;
    string u_id,s_id,p_id,gm_id;
    bool admin_tag;
    int n;
    bool flag=false;
    main_page();
    while(true)
    {
        cin>>n;
        if(n==1)
        {
            if (admin_check())
            {
                cout << "密码正确！欢迎管理员!" << endl;
                cout << "按任意键继续" << endl;
                getchar();
                system("CLS");
                admin_page();
                while (true)
                {
                    cin >> n;
                    if (n == 1)employee_add(id_check,TE,NE,SC,GM);
                    else if (n == 2)employee_delete(S,P,id_check,TE,NE,SC,GM);
                    else if (n == 3)INF_change(u_id,TE,NE,SC,GM);
                    else if (n == 4)INF_search(u_id,TE,NE,SC,GM);
                    else if (n == 5)wage_statistic(TE,NE,SC,GM);
                    else if (n == 6)S.show(admin_tag);
                    else if (n == 0)
                    {
                        system("CLS");
                        main_page();
                        break;
                    }
                    else
                    {
                        cout << "该选项不存在！按任意键继续：" << endl;
                        getchar();
                        system("CLS");
                        admin_page();
                    }
                }
            }
            else
            {
                cout << "密码错误！返回主菜单！" << endl;
                cout << "按任意键继续" << endl;
                getchar();
                system("CLS");
                main_page();
            }
        }
        else if(n==2)
        {
            login();
            string id;
            char fir_id;
            int hash;
            cin >> id;
            fir_id = id.at(0);
            if (fir_id == 1)
            {
                for (vector<general_manager>::iterator i = GM.begin(); i != GM.end(); i++)
                {
                    if (id == (*i).get_id())
                    {

                        flag = true;
                        general_manager tmp = *i;
                        if(tmp.get_hash()==-1)
                        {
                            cout<<"初次登陆，请设置新密码！"<<endl;
                            string new_passwd1,new_passwd2;
                            new_passwd1=enter_passwd();
                            cout<<"请确认你的密码！"<<endl;
                            new_passwd2=enter_passwd();
                            if(new_passwd1==new_passwd2)
                            {
                                tmp.hash_update(BKDRHash(new_passwd1));
                                system("CLS");
                            }
                            else
                            {
                                cout<<"两次密码不一致！即将回到主菜单！"<<endl;
                                getchar();
                                system("CLS");
                                main_page();
                                break;
                            }
                        }
                        hash = BKDRHash(enter_passwd());
                        if (hash == tmp.get_hash())
                        {
                            cout << "密码正确！欢迎总经理" << tmp.get_name() << "!" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            general_manager_page();
                            while(true)
                            {
                                cin >> n;
                                if (n == 1)INF_search(u_id,TE,NE,SC,GM);
                                else if (n == 2)INF_change(u_id,TE,NE,SC,GM);
                                else if (n == 3){S.show(admin_tag);Stock_get(u_id,S,NE,SC,GM);}
                                else if (n == 4)Stock_sale(u_id,S,NE,SC,GM);
                                else if (n == 5){TS_update(s_id,P,NE,TE);project_end(p_id,gm_id,P,S,GM,SC,NE,TE);}
                                else if (n == 6)Project_start(P,SC,NE,TE);
                                else if (n == 7)Office_add(TE,NE,SC);
                                else if (n == 8)Office_dismiss(s_id,TE,NE,SC);
                                else if (n == 0){main_page();break;}
                                else
                                {
                                    cout << "该选项不存在！按任意键继续：" << endl;
                                    cout << "按任意键继续" << endl;
                                    getchar();
                                    system("CLS");
                                    general_manager_page();
                                }
                            }
                        }
                        else
                        {
                            cout << "密码错误！返回主菜单！" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            main_page();
                        }
                    }
                }
                if (flag == false)
                {
                    cout << "该员工不存在!返回主菜单！" << endl;
                    cout << "按任意键继续" << endl;
                    getchar();
                    system("CLS");
                    main_page();
                }
                flag = false;
            }
            else if (fir_id == 2)
            {
                for (vector<section_chief>::iterator i = SC.begin(); i != SC.end(); i++)
                {
                    if (id == (*i).get_id())
                    {
                        flag = true;
                        section_chief tmp = *i;
                        if(tmp.get_hash()==-1)
                        {
                            cout<<"初次登陆，请设置新密码！"<<endl;
                            string new_passwd1,new_passwd2;
                            new_passwd1=enter_passwd();
                            cout<<"请确认你的密码！"<<endl;
                            new_passwd2=enter_passwd();
                            if(new_passwd1==new_passwd2)
                            {
                                tmp.hash_update(BKDRHash(new_passwd1));
                                system("CLS");
                            }
                            else
                            {
                                cout<<"两次密码不一致！即将回到主菜单！"<<endl;
                                getchar();
                                system("CLS");
                                main_page();
                                break;
                            }
                        }
                        hash = BKDRHash(enter_passwd());
                        if (hash == tmp.get_hash())
                        {
                            cout << "密码正确！欢迎科长" << tmp.get_name() << "!" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            section_chief_page();
                            while(true)
                            {
                                cin >> n;
                                if (n == 1)INF_search(u_id,TE,NE,SC,GM);
                                else if (n == 2)INF_change(u_id,TE,NE,SC,GM);
                                else if (n == 3){S.show(admin_tag);Stock_get(u_id,S,NE,SC,GM);}
                                else if (n == 4)Stock_sale(u_id,S,NE,SC,GM);
                                else if (n == 5)TS_update(s_id,P,NE,TE);
                                else if (n == 0){main_page();break;}
                                else
                                {
                                    cout << "该选项不存在！按任意键继续：" << endl;
                                    cout << "按任意键继续" << endl;
                                    getchar();
                                    system("CLS");
                                    section_chief_page();
                                }
                            }
                        }
                        else
                        {
                            cout << "密码错误！返回主菜单！" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            main_page();
                        }
                    }
                }
                if (flag == false)
                {
                    cout << "该员工不存在!返回主菜单！" << endl;
                    cout << "按任意键继续" << endl;
                    getchar();
                    system("CLS");
                    main_page();
                }
                flag = false;
            }
            else if (fir_id == 3)
            {
                for (vector<normal_employee>::iterator i = NE.begin(); i != NE.end(); i++)
                {
                    if (id == (*i).get_id())
                    {
                        flag = true;
                        normal_employee tmp = *i;
                        if(tmp.get_hash()==-1)
                        {
                            cout<<"初次登陆，请设置新密码！"<<endl;
                            string new_passwd1,new_passwd2;
                            new_passwd1=enter_passwd();
                            cout<<"请确认你的密码！"<<endl;
                            new_passwd2=enter_passwd();
                            if(new_passwd1==new_passwd2)
                            {
                                tmp.hash_update(BKDRHash(new_passwd1));
                                system("CLS");
                            }
                            else
                            {
                                cout<<"两次密码不一致！即将回到主菜单！"<<endl;
                                getchar();
                                system("CLS");
                                main_page();
                                break;
                            }
                        }
                        hash = BKDRHash(enter_passwd());
                        if (hash == tmp.get_hash())
                        {
                            cout << "密码正确！欢迎正式雇员" << tmp.get_name() << "!" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            normal_employee_page();
                            while(true)
                            {
                                cin>>n;
                                if (n == 1)INF_search(u_id,TE,NE,SC,GM);
                                else if (n == 2)INF_change(u_id,TE,NE,SC,GM);
                                else if (n == 3){S.show(admin_tag);Stock_get(u_id,S,NE,SC,GM);}
                                else if (n == 4)Stock_sale(u_id,S,NE,SC,GM);
                                else if (n == 5)TS_update(s_id,P,NE,TE);
                                else if (n == 0){main_page();break;}
                                else
                                {
                                    cout << "该选项不存在！按任意键继续：" << endl;
                                    cout << "按任意键继续" << endl;
                                    getchar();
                                    system("CLS");
                                    normal_employee_page();
                                }
                            }
                        }
                        else
                        {
                            cout << "密码错误！返回主菜单！" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            main_page();
                        }
                    }
                }
                if (flag == false)
                {
                    cout << "该员工不存在!返回主菜单！" << endl;
                    cout << "按任意键继续" << endl;
                    getchar();
                    system("CLS");
                    main_page();
                }
                flag = false;
            }
            else if (fir_id == 4)
            {
                for (vector<temp_employee>::iterator i = TE.begin(); i != TE.end(); i++)
                {
                    if (id == (*i).get_id())
                    {
                        flag = true;
                        temp_employee tmp = *i;
                        if(tmp.get_hash()==-1)
                        {
                            cout<<"初次登陆，请设置新密码！"<<endl;
                            string new_passwd1,new_passwd2;
                            new_passwd1=enter_passwd();
                            cout<<"请确认你的密码！"<<endl;
                            new_passwd2=enter_passwd();
                            if(new_passwd1==new_passwd2)
                            {
                                tmp.hash_update(BKDRHash(new_passwd1));
                                system("CLS");
                            }
                            else
                            {
                                cout<<"两次密码不一致！即将回到主菜单！"<<endl;
                                getchar();
                                system("CLS");
                                main_page();
                                break;
                            }
                        }
                        hash = BKDRHash(enter_passwd());
                        if (hash == tmp.get_hash())
                        {
                            cout << "密码正确！欢迎临时雇员" << tmp.get_name() << "!" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            temp_employee_page();
                            while(true)
                            {
                                cin >> n;
                                if (n == 1)INF_search(u_id,TE,NE,SC,GM);
                                else if (n == 2)INF_change(u_id,TE,NE,SC,GM);
                                else if (n == 0){main_page();break;}
                                else
                                {
                                    cout << "该选项不存在！按任意键继续：" << endl;
                                    cout << "按任意键继续" << endl;
                                    getchar();
                                    system("CLS");
                                    temp_employee_page();
                                }
                            }
                        }
                        else
                        {
                            cout << "密码错误！返回主菜单！" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            main_page();
                        }
                    }
                }
                if (flag == false)
                {
                    cout << "该员工不存在!返回主菜单！" << endl;
                    cout << "按任意键继续" << endl;
                    getchar();
                    system("CLS");
                    main_page();
                }
                flag = false;
            }
            else
            {
                cout << "该员工不存在!返回主菜单！" << endl;
                cout << "按任意键继续" << endl;
                getchar();
                system("CLS");
                main_page();
            }
        }
        else if (n==0)return 0;
        else
        {
            cout << "该选项不存在！按任意键继续：" << endl;
            getchar();
            system("CLS");
            main_page();
        }
    }
}