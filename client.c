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

# include <string.h>

int		main(int ac, char *av[])
{
	int		killRet;
	int		i;
	int		current_bit;

	if (ac != 3)
	{
		ft_putstr_fd("Error\nIncorrect arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (av[2][i])
	{
		current_bit = 0;
		while (current_bit < 8)
		{
			usleep(150);
			if ((av[2][i] >> current_bit) & 1)
				killRet = kill(ft_atoi(av[1]), SIGUSR1);
			else if ((av[2][i] >> current_bit) | 1)
				killRet = kill(ft_atoi(av[1]), SIGUSR2);
			if (killRet == -1)
			{
				ft_putstr_fd("Error\nProcess not found\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
			current_bit++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
