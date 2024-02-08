/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:18:28 by inkahar           #+#    #+#             */
/*   Updated: 2024/01/29 17:54:41 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <ctype.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	recive(int c);
void	receiver(int c, siginfo_t *info, void *context);
void	client(int pid, char c);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	sighandler(int sig);
#endif