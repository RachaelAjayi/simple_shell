#include "shell.h"
/**
 * all - Read from fd.
 * @fd: arg 1.
 * @left: arg 2.
 * Return: The concatenated string string
 */
static char	*all(int fd, char *left)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readed && !my_strchr(left, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		left = my_strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

/**
 * get_line - Extract the one new line.
 * @line: arg 1.
 * Return: The extracted line
 */
static char	*get_line(char *line)
{
	int		k;
	char	*ptr;

	k = 0;
	if (!line)
		return (NULL);
	if (!line[k])
		return (NULL);
	while (line[k] && line[k] != '\n')
		k++;
	ptr = malloc(k + 2);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line, k);
	if (line[k] == '\n')
	{
		ptr[k] = '\n';
		ptr[k + 1] = '\0';
	}
	else
		ptr[k] = '\0';
	return (ptr);
}

/**
 * ft_left - Extract the remainingg part of a string.
 * @line: arg 1..
 * Return: The remaining parts of a string
 */
static char	*ft_left(char *line)
{
	int		k;
	char	*ptr;

	k = 0;
	if (!line)
		return (NULL);
	if (!line[k])
		return (NULL);
	while (line[k] && line[k] != '\n')
		k++;
	ptr = malloc(my_strlen(line) - k + 1);
	if (!ptr)
		return (NULL);
	my_memcpy(ptr, line + k + 1, my_strlen(line) - k);
	ptr[my_strlen(line) - k] = '\0';
	return (ptr);
}

/**
 * _getline - Read lines from fd.
 * @fd: arg 1.
 * @global: arg 2.
 * Return: The next line the file descriptorr,
 * or NULL on failure or end of files.
 */
char	*_getline(int fd, global_t *global)
{
	static char	*left;
	char		*line;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = all(fd, left);
	next_line = get_line(line);
	left = ft_left(line);
	global->left = left;
	free(line);
	return (next_line);
}
