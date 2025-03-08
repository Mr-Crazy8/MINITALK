/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:41:50 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/08 03:01:38 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int	ft_atoi(const char *str);

typedef struct s_signal_data
{
	unsigned char	res;
	int				i;
	int				bytes_needed;
	int				bytes_received;
	unsigned char	utf8_buffer[4];
	pid_t			pid;
}	t_signal_data;

#endif
