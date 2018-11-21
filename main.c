#include "common.h"

void carry(Userinfo u, int choice);
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
                
                break;
                case postInfomation:
                
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
