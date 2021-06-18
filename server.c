/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 20:37:49 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/18 20:39:15 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <signal.h>

# include <string.h>

/* https://www.programiz.com/c-programming/bitwise-operators */

static void	signalHandler(int sigNo)
{
	printf("Signal catched\n");
}

int			main(int ac, char *av[])
{
	if (signal(SIGUSR1, signalHandler) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	signal(SIGUSR2, signalHandler);
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
