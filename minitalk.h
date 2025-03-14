/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:07:34 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/13 01:23:02 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	check_input(int argc, char *argv[]);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);

#endif
