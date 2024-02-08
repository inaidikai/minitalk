/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:48:00 by inkahar           #+#    #+#             */
/*   Updated: 2024/01/29 20:04:52 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiver(int c, siginfo_t *info, void *context)
{
	static int	bits;
	static int	ch;

	(void)context;
	if (c == SIGUSR1)
		ch += (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(ch, 1);
		if (ch == '\0')
		{
			usleep(500);
			kill(info->si_pid, SIGUSR1);
		}
		ch = 0;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Wrong format: Type server to get PID\n", 38);
		return (0);
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = receiver;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
