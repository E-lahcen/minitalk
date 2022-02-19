/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelhlami <lelhlami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:57:27 by lelhlami          #+#    #+#             */
/*   Updated: 2022/02/19 18:14:48 by lelhlami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

int		check_args(char *pid);
int		ft_isdigit(int c);
void	convert_bit(int sig);
void	send_server(char **data, pid_t pid);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		check_out_nbr(unsigned long nbr, int neg);
int		ft_atoi(const char *str);

#endif
