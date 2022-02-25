/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:59:32 by ahinani           #+#    #+#             */
/*   Updated: 2022/02/20 15:01:13 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handle(int signal)
{
	(void) signal;
	usleep(150);
	return ;
}

static int	char_to_bin(int server_pid, unsigned char c)
{
	int	i;
	int	j;
	int	bit;

	i = 8;
	bit = 0;
	if (c >= 0 && c <= 127)
	{
		while (i--)
		{
			bit = (c >> i) & 1;
			if (bit == 1)
				j = kill (server_pid, SIGUSR1);
			if (bit == 0)
				j = kill (server_pid, SIGUSR2);
			signal(SIGUSR1, ft_handle);
			if (j == -1)
				return (-1);
			pause();
		}
	}
	return (0);
}

static int	send_text(char *txt, int server_pid)
{
	int	i;

	i = -1;
	while (txt[++i])
	{
		if (char_to_bin(server_pid, txt[i]) == -1)
		{
			ft_putstr(RED"Invalid PID!\n");
			return (-1);
		}
	}
	char_to_bin(server_pid, '\0');
	return (0);
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		ft_putstr(YELLOW"Usage : ./client <server_pid> text to send\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	if (!server_pid || server_pid == -1)
	{
		ft_putstr(RED"Invalid PID!\n");
		exit(EXIT_FAILURE);
	}
	if (send_text(av[2], server_pid) == 0)
		exit(EXIT_SUCCESS);
}
