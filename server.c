/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:00 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/17 19:25:38 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static long		i = 0;
	static char		c = 0;
	static pid_t	client_pid = 0;

	if (client_pid == 0)
		client_pid = info->si_pid;
	(void)context;
	if (signum == SIGUSR1)
		c <<= 1;
	else if (signum == SIGUSR2)
		c = (c << 1) | 1;
	if (++i == BINARY_SIZE)
	{
		i = 0;
		if (c == '\0')
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigemptyset(&action.sa_mask);
	ft_putstr_fd("My Server PID: \033[33m", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\033[0m\n", 1);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
