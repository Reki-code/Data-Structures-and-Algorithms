#ifndef _COMMON_H_
#define _COMMON_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum CHOICE{logout, quit};
enum GROUP{admin = 1, guest};

struct User;
typedef struct User *Userinfo;

bool login(Userinfo *u); 

#endif
