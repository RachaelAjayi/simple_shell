
/**
 *printno - function prints number.
 *@i: first argument, number to be printed.
 *@t: second argument, where output will be written.
 */
void	printno(int i, int t)
{
	if (i < 10)
		write(t, &"0123456789"[i % 10], 1);
	else
	{
		printno(i / 10, t);
		printno(i % 10, t);
	}
}
