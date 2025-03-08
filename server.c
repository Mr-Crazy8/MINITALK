/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:17:45 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/08 02:22:52 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_res(int sig, siginfo_t *info, void *v)
{
	static char		res;
	static int		i;
	static pid_t	pid;

	(void)v;
	if (pid == 0)
		pid = info->si_pid;
	else if (pid != info->si_pid)
	{
		i = 0;
		res = 0;
		pid = 0;
	}
	res <<= 1;
	if (sig == SIGUSR1)
		res |= 1;
	i++;
	if (i == 8)
	{
		if (res >= 0 && res <= 127)
			write(1, &res, 1);
		i = 0;
		res = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = print_res;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("_____{%d}_____\n", getpid());
	while (1)
		pause();
}
