#ifndef MY_HANDS_1_0
#define MY_HANDS_1_0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <string.h>
#include "libmy_shell.h"

#define MAXARGS 128
#define MAXLINE 64
#define CONSOLE_ERROR 1
#define FORK_ERROR -1
#define FORK_SCS 0

//Macros
#define ARRAY_LEN(ARRAY_NAME, TYPE)(sizeof(ARRAY_NAME)/sizeof(TYPE))
#define COMMAND_STRING_ char **
#define ERROR_MSSG_ char *err_msg

//System call wrapers
extern void Console_Child_Signal_Set(__sighandler_t handler);
extern void Console_Wait_Pid(const pid_t pid, ERROR_MSSG_);
extern void Console_Write(const void* buf, ERROR_MSSG_);
extern void Console_Read(void* buf, ERROR_MSSG_);
extern void Task_Fork(COMMAND_STRING_ command, ERROR_MSSG_);

//Signal hanlders
extern void Console_Child_Hanlder(int n);

//Failure exit handling
extern void Console_AtExit(void);

#endif