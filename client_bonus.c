/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:48:18 by inkahar           #+#    #+#             */
/*   Updated: 2024/01/29 20:05:51 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int sig)
{
	(void)sig;
	write(1, "Signal received\n", 16);
	exit(0);
}

void	client(int pid, char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		i--;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		write(1, "Wrong format, try ./client\n", 27);
		return (1);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			client(pid, argv[2][i]);
			i++;
		}
		client(pid, '\0');
		signal(SIGUSR1, sighandler);
		while (1)
			pause();
	}
	return (0);
}
