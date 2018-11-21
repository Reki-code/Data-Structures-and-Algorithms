#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum CHOICE{logout, quit, searchLocation, shortPathPrint, 
    allPathPrint, bestPath, infomationPrint, 
    postInfomation, manageAttraction};
enum GROUP{admin = 1, guest};

struct User {
    char *username;
    int group;
};
typedef struct User *Userinfo;

bool login(Userinfo *u); 

enum CHOICE get_choice(Userinfo u);
void display_menu(Userinfo u);

#endif
