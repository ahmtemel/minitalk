/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:50:22 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/05/08 11:54:00 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_correct(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message Sent Successfully!", 26);
}

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

void	ft_send_pid_size(int client_pid, int pid)
{
	int		i;

	i = 0;
	while (i < 32)
	{
		if ((client_pid & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;
	int	client_pid;
	int	size;

	if (ac != 3)
	{
		ft_printf("Wrong format try with ./client ... ...");
		return (0);
	}
	client_pid = getpid();
	i = 0;
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_correct);
	ft_send_pid_size(client_pid, pid);
	size = ft_strlen(av[2]);
	ft_send_pid_size(size, pid);
	while (i < size)
	{
		ft_send_bits(pid, av[2][i]);
		i++;
	}
}
