/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:23:58 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/14 14:46:42 by cpapot           ###   ########.fr       */
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

void	add_binary(t_int_list **list_a)
{
	t_int_list	*list;
	int			i;
	int			tmp;

	i = 1;
	list = *list_a;
	while (i - 1 != ft_lstintsize(list))
	{
		tmp = INT_MAX;
		while (list)
		{
			if (list->cont <= tmp && list->nb == 0)
				tmp = list->cont;
			list = list->next;
		}
		list = *list_a;
		while (list->cont != tmp)
			list = list->next;
		list->nb = ft_convert_bin(i);
		ft_printf("\n%d: %d", list->cont, list->nb);
		i++;
		list = *list_a;
	}
}

void	radix(t_int_list **list_a)
{
	int			divide_bin;
	t_int_list	*lista;
	int			i;
	int			u;
	t_int_list	*listb;

	add_binary(list_a);
	lista = *list_a;
	i = 0;
	u = 0;
	listb = NULL;
	divide_bin = 2;
	while (i != 3)
	{
		while (u != ft_lstintsize(lista))
		{
			if ((lista->nb % divide_bin) >= (divide_bin / 2))
				pb(&lista, &listb);
			ra(&lista);
		}
		while (listb)
			pa(&lista, &listb);
		i++;
		divide_bin *= 10;
	}
}
