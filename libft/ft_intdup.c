/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 11:52:50 by aabounak          #+#    #+#             */
/*   Updated: 2021/06/12 11:53:03 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int			*ft_intdup(const int d)
{
	int		*n;

	n = (int *)malloc(sizeof(int));
	*n = d;
	return (n);
}
