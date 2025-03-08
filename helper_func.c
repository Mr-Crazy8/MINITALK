#include "minitalk.h"

void	check_input(int argc, char *argv[])
{
	int	j;
	int	server_pid;

	if (argc != 3)
		(write(2, "Usage: ./client [server_pid] [string]\n", 39), exit(1));
	j = 0;
	while (argv[1][j])
	{
		if (argv[1][j] != ' ' && (argv[1][j] < '0' || argv[1][j] > '9'))
			(write(2, "Error: PID must contain only digits\n", 35), exit(1));
		j++;
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 99999)
		(write(2, "Error: Invalid PID range\n", 25), exit(1));
}