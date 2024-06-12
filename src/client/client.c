/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgolding <bgolding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:51:55 by bgolding          #+#    #+#             */
/*   Updated: 2024/01/22 14:47:49 by bgolding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sig_confirm = 0;

static void	send_char(pid_t pid, unsigned char c)
{
	unsigned char	bit_mask;
	int				bit_index;

	bit_index = 7;
	bit_mask = 1u << bit_index;
	while (bit_mask)
	{
		usleep(25);
		g_sig_confirm = 0;
		if (bit_mask & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		bit_mask >>= 1;
		while (!g_sig_confirm)
			pause();
	}
}

static void	send_message(pid_t pid, char *msg)
{
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (signum == SIGUSR1)
		g_sig_confirm = 1;
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Message succesfully transmitted\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	pid_t				pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <server PID> <string>\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_putstr_fd("Invalid PID\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	send_message(pid, argv[2]);
	sleep(10);
	ft_putstr_fd("Timeout, terminating process.\n", STDOUT_FILENO);
	return (0);
}
