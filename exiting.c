#include "shell.h"

/**
 * is_num - is a number.
 * @str: arg 1.
 * Return: 1 if is number.
 */
int	is_num(char *str)
{
	int k = 0;

	if (str[0] && (str[0] == '-' || str[0] == '+'))
		k++;
	if (!str[k])
		return (0);
	while (str[k] && str[k] == '0')
	{
	}
	while (str[k])
	{
		if (str[k] > '9' || str[k] < '0')
			return (0);
		k++;
	}
	return (1);
}

/**
 * my_exit - exiting the shell.
 * @cmd: arg 1;
 * @global: arg 2.
 */
void    my_exit(char **cmd, global_t *global)
{
	int p;

	if (!cmd[1])
	{
		p = global->exit_code;
		free_all(global);
		exit(p);
	}
	else
	{
		if (!is_num(cmd[1]) || _atoi(cmd[1]) < 0)
		{
			print(global->name, 2, 0);
			print(": ", 2, 0);
			putnbr_fd(global->n, 2);
			print(": exit: Illegal number: ", 2, 0);
			print(cmd[1], 2, 1);
			global->exit_code = 2;
		}
		else
		{
			p = _atoi(cmd[1]);
			free_all(global);
			exit((unsigned char)p);
		}
	}
}
