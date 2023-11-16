#include "shell.h"

/**
 *is_lo_op - con || or &&.
 *@str: arg 1.
 *Return: 0 or 1.
 */
int	is_lo_op(char *str)
{
	int	k = 0;

	while (str[k])
	{
		if (str[k] == '&' && str[k + 1] == '&')
			return (1);
		if (str[k] == '|' && str[k + 1] == '|')
			return (1);
		k++;
	}
	return (0);
}

/**
 *count_words - count number of words.
 *@str: arg 1.
 *@global: arg 2.
 *Return: number of words.
 */
int	count_words(char *str, global_t *global)
{
	int	count = 0, c = 1, k = 0;

	if (str[0] == '|' && str[1] && str[1] == '|')
	{
		print(global->name, 2, 0);
		print(": ", 2, 0);
		putnbr_fd(global->n, 2);
		print(": Syntax error: \"||\" unexpected", 2, 1);
		return (count);
	}
	if (str[0] == '&' && str[1] && str[1] == '&')
	{
		print(global->name, 2, 0);
		print(": ", 2, 0);
		putnbr_fd(global->n, 2);
		print(": Syntax error: \"&&\" unexpected", 2, 1);
		return (count);
	}
	while (str[k])
	{
		if (str[k] == ' ' || str[k] == '\t')
			c = 1;
		if ((str[k] == '|' && str[k + 1] && str[k + 1] == '|') ||
			(str[k] == '&' && str[k + 1] && str[k + 1] == '&'))
		{
			c = 1;
			count++;
			k += 2;
		}
		if (c && str[k] != ' ' && str[k] != '\t')
		{
			count++;
			c = 0;
		}
		k++;
	}
	return (count);
}

/**
 *copy_str - dup an new word in function.
 *@str: arg 1.
 *@index: arg 2.
 *Return: new word.
 */
char *copy_str(char *str, int *index)
{
	int		k = *index, start, len = 0;
	char	*ptr;

	while (str[k] && (str[k] == ' ' || str[k] == '\t'))
		k++;
	if (str[k] == '|' && str[k + 1] && str[k + 1] == '|')
	{
		*index = k + 2;
		return (_strdup("||"));
	}
	if (str[k] == '&' && str[k + 1] && str[k + 1] == '&')
	{
		*index = k + 2;
		return (_strdup("&&"));
	}
	start = k;
	while (str[k] != ' ' && str[k] != '\t')
	{
		if (str[k] == '|' && str[k + 1] && str[k + 1] == '|')
			break;
		if (str[k] == '&' && str[k + 1] && str[k + 1] == '&')
			break;
		k++;
		len++;
	}
	*index = k;
	ptr = malloc(len + 1);
	k = 0;
	while (k < len)
	{
		ptr[k] = str[start];
		k++;
		start++;
	}
	ptr[len] = '\0';
	return (ptr);
}

/**
 *advanced_split - split words in function.
 *@str: arg 1.
 *@global: arg 2.
 *Return: array of strings.
 */
char **advanced_split(char *str, global_t *global)
{
	int		count = count_words(str, global), k = 0, index = 0;
	char	**ptr;

	if (!count)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count + 1));
	while (k < count)
	{
		ptr[k] = copy_str(str, &index);
		k++;
	}
	ptr[count] = NULL;
	return (ptr);
}

/**
 *exec_logical_operators - exec_logical_operators in function.
 *@str: arg 1.
 *@global: arg 2.
 */
void exec_logical_operators(char **str, global_t *global)
{
	int		k = 0;
	char	n = 0, m, v = 1;
	command_t	*node = malloc(sizeof(command_t));

	while (str[k])
	{
		str = str + k;
		k = 0;
		while (1)
		{
			if (!str[k] || !_strncmp(str[k], "||", 3) || !_strncmp(str[k], "&&", 3))
			{
				if (str[k] && !_strncmp(str[k], "&&", 3))
					m = '&';
				else if (str[k] && !_strncmp(str[k], "||", 3))
					m = '|';
				if (!str[k])
					v = 0;
				free(str[k]);
				str[k] = NULL;
				node->path = get_path(str[0], global);
				node->args = str;
				if (!n || (n == '|' && global->exit_code) ||
					(n == '&' && !global->exit_code))
				{
					if (!exec_builtin(node->args, global))
						exec_binary(node, global);
				}
				free(node->path);
				n = m;
				if (v)
					str[k++] = _strdup("anything");
				break;
			}
			k++;
		}
	}
	free(node);
}
