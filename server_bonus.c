/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:37:49 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/18 20:39:15 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	handleSIGUSR(int sigNo)
{
	static int	serverAcknowledged;
	static int	current_bit;
	static char	byte;

	if ((SIGUSR1 == sigNo || SIGUSR2 == sigNo) && serverAcknowledged == 0)
	{
		serverAcknowledged = 1;
		ft_putstr_fd("SIG acknowledged\nReceiving messages\n", STDOUT_FILENO);
	}
	byte += (SIGUSR1 == sigNo) << current_bit;
	current_bit++;
	if (current_bit == LAST_BIT)
	{
		current_bit = 0;
		ft_putchar_fd(byte, STDOUT_FILENO);
		byte = 0;
	}
}

int	server(void)
{
	if (signal(SIGUSR1, handleSIGUSR) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, handleSIGUSR) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char *av[])
{
	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error\nIncorrect arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("Server running [PID]-> ", STDOUT_FILENO);
		ft_putnbr_fd(getpid(), STDOUT_FILENO);
		ft_putendl_fd(NULL, STDOUT_FILENO);
		server();
		while (TRUE)
			pause();
	}
	return (EXIT_SUCCESS);
}
