/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:05:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/13 12:48:49 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_smallest_pos(t_int_list **list_a)
{
	int			tmp;
	int			i;
	t_int_list	*list;

	list = *list_a;
	tmp = list->cont;
	while (list)
	{
		if (tmp > list->cont)
			tmp = list->cont;
		list = list->next;
	}
	i = 0;
	list = *list_a;
	while (tmp != list->cont)
	{
		i++;
		list = list->next;
	}
	return (i);
}

void	push_smallest(t_int_list **list_a, t_int_list **list_b)
{
	int			smallest;
	int			i;

	i = 0;
	smallest = find_smallest_pos(list_a);
	if (smallest < 3)
	{
		while (i != smallest)
		{
			ra(list_a);
			i++;
		}
	}
	else
	{
		while (i != ft_lstintsize(*list_a) - smallest)
		{
			rra(list_a);
			i++;
		}
	}
	pb(list_a, list_b);
}

void	sort_five_nbr(t_int_list *list_a)
{
	t_int_list	*list_b;

	list_b = NULL;
	push_smallest(&list_a, &list_b);
	push_smallest(&list_a, &list_b);
	sort_three_nbr(&list_a);
	pa(&list_a, &list_b);
	pa(&list_a, &list_b);
	ft_lstintclear(&list_b);
}
