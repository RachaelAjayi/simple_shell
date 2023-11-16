#include "shell.h"

/**
 *lstadd_back_env - Will add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_env(env_t **lst, env_t *new)
{
	env_t	*chip;

	if (!lst || !new)
		return;
	chip = *lst;
	if (*lst)
	{
		while (chip->next)
			chip = chip->next;
		chip->next = new;
	}
	else
		*lst = new;
}

/**
 *lstadd_back_command - Will add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_command(command_t **lst, command_t *new)
{
	command_t	*chip;

	if (!lst || !new)
		return;
	chip = *lst;
	if (*lst)
	{
		while (chip->next)
			chip = chip->next;
		chip->next = new;
	}
	else
		*lst = new;
}

/**
 *lstadd_back_alias - will add a new node to the end of list.
 *@lst: arg 1.
 *@new: arg 2.
 */
void	lstadd_back_alias(alias_t **lst, alias_t *new)
{
	alias_t	*chip;

	if (!lst || !new)
		return;
	chip = *lst;
	if (*lst)
	{
		while (chip->next)
			chip = chip->next;
		chip->next = new;
	}
	else
		*lst = new;
}
