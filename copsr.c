#include "shell.h"

/**
 *str_copy1 - Copying substring from str.
 *@str: arg 1.
 *@index: arg 2.
 *@a: arg 3.
 *Return: String.
 */
char	*str_copy1(char	*str, int *index, char a)
{
	int		k;
	int		start;
	char	*ptr;
	int		z;

	k = *index;
	start = *index;
	while (str[k] && str[k] != a)
	{
		k++;
		*index = *index + 1;
	}
	ptr = malloc(k + 1);
	z = 0;
	while (z < k)
		ptr[z++] = str[start++];
	ptr[z] = '\0';
	return (ptr);
}

/**
 *init_env - Initialize the environmental variable.
 *@envp: arg 1.
 *@global: arg 2.
 */
void	init_env(char **envp, global_t *global)
{
	int		k;
	env_t	*env;
	env_t	*head;
	int		index;

	k = 0;
	head = NULL;
	while (envp && envp[k])
	{
		index = 0;
		env = malloc(sizeof(env_t));
		env->name = str_copy1(envp[k], &index, '=');
		index++;
		env->value = str_copy1(envp[k], &index, 0);
		env->next = NULL;
		lstadd_back_env(&head, env);
		k++;
	}
	global->env = head;
	global->commands = NULL;
	global->exit_code = 0;
	global->pid = getpid();
	global->alias = NULL;
	global->envp = envp;
	global->n = 1;
}

/**
 *env_search - Search for an environmental variables.
 * @str: arg 1.
 * @global: arg 2.
 *Return: Value of the env if found, or NULL
 */
char	*env_search(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

/**
 *envsearch - Search for an environmental variables.
 * @str: arg 1.
 * @global: arg 2.
 *Return: Value of the env if found, or NULL
 */
env_t	*envsearch(char	*str, global_t *global)
{
	env_t	*ptr;

	ptr = global->env;
	while (ptr)
	{
		if (ptr->name && !_strncmp(str, ptr->name, _strlen(str) + 1))
			return (ptr);
		ptr = ptr->next;
	}
	return (0);
}
