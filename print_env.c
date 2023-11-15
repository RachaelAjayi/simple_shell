#include "shell.h"
/**
 *print_env - prints the environment.
 *@command: an array of strings rep the command arg.
 *@list:pointer to the list_t structure.
 */
void print_env(char **command, list_t *list)
{
	env_t *ptr = list->print_env;

	(void)command;
	while (ptr)
	{
		if (ptr->name)
		{
			print(ptr->name, 1, 0);
			print("=", 1, 0);
			print(ptr->value, 1, 1);
		}
		ptr = ptr->next;
	}
	list->exit_code = 0;
}
