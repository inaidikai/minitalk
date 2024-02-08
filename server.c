/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:14:38 by inkahar           #+#    #+#             */
/*   Updated: 2024/01/29 17:43:05 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	recive(int c)
{
	static int	bits;
	static int	ch;

	if (c == SIGUSR1)
		ch += (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(ch, 1);
		ch = 0;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		write(1, "wrong format type server to get pid", 37);
		return (0);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, recive);
		signal(SIGUSR2, recive);
	}
	return (0);
}
