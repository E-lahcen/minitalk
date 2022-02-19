/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:22:23 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 18:36:25 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	check_received(int sig)
{
	if (sig)
		write(1, "Well received !\n", 17);
	exit(0);
}

int	check_args(char *pid)
{
	while (*pid)
	{
		if (!ft_isdigit(*pid))
			return (0);
		pid++;
	}
	return (1);
}

void	kill_server(char **data, pid_t pid)
{
	int	j;
	int	i;

	i = 0;
	while (data[2][i])
	{
		j = 0;
		while (j < 8)
		{
			if ((data[2][i] >> j) & 1)
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		j;
	pid_t	pid;

	if (argc == 3 && check_args(argv[1]))
	{
		signal(SIGUSR2, check_received);
		pid = ft_atoi(argv[1]);
		kill_server(argv, pid);
		j = 8;
		while (j--)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		while (1)
			pause();
	}
	else
		write(1, "Please Write PID of the server + Data wanted\
			   	to be send.\nNothing more!", 70);
	return (0);
}
