//
// Created by user3093 on 2022/12/4.
//
#include <stdio.h>
#include "library.h"
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
    //记录当前登录用户信息
    pUser user;
    //记录用户密码输入次数
    int number = 1;
    start:
    while (True)
    {
        //打印主菜单
        menu_main();
        char choice = _getch();
        //设置对应选择
        switch (choice) {
            case '1':
                if(login(&user))
                {
                    //如果登录成功，打印用户菜单
                    printf("\n登录成功\n");
                    Sleep(1000);
                    //先读文件中所有的图书信息
                    pBook  book_list = NULL;
                    findAll_book(&book_list);
                    //用户操作
                    while (True)
                    {
                        menu_user();
                        char choice = _getch();
                        switch (choice) {
                            case '1':
                                if(!keywords_find(&book_list))
                                {
                                    printf("馆内貌似没有相关书籍呢,请换个关键字试试\n");
                                }
                                Sleep(2000);
                                break;
                            case '2':
                                if(borrow_book(user,&book_list))
                                {
                                    printf("借书成功\n");
                                }
                                else
                                {
                                    printf("你要借的书籍图书馆中暂时还没有存量,请重新搜索书籍\n");
                                }
                                Sleep(1000);
                                break;
                            case '3':
                                if(return_book(user,&book_list))
                                {
                                    printf("还书成功\n");
                                }
                                else
                                {
                                    printf("很抱歉,图书馆后台暂无您对此本书的记录\n");
                                }
                                Sleep(1000);
                                break;
                            case '4':
                                if(update_user(user))
                                {
                                    printf("修改成功\n");
                                }
                                else
                                {
                                    printf("修改失败\n");
                                }
                                Sleep(1000);
                                break;
                            case '5':
                                printf("谢谢使用!\n");
                                free(user);
                                Sleep(1000);
                                goto start;
                                break;
                            default:
                                printf("你输入的指令有误，请重新输入");
                                break;
                        }
                    }

                }
                else /*登录失败*/
                {
                    printf("\n你输入的账号或密码有误,请重新输入\n");
                    Sleep(1000);
                    number = freeze_account(number);
                }
                break;

            case '2':
                if(register_user())
                {
                    printf("注册成功!\n");
                }
                Sleep(1000);
                break;
            case '3':
                if(login(&user) &&user->identity==MANAGER)
                {
                    //先读文件中所有的图书信息
                    pBook  book_list = NULL;
                    findAll_book(&book_list);
                    while (True)
                    {
                        //打印管理员菜单
                        menu_manager();
                        //打印管理员操作
                        char choice = _getch();
                        switch (choice) {
                            case '1':
                                if(add_book(&book_list))
                                {
                                    printf("添加成功");
                                }
                                else
                                {
                                    printf("添加失败\n");
                                }
                                Sleep(1000);
                                break;

                            case '2':
                                if(delete_book((&book_list)))
                                {
                                    printf("删除成功\n");
                                }
                                else
                                {
                                    printf("删除失败,请检查你要删除的书名和作者是否输入正确\n");
                                }
                                Sleep(1000);
                                break;
                            case '3':
                                if(update_book(&book_list))
                                {
                                    printf("修改成功\n");
                                    Sleep(1000);
                                }
                                else
                                {
                                    printf("你要修改的书籍并不存在,请检查书籍ID\n");
                                    Sleep(1000);
                                }
                                break;
                            case '4':
                                if(!keywords_find(&book_list))
                                {
                                    printf("馆内貌似没有相关书籍呢,请换个关键字试试\n");
                                }
                                Sleep(2000);
                                break;
                            case '5':
                                if(book_list)
                                {
                                    println(book_list);
                                }
                                else
                                {
                                    printf("图书馆中还没有书籍!\n");
                                }
                                Sleep(1000);
                                break;
                            case '6':
                                printlnAll_users();
                                Sleep(1000);
                                break;
                            case '7':
                                count_books(book_list);
                                Sleep(1000);
                                break;
                            case '8':
                                printlnAll_fines();
                                Sleep(1000);
                                break;
                            case '9':
                                free(user);
                                printf("退出成功\n");
                                Sleep(1000);
                                goto start;
                                break;
                            default:
                                printf("你输入的指令有误，请重新输入");
                                break;
                        }
                    }
                }
                else
                {
                    printf("\n你的管理员账号或用户密码错误,请重新输入\n");
                    number = freeze_account(number);
                }
                break;
            case '4':
                printf("谢谢使用");
                Sleep(1000);
                exit(1);
            default:
                printf("\n你输入的选择有误，请重试新输入\n");
                Sleep(1000);
        }

    }
    return 0;
}



