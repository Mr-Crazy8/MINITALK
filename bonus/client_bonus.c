/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:27:15 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/08 15:35:18 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_sig(int server_pid, int bit)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	usleep(400);
}

void	convert_bits_to_sig(int sever_pid, char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			send_sig(sever_pid, 1);
		else
			send_sig(sever_pid, 0);
		usleep(400);
	}
}

void	print_done(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Done\n", 5);
}

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

int	main(int argc, char *argv[])
{
	int	i;
	int	server_pid;

	i = 0;
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, print_done);
	check_input(argc, argv);
	while (argv[2][i])
	{
		convert_bits_to_sig(server_pid, argv[2][i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		send_sig(server_pid, 0);
		i++;
		usleep(400);
	}
	usleep(1000000);
}
