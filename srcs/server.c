/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:06 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 15:06:29 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	convert_bit(int sig)
{
	static int				size;
	static unsigned char	str;

	str += ((sig % 2) << size);
	size++;
	if (size == 8)
	{
		write(1, &str, 1);
		str = 0;
		size = 0;
	}
}

int	main(void)
{
	pid_t	i;

	i = getpid();
	signal(SIGUSR1, convert_bit);
	signal(SIGUSR2, convert_bit);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
