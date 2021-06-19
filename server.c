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
# include <errno.h>

# include <string.h>

/* https://www.programiz.com/c-programming/bitwise-operators */

#define MAX_BYTES 64

// static void	handleSIGUSR(int sigNo)
// {
// 	static int	current_bit = 0;
// 	static char	byte = 0;

// 	if (sigNo == SIGUSR1)
// 	{
		
// 		ft_putchar_fd('1', STDOUT_FILENO);
// 	}
// 	if (sigNo == SIGUSR2)
// 	{
// 		ft_putchar_fd('0', STDOUT_FILENO);
// 	}
// 	// byte += (SIGUSR1 == sigNo) << current_bit;
// 	// current_bit++;
// 	// if (current_bit == 8)
// 	// {
// 	// 	current_bit = 0;
// 	// 	write(STDOUT_FILENO, &byte, 1);
// 	// 	byte = 0;
// 	// }
// }

static void	handleSIGUSR(int sigNo)
{
	static int	current_bit = 0;
	static int	current_byte = 0;
	static char	byte = 0;
	static char	output_bytes[MAX_BYTES];

	// if (sigNo == SIGUSR1)
	// 	ft_putchar_fd('1', STDOUT_FILENO);
	// if (sigNo == SIGUSR2)
	// 	ft_putchar_fd('0', STDOUT_FILENO);

	if (sigNo == SIGUSR1)
		byte &= ~(128 >> current_bit);
	if (sigNo == SIGUSR2)
		byte |= (128 >> current_bit);
	// byte += (SIGUSR1 == sigNo) << current_bit;
	current_bit++;
	if (current_bit == 8)
	{
		current_bit = 0;
		ft_putchar_fd(byte, STDOUT_FILENO);
		// output_bytes[current_byte] = byte;
		byte = 0;
		// if (current_byte < (MAX_BYTES - 1))
		// 	current_byte++;
	}
	// ft_putstr_fd(output_bytes, STDOUT_FILENO);
}

int			main(int ac, char *av[])
{
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

		if (signal(SIGUSR1, handleSIGUSR) == SIG_ERR)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			strerror(errno);
			return (EXIT_FAILURE);
		}
		if (signal(SIGUSR2, handleSIGUSR) == SIG_ERR)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			strerror(errno);
			return (EXIT_FAILURE);
		}

		while (TRUE)
			pause();
	}
	return (EXIT_SUCCESS);
}
