#include "common.h"

struct User {
    char *username;
    int group;
};
static bool admin_login(Userinfo *u)
{
        printf("admin_login\n");
        char username[20], password[20];
        printf("输入用户名\n");
        scanf("%s", username);
        printf("输入密码\n");
        scanf("%s", password);
        (*u)->username = malloc(sizeof(char) * strlen(username));
        return true;
}

bool login(Userinfo *u) 
{
        *u = malloc(sizeof(struct User));
        printf("login\n");
        int choice = guest;
        printf("1.admin\n2.guest\n");
        scanf("%d", &choice);
        switch (choice) {
                case admin:
                        while (admin_login(u) == false) {

                        }
                        return true;
                        break;
                case guest:
                        (*u)->group = guest;
                        (*u)->username = "anonymous";
                        return true;
                        break;
        }
        return false;
}
