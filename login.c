#include "common.h"

static bool admin_login(Userinfo *u)
{
        printf("admin_login\n");
        char username[20], password[20];
        printf("输入用户名\n");
        scanf("%s", username);
        printf("输入密码\n");
        scanf("%s", password);
        (*u)->username = malloc(sizeof(char) * strlen(username));
        (*u)->group = admin;
        if (strcmp(username, "admin") == 0 
                        && strcmp(password, "admin") == 0){
                printf("成功\n");
                return true;
        }
        free((*u)->username);
        printf("失败\n");
        return false;
}

bool login(Userinfo *u) 
{
        *u = malloc(sizeof(struct User));
        bool ret = false;
        while (ret == false) {
                printf("login\n");
                int choice = guest;
                printf("1.admin\n2.guest\n");
                scanf("%d", &choice);
                switch (choice) {
                        case admin:
                                ret = admin_login(u);
                                break;
                        case guest:
                                (*u)->group = guest;
                                (*u)->username = "anonymous";
                                ret = true;
                                break;
                }
        }
        
        return ret;
}
