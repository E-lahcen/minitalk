/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:30:17 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 15:11:47 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	p;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		p = (unsigned int)(n * -1);
	}
	else
		p = (unsigned int)n;
	if (p > 9)
	{
		ft_putnbr_fd(p / 10, fd);
		ft_putnbr_fd(p % 10, fd);
	}
	else
		ft_putchar_fd(p + 48, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	check_out_nbr(unsigned long nbr, int neg)
{
	if (nbr > 9223372036854775807)
	{
		if (neg == 1)
			return (-1);
		else if (neg == -1)
			return (0);
	}
	return (nbr * neg);
}

int	ft_atoi(const char *str)
{
	unsigned long			nbr;
	int						is_negative;

	nbr = 0;
	is_negative = 1;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str
			== '\r' || *str == '\v' || *str == '\f'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		is_negative = -1;
	}
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			nbr = nbr * 10 + (*str - 48);
		else
			return (is_negative * nbr);
		str++;
	}
	return (check_out_nbr(nbr, is_negative));
}
