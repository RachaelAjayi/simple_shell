#include "shell.h"
/**
 *m_error - Frees memory.
 *@arr: arg 1.
 *Return:NULL
 */
static char	**m_error(char	**arr)
{
	unsigned int	k;

	k = 0;
	while (arr[k])
		free(arr[k++]);
	free(arr);
	return (NULL);
}

/**
 *ft_count_words - counts the number of words used in code.
 *@str: arg 1.
 *@charset: arg 2.
 *Return: the num of words.
 */
static int	ft_count_words(char const *str, char charset)
{
	int	k;
	int	nbr_w;

	nbr_w = 0;
	k = 0;
	while (str[k])
	{
		while (str[k] && (str[k] == charset))
			k++;
		if (str[k])
			nbr_w++;
		while (str[k] && !(str[k] == charset))
			k++;
	}
	return (nbr_w);
}

/**
 *ft_word_len - calculate the lenth of function.
 *@str: arg 1.
 *@charset: arg 2.
 *Return: The length.
 */
static int	ft_word_len(char const *str, char charset)
{
	int	k;

	k = 0;
	while (str[k] && !(str[k] == charset))
		k++;
	return (k);
}

/**
 *ft_word_grep - extracts a word from file.
 *@str: arg 1.
 *@charset: arg 2.
 *Return: ne word.
 */
static char	*ft_word_grep(char const *str, char charset)
{
	int		len_w;
	int		k;
	char	*word;

	k = 0;
	len_w = ft_word_len(str, charset);
	word = malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (k < len_w)
	{
		word[k] = str[k];
		k++;
	}
	word[k] = 0;
	return (word);
}

/**
 *split - string array of substrings.
 *@s: arg 1.
 *@c: arg 2.
 *Return: An array of pointers.
 */
char	**split(char const *s, char c)
{
	int			k;
	char		**splited;

	if (!s)
		return (NULL);
	k = 0;
	splited = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splited)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			splited[k] = ft_word_grep(s, c);
			if (!splited[k])
				return (m_error(splited));
			k++;
		}
		while (*s && !(*s == c))
			s++;
	}
	splited[k] = 0;
	return (splited);
}
