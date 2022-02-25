/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:39:25 by ahinani           #+#    #+#             */
/*   Updated: 2022/02/16 14:31:05 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_idclient;

static void	piid(int pid, char *buf, char *bit)
{
	if (pid != g_idclient)
	{
		g_idclient = pid;
		*buf = 0;
		*bit = 7;
	}
}

static void	receive_text(int sig, siginfo_t *data, void *context)
{
	static char	buf = 0;
	static char	bit = 7;
	int			pid;

	pid = data->si_pid;
	(void) context;
	piid(pid, &buf, &bit);
	if (sig == SIGUSR1)
		buf |= (1 << bit);
	if (sig == SIGUSR2)
		buf |= 0;
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (buf)
		{
			write(1, &buf, 1);
			buf = 0;
		}
		else
			write(1, "\n", 1);
	}
	usleep(150);
	kill(g_idclient, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sigs;

	g_idclient = 0;
	pid = getpid();
	ft_putstr(YELLOW"\nPID : ");
	ft_putnbr(pid);
	ft_putstr("\n");
	sigs.sa_flags = SA_SIGINFO;
	sigs.sa_sigaction = receive_text;
	sigaction(SIGUSR1, &sigs, NULL);
	sigaction(SIGUSR2, &sigs, NULL);
	while (1)
		pause();
	return (0);
}
