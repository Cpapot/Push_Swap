/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/15 18:05:00 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	smart_push(t_int_list **list_a, t_int_list **list_b, int size)
{
	int		min;
	int		max;

	max = max_pos(list_b);
	min = min_pos(list_b);
	smart_rotate(list_b, size, max, min);
	pa(list_a, list_b);
}

void	push_min_half(t_int_list **list_a, t_int_list **list_b, int median_nbr, int size)
{
	int			i;

	i = 0;
	while (i != median_pos(size))
	{
		while ((* list_a)->cont > median_nbr)
			ra(list_a);
		pb(list_a, list_b);
		i++;
	}
}

void	push_max_half(t_int_list **list_a, t_int_list **list_b, int median_nbr, int size)
{
	int	i;

	i = 0;
	while (i != size - median_pos(size))
	{
		while ((* list_a)->cont <= median_nbr)
			ra(list_a);
		pb(list_a, list_b);
		i++;
	}
}

void	sort(t_int_list **list_a)
{
	int			median_nbr;
	int			size;
	t_int_list	*list_b;
	t_int_list	*tmp;

	tmp = *list_a;
	size = ft_lstintsize(tmp);
	median_nbr = find_median(size, &tmp);
	list_b = NULL;
	push_min_half(list_a, &list_b, median_nbr, size);
	while (list_b)
	{
		smart_push(list_a, &list_b, size);
		if ((*list_a)->cont < find_min(&list_b))
			ra(list_a);
	}
	push_max_half(list_a, &list_b, median_nbr, size);
	while (list_b)
	{
		smart_push(list_a, &list_b, size);
		if ((*list_a)->cont < find_min(&list_b))
			ra(list_a);
	}
	while ((*list_a)->cont != find_min(list_a))
		ra(list_a);
	ft_lstintclear(&list_b);
	ft_lstintclear(list_a);
}
