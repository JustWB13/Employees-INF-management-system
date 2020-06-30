//
// Created by 吴波 on 2020/6/22.
//
#include "function.h"//test
int main()
{
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
                    if (n == 1)employee_add();
                    else if (n == 2)employee_delete();
                    else if (n == 3)INF_change();
                    else if (n == 4)INF_search();
                    else if (n == 5)wage_statistic();
                    else if (n == 6)stocks::show();
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
                    if (id == (*i).id)
                    {

                        flag = true;
                        general_manager tmp = *i;
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
                                if (n == 1)INF_search();
                                else if (n == 2)INF_change();
                                else if (n == 3){stocks::show();Stock_get();}
                                else if (n == 4)Stock_sale();
                                else if (n == 5){TS_update();INF_update();}
                                else if (n == 6)Project_start();
                                else if (n == 7)Office_add();
                                else if (n == 8)Office_dismiss();
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
                    if (id == (*i).id)
                    {
                        flag = true;
                        section_chief tmp = *i;
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
                                if (n == 1)INF_search();
                                else if (n == 2)INF_change();
                                else if (n == 3){stocks::show();Stock_get();}
                                else if (n == 4)Stock_sale();
                                else if (n == 5)TS_update();
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
                    if (id == (*i).id)
                    {
                        flag = true;
                        normal_employee tmp = *i;
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
                                if (n == 1)INF_search();
                                else if (n == 2)INF_change();
                                else if (n == 3){stocks::show();Stock_get();}
                                else if (n == 4)Stock_sale();
                                else if (n == 5)TS_update();
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
                    if (id == (*i).id)
                    {
                        flag = true;
                        temp_employee tmp = *i;
                        hash = BKDRHash(enter_passwd());
                        if (hash == tmp.get_hash())
                        {
                            cout << "密码正确！欢迎临时雇员" << tmp.get_name() << "!" << endl;
                            cout << "按任意键继续" << endl;
                            getchar();
                            system("CLS");
                            temp_employee_page(id);
                            while(true)
                            {
                                cin >> n;
                                if (n == 1)INF_search();
                                else if (n == 2)INF_change();
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