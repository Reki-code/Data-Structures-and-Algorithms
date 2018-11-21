#include "common.h"

static void admin_menu(void)
{
        printf("admin menu\n");
        return ;
}

static void guest_menu(void)
{
        printf("guest menu\n");
        return ;
}

void display_menu(Userinfo u)
{
        if (u->group == admin){
                admin_menu();
        } else {
                guest_menu();
        }
        return ;
}
bool check_choice(Userinfo u, int ch)
{
        bool flag = true;
        if (u->group == admin) {
                if (1 < ch && ch < 10) {
                        flag = true;
                } else {
                        flag = false;
                }
        } else {
                if (1 < ch && ch < 5) {
                        flag = true;
                } else {
                        flag = false;
                }
        }

        return flag;
}

enum CHOICE get_choice(Userinfo u)
{
        int ch;
        do {
                printf("get choice\n");
                scanf("%d", &ch);
        } while (check_choice(u, ch) == false);
        return ch;
}
int main( )
{
        // load_info
        enum CHOICE choice = logout;
        do {
                Userinfo user;
                // login
                login(&user);// always true
                do {
                        // display_menu
                        display_menu(user);
                        // get_choice
                        choice = get_choice(user);
                        // play 

                } while (choice != logout && choice != quit);
        } while (choice == logout);

        // save info
        return 0;
}
