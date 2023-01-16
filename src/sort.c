/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/16 17:51:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	smart_push(t_int_list **list_a, t_int_list **list_b, int size)
{
	int			min;
	int			max;

	max = max_pos(list_b);
	min = min_pos(list_b);
	if (min == 1 || max == 1)
		pa(list_a, list_b);
	else
	{
		smart_rotate(list_b, size, max, min);
		pa(list_a, list_b);
	}
}

void	smart_push_and_rotate(t_int_list **list_b, t_int_list **list_a, int s)
{
	int	tmp;

	while (*list_b)
	{
		smart_push(list_a, list_b, s);
		tmp = (*list_a)->cont;
		if ((*list_a)->cont < find_min(list_b))
		{
			ra(list_a);
		}
	}
}

void	push_min_half(t_int_list **li_a, t_int_list **li_b, int median, int s)
{
	int			i;

	i = 0;
	while (i != median_pos(s))
	{
		while ((*li_a)->cont > median)
			ra(li_a);
		pb(li_a, li_b);
		i++;
	}
	smart_push_and_rotate(li_b, li_a, median_pos(s));
}

void	push_max_half(t_int_list **li_a, t_int_list **li_b, int median, int s)
{
	int			i;

	i = 0;
	while (i != s - median_pos(s))
	{
		while ((*li_a)->cont <= median)
			ra(li_a);
		pb(li_a, li_b);
		i++;
	}
	smart_push_and_rotate(li_b, li_a, s - median_pos(s));
}

void	sort_median(t_int_list **list_a)
{
	int			median_nbr;
	int			size;
	int			min;
	t_int_list	*list_b;
	t_int_list	*tmp;

	tmp = *list_a;
	size = ft_lstintsize(tmp);
	median_nbr = find_median(size, &tmp);
	list_b = NULL;
	push_min_half(list_a, &list_b, median_nbr, size);
	push_max_half(list_a, &list_b, median_nbr, size);
	min = min_pos(list_a);
	while ((*list_a)->cont != find_min(list_a))
	{
		if (min <= median_pos(size))
			ra(list_a);
		else
			rra(list_a);
	}
	ft_lstintclear(&list_b);
	ft_lstintclear(list_a);
}
