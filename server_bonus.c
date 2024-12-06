/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:50:27 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/05/08 11:55:50 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_message(int sig)
{
	static int	bit;
	static int	s;

	if (sig == SIGUSR1)
		s += (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", s);
		bit = 0;
		s = 0;
	}
}

void	ft_get_pid(int sig)
{
	static int	i;
	static int	bit;

	if (sig == SIGUSR1)
		i += (0x01 << bit);
	bit++;
	if (bit == 32)
	{
		kill(i, SIGUSR1);
		i = 0;
		bit = 0;
	}
}

int	ft_get_size(int sig)
{
	static int	bit;
	static int	size;
	static int	r;

	if (sig == SIGUSR1)
		size += (0x01 << bit);
	bit++;
	if (bit == 32)
	{
		r = size;
		size = 0;
		bit = 0;
		return (r);
	}
	return (size);
}

void	ft_forwarder(int sig)
{
	static int	i;
	static int	size;

	if (i < 32)
	{
		ft_get_pid(sig);
		i++;
	}
	else if (i < 64 && i > 31)
	{
		size = ft_get_size(sig);
		i++;
	}
	else if (i > 63 && i < (64 + (size * 8)))
	{
		ft_message(sig);
		i++;
		if (i == (64 + (size * 8)))
		{
			size = 0;
			i = 0;
			ft_printf("\n");
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	(void)av;
	if (ac == 1)
	{
		ft_printf("PID: %d\n", pid);
	}
	if (ac != 1)
	{
		write(1, "Wrong format try with only ./server", 35);
		return (0);
	}
	while (ac == 1)
	{
		signal(SIGUSR2, ft_forwarder);
		signal(SIGUSR1, ft_forwarder);
		pause();
	}
}
