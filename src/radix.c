/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:23:58 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/13 17:12:42 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_bin_size(unsigned int nbr)
{
	int	index;

	index = 0;
	while (nbr >= 2)
	{
		nbr = nbr / 2;
		index++;
	}
	if (nbr != 0)
		index++;
	return (index);
}

static int	ft_convert_bin(unsigned int nbr)
{
	char	*base;
	char	*result;
	int		size;
	int		index;

	base = "01";
	size = ft_bin_size(nbr);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (0);
	index = size - 1;
	ft_bzero(result, size + 1);
	while (nbr >= 2)
	{
		result[index] = base[nbr % 2];
		nbr = nbr / 2;
		index--;
	}
	if (nbr != 0)
		result[index] = base[nbr % 2];
	result[size] = '\0';
	size = ft_atoi(result);
	free (result);
	return (size);
}

void	radix(t_int_list **list_a)
{
	t_int_list	*list_b;
	int			i;

	list_b = NULL;
	i = 1;
	while (i - 1 =! )

}
