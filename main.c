#include "common.h"

void carry(Userinfo u, int choice);
bool print_infomation(void);
bool post_infomation(void);
bool get_infomation(char *string);
bool get_infomation(char *string)
{
        getchar();
        fgets(string, 255, stdin);
        return true;
}

bool post_infomation(void)
{
        FILE *fp = fopen("./infomation.txt", "a");
        if (fp == NULL) {
                printf("cannot open file\n");
        }
        char buffer[255];
        get_infomation(buffer);
        fprintf(fp, "%s", buffer);

        fclose(fp);
        return true;
}

bool print_infomation(void)
{
        FILE *fp = fopen("./infomation.txt", "r");
        if (fp == NULL) {
                printf("cannot open file\n");
                return false;
        }
        while (!feof(fp)) {
                char buffer[255];
                if (fgets(buffer, 255, fp) != NULL) {
                        printf("%s\n", buffer);
                }
        }
        fclose(fp);
        return true;
}
void carry(__attribute__((unused))Userinfo u, int choice)
{
        switch(choice) {
                case searchLocation:
                
                break;
                case shortPathPrint:
                
                break;
                case allPathPrint:
                
                break;
                case bestPath:
                
                break;
                case infomationPrint:
                print_infomation(); 
                break;
                case postInfomation:
                post_infomation();
                break;
                case manageAttraction:
                
                break;
        }
        return ;
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
                        carry(user, choice);

                } while (choice != logout && choice != quit);
        } while (choice == logout);

        // save info
        return 0;
}
