/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:58:45 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 18:23:20 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	convert_bit(int sig, siginfo_t *info, void *context)
{
	static int				size;
	static unsigned char	str;
	pid_t					pid_client;

	pid_client = 0;
	context = NULL;
	str += ((sig % 2) << size);
	if (!pid_client)
		pid_client = info->si_pid;
	size++;
	if (size == 8)
	{
		write(1, &str, 1);
		if (!str)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
		}
		str = 0;
		size = 0;
	}
}

int	main(void)
{
	pid_t				i;
	struct sigaction	sa;

	i = getpid();
	sa.sa_sigaction = convert_bit;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	system("leaks client");
	return (0);
}
