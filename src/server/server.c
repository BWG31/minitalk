/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:52:06 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/22 14:47:48 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_sig_confirm = 0;

static void	signal_handler(int signum, siginfo_t *client, void *ucontext)
{
	static int				bit_index = -1;
	static unsigned char	c = 0;

	g_sig_confirm = 1;
	usleep(25);
	(void)ucontext;
	if (bit_index < 0)
		bit_index = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
	}
	else if (bit_index < 0 && !c)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		kill(client->si_pid, SIGUSR2);
		g_sig_confirm = 0;
		return ;
	}
	kill(client->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_putstr_fd("Server PID: ", STDOUT_FILENO);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
