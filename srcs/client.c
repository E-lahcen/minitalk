/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:22:23 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 15:08:49 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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

void	send_server(char **data, pid_t pid)
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
			usleep(800);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3 && check_args(argv[1]))
	{
		pid = ft_atoi(argv[1]);
		send_server(argv, pid);
	}
	return (0);
}
