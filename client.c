/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:39:25 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/18 20:40:05 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <signal.h>

int		pidSyntaxChecker(char *av)
{
	int		i;

	i = -1;
	while (av[++i] != '\0')
	{
		if (!ft_isdigit(av[i]))
		{
			ft_putstr_fd("Error\nIncorrect PID\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int		acknowledgmentSystem(int killRet, char *av)
{
	static int	clientAcknowledged;

	if (killRet == -1)
	{
		ft_putstr_fd("Error\nProcess not found\n", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	if (killRet == 0 && clientAcknowledged == 0)
	{
		clientAcknowledged = 1;
		ft_putstr_fd("Signal Acknowledged ---- [PID :", STDOUT_FILENO);
		ft_putnbr_fd(ft_atoi(av), STDOUT_FILENO);
		ft_putstr_fd("] is found\nMessage sent\n", STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}

int		client(char *av[])
{
	int		killRet;
	int		i;
	int		current_bit;

	i = -1;
	while (av[2][++i])
	{
		current_bit = -1;
		while (++current_bit < 8)
		{
			usleep(150);
			if ((av[2][i] >> current_bit) & 1)
				killRet = kill(ft_atoi(av[1]), SIGUSR1);
			else if ((av[2][i] >> current_bit) | 1)
				killRet = kill(ft_atoi(av[1]), SIGUSR2);
			acknowledgmentSystem(killRet, av[1]);
		}
	}
	return (EXIT_SUCCESS);
}

int		main(int ac, char *av[])
{
	if (ac != 3)
	{
		ft_putstr_fd("Error\nIncorrect arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pidSyntaxChecker(av[1]);
	client(av);
	return (EXIT_SUCCESS);
}
