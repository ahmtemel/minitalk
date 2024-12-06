/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:11:26 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/05/08 11:56:23 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char s)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((s & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;
	int	size;

	if (ac != 3)
	{
		ft_printf("Wrong format try with ./client ... ...");
		return (0);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	size = ft_strlen(av[2]);
	while (i < size)
	{
		ft_send_bits(pid, av[2][i]);
		i++;
	}
	if (i == size)
		ft_send_bits(pid, '\n');
}
