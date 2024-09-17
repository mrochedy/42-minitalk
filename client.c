/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochedy <mrochedy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:05:02 by mrochedy          #+#    #+#             */
/*   Updated: 2024/09/17 19:23:37 by mrochedy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_is_response_received = 0;

void	receive_response(int a)
{
	(void)a;
	g_is_response_received = 1;
}

void	encode_and_send(char c, int pid)
{
	long	i;
	int		bit;
	int		j;

	i = BINARY_SIZE - 1;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		j = 0;
		while (!g_is_response_received && j++ < 100)
			usleep(100);
		if (j >= 100)
		{
			ft_putstr_fd("Error\nTargeted process not responding\n", 2);
			exit(1);
		}
		g_is_response_received = 0;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (ft_putstr_fd("Error\nThe program receives 2 arguments: \
first one is the PID of the server, second one is \
the string to send.\n", 2), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_putstr_fd("Error\nPID is invalid\n", 2), 1);
	i = 0;
	signal(SIGUSR1, receive_response);
	while (argv[2][i])
		encode_and_send(argv[2][i++], pid);
	encode_and_send('\0', pid);
	return (0);
}
