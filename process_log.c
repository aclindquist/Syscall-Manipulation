#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "process_log.h"


int get_proc_log_level()
{
	return syscall(335);
}

int set_proc_log_level(int new_level)
{
	return syscall(336, new_level);
}

int proc_log_message(int level, char *message)
{
//define process log 337
	return syscall(337, message, level);
}

int* retrieve_set_level_params(int new_level)
{
	int *pointer = malloc(3 * sizeof(int));
	pointer[0] = 336;                           //syscall num
	pointer[1] = 1;                             //num of parameters
	pointer[2] = new_level;
	return pointer;
}

int* retrieve_get_level_params()
{
	int *pointer = malloc(2 * sizeof(int));
	pointer[0] = 335;
	pointer[1] = 0;
	return pointer;
}

int interpret_set_level_result(int ret_value)
{
	return ret_value;
}

int interpret_get_level_result(int ret_value)
{
	return ret_value;
}

int interpret_log_message_result(int ret_value)
{
	return ret_value;
}
