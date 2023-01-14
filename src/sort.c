/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/14 16:36:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min(t_int_list *list)
{
	int	i;
	int	tmp;
	int	pos;

	i = 0;
	tmp = INT_MAX;
	while (list)
	{
		i++;
		if (list->cont < tmp)
		{
			tmp = list->cont;
			pos = i;
		}
		list = list->next;
	}
	return (pos);
}

void	sort(t_int_list **list_a)
{
	int			median_nbr;
	int			size;
	t_int_list	*tmp;

	tmp = *list_a;
	size = ft_lstintsize(tmp);
	tmp = *list_a;
	median_nbr = find_median(size, &tmp);
	ft_printf("%d (%d) (%d)", median_nbr, median_pos(size), size);
}
