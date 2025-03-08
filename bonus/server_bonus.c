/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:57:59 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/08 03:00:48 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	get_utf8_size(unsigned char byte)
{
	if ((byte & 0x80) == 0)
		return (1);
	else if ((byte & 0xE0) == 0xC0)
		return (2);
	else if ((byte & 0xF0) == 0xE0)
		return (3);
	else if ((byte & 0xF8) == 0xF0)
		return (4);
	return (1);
}

void	handle_signal_bit(int sig, siginfo_t *info, void *v,
				t_signal_data *data)
{
	(void)v;
	if (data->pid == 0)
		data->pid = info->si_pid;
	else if (data->pid != info->si_pid)
	{
		data->i = 0;
		data->res = 0;
		data->bytes_needed = 0;
		data->bytes_received = 0;
		data->pid = info->si_pid;
	}
	data->res = data->res << 1;
	if (sig == SIGUSR1)
		data->res |= 1;
	data->i++;
}

void	process_completed_byte(t_signal_data *data)
{
	data->utf8_buffer[data->bytes_received] = data->res;
	data->bytes_received++;
	if (data->bytes_received == 1)
		data->bytes_needed = get_utf8_size(data->res);
	if (data->bytes_received == data->bytes_needed)
	{
		write(1, data->utf8_buffer, data->bytes_received);
		if (data->bytes_received == 1 && data->utf8_buffer[0] == '\0')
			kill(data->pid, SIGUSR1);
		data->bytes_received = 0;
		data->bytes_needed = 0;
	}
}

void	print_res(int sig, siginfo_t *info, void *v)
{
	static t_signal_data	data = {0};

	handle_signal_bit(sig, info, v, &data);
	if (data.i == 8)
	{
		process_completed_byte(&data);
		data.i = 0;
		data.res = 0;
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
