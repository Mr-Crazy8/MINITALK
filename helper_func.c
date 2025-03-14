/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:21:09 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/13 02:59:44 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if ((argv[1][j] < '0' || argv[1][j] > '9'))
			(write(2, "Error: PID must contain only digits\n", 35), exit(1));
		j++;
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < 100 || server_pid > 99999)
		(write(2, "Error: Invalid PID range\n", 25), exit(1));
	if (kill(server_pid, 0) == -1)
		(write(2, "Error: Process doesn't exist\n", 28), exit(1));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar(nbr % 10 + '0');
}
