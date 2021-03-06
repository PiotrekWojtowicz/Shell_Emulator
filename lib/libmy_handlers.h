#ifndef MY_HANDS_1_0
#define MY_HANDS_1_0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <wait.h>
#include <string.h>
#ifndef LIBM_SHELL
#define LIBM_SHELL
#include "libmy_shell.h"
#endif

#define MAXARGS 128
#define MAXLINE 64
#define CONSOLE_ERROR 1
#define FORK_ERROR -1
#define FORK_SCS 0

//Macros
#define ARRAY_LEN(ARRAY_NAME, TYPE)(sizeof(ARRAY_NAME)/sizeof(TYPE))

#ifndef COMMAND_STRING_
#define COMMAND_STRING_ char **
#endif

#ifndef ERROR_MSSG_
#define ERROR_MSSG_ char *err_msg
#endif

//System call wrapers

//Sets the new signal hanlder
extern void Console_Signal_Set(void(*my_new_hanlder)(int, siginfo_t *, void*));
//Waits for the child with given pid
extern void Console_Wait_Pid(const pid_t pid, ERROR_MSSG_);
//Writes to the standard output
extern void Console_Write(const void* buf, ERROR_MSSG_);
//Reads from the standard input
extern void Console_Read(void* buf, ERROR_MSSG_);
//Froks exectuing given command
extern pid_t Task_Fork(COMMAND_STRING_ command, ERROR_MSSG_);

//Signal hanlders
extern void Console_Handler(int signo, siginfo_t *info, void *context);

//Exit handling
extern void Console_AtExit(void);

#endif