/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:16:53 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/08 15:38:28 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	skip_whitespace_and_sing(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;
	long long	check;

	i = 0;
	res = 0;
	check = 0;
	sign = 1;
	i = skip_whitespace_and_sing(str, &sign);
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		res = res * 10 + (str[i] - '0');
		if (res / 10 != check)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		check = res;
		i++;
	}
	return ((int)(res * sign));
}

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

int	main(int argc, char *argv[])
{
	int	i;
	int	server_pid;

	i = 0;
	server_pid = ft_atoi(argv[1]);
	check_input(argc, argv);
	while (argv[2][i])
	{
		convert_bits_to_sig(server_pid, argv[2][i]);
		i++;
	}
}
