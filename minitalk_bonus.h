/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:53:35 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/05/08 12:26:57 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "./ft_printf/ft_printf.h"
# include <signal.h>

void	ft_correct(int sig);
void	ft_send_bits(int pid, char s);
void	ft_send_pid_size(int client_pid, int pid);
void	ft_message(int sig);
void	ft_get_pid(int sig);
int		ft_get_size(int sig);
void	ft_forwarder(int sig);

#endif
