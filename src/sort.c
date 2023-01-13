/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/13 17:42:01 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min_pos(t_int_list *list)
{
	int	i;
	int	pos;
	int	tmp;

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
	int	i;
	int	pos;

	while (!is_sorted(*list_a))
	{
		pos = find_min_pos(*list_a);
		if (pos <= (ft_lstintsize(*list_a) / 2))
		{
			i = 1;
			while (i != pos)
			{
				i++;
				ra(list_a);
			}
		}
		else
		{
			i = ft_lstintsize(*list_a);
			while (i != pos)
			{
				i--;
				rra(list_a);
			}
		}
	}
}
