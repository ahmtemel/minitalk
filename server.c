/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:50:22 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/04/06 13:01:00 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		signal(SIGUSR2, ft_message);
		signal(SIGUSR1, ft_message);
		pause();
	}
}
