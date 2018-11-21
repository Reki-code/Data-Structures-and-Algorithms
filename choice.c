#include "common.h" 

static bool check_choice(Userinfo u, int ch);
static void admin_menu(void);
static void guest_menu(void);

void display_menu(Userinfo u)
{
        if (u->group == admin){
                admin_menu();
        } else {
                guest_menu();
        }
        return ;
}

static void admin_menu(void)
{
        printf("1.发布公告\n");
        printf("2.景点管理\n");
        printf("3.退出登录\n");
        printf("4.结束程序\n");
        return ;
}

static void guest_menu(void)
{
        printf("1.景点查询\n");
        printf("2.两点路径查询\n");
        printf("3.两点所有路径查询\n");
        printf("4.多景点访问路线查询\n");
        printf("5.公告栏\n");
        printf("6.退出登录\n");
        printf("7.结束程序\n");
        return ;
}

enum CHOICE get_choice(Userinfo u)
{
        int ch;
        int ret = logout;
        do {
                printf("get choice\n");
                scanf("%d", &ch);
        } while (check_choice(u, ch) == false);
        if (u->group == admin) {
                switch(ch) {
                        case 1:
                        ret = postInfomation;        
                        break;
                        case 2:
                        ret = manageAttraction; 
                        break;
                        case 3:
                        ret = logout;
                        break;
                        case 4:
                        ret = quit;
                        break;
                }
        } else {
                switch(ch) {
                        case 1:
                        ret = searchLocation;
                        break;
                        case 2:
                        ret = shortPathPrint;
                        break;
                        case 3:
                        ret = allPathPrint;
                        break;
                        case 4:
                        ret = bestPath;
                        break;
                        case 5:
                        ret = infomationPrint;
                        break;
                        case 6:
                        ret = logout;
                        break;
                        case 7:
                        ret = quit;
                        break;
                }
        }
        return ret;
}

static bool check_choice(Userinfo u, int ch)
{
        bool flag = true;
        if (u->group == admin) {
                flag = (1 <= ch && ch <= 4);
        } else {
                flag = (1 <= ch && ch <= 7);
        }

        return flag;
}
