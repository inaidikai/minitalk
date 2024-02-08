/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:10:39 by inkahar           #+#    #+#             */
/*   Updated: 2024/01/29 13:18:11 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(int pid, char c)
{
	int		i;
	char	t;

	i = 8;
	while (i > 0)
	{
		i--;
		t = c >> i;
		if (t % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			client(pid, argv[2][i]);
			i++;
		}
		client(pid, '\n');
	}
	else
	{
		write(1, "wrong format try ./client", 27);
		return (1);
	}
	return (0);
}
