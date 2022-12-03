//
// Created by user3093 on 2022/12/3.
//
#include "library.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <sys/types.h>
#include <sys/stat.h>
//-------------------------------菜单栏--------------------------------
//主菜单
void menu_main()
{
    printf("\n\n");
    printf("\t\t\t *=======================================*\n");
    printf("\t\t\t|  * - * - * 欢迎来到图书管理系统 * - * - *|\n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [1]    用户登录                    |  |\n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [2]    用户注册                    |  |\n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [3]    管理员登录                    |  |\n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [4]    退出系统                   |  |\n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t|  * - * - * - * - * - * - * - * - * - * - * - *|\n");
    printf("\t\t\t *==========================================*\n");
}

//用户菜单栏
void menu_user()
{
    printf("\n\n");
    printf("\t\t\t *=======================================*\n");
    printf("\t\t\t|     * - * - * -会-员-界-面 * - -* - *| |  \n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [1]    查找图书信息                    |  |\n");
    printf("\t\t\t| *  [2]    借阅图书                         *|\n");
    printf("\t\t\t| |  [3]    归还图书                       |  |\n");
    printf("\t\t\t| *  [4]    修改账户信息                      *|\n");
    printf("\t\t\t| |  [5]    退出用户界面                      |  |\n");
    printf("\t\t\t| |                                         |  |\n");
    printf("\t\t\t|  * - * - * - * - * - * - * - * - * - * - * - *|\n");
    printf("\t\t\t *==============================================*\n");
}

//管理员菜单栏
void menu_manager()
{
    printf("\n\n");
    printf("\t\t\t *=======================================*\n");
    printf("\t\t\t|     * - * - * -管-理-员-界-面 * - -* - *| |  \n");
    printf("\t\t\t| *                                       *|\n");
    printf("\t\t\t| |  [1]    添加图书                      | |\n");
    printf("\t\t\t| *  [2]    删减图书                        *|\n");
    printf("\t\t\t| |  [3]    修改图书信息                      | |\n");
    printf("\t\t\t| *  [4]    查找图书信息                      *|\n");
    printf("\t\t\t| |  [5]    显示全部图书信息                   | |\n");
    printf("\t\t\t| |  [6]    显示全部会员信息                   | |\n");
    printf("\t\t\t| |  [7]    统计所有借阅信息                   | |\n");
    printf("\t\t\t| |  [8]    显示罚款信息详情                   | |\n");
    printf("\t\t\t| |  [9]    退出管理员界面                     | |\n");
    printf("\t\t\t| *                                          *|\n");
    printf("\t\t\t|  * - * - * - * - * - * - * - * - * - * - * - *|\n");
    printf("\t\t\t *=============================================*\n");
}

//--------------------------登录操作-----------------------------
//用户登录
int login(pUser* user)
{
    char account[ACCOUNT]="";
    char password[PASSWORD]="";
    FILE* fp;
    pUser users = NULL;
    //输入账号密码
    input(account,password);
    //打开文件并从文件读入所有用户信息
    errno_t message = fopen_s(&fp,"users")
}