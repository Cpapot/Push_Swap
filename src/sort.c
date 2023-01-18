/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/18 14:42:48 by cpapot           ###   ########.fr       */
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
	while (*list_b)
	{
		smart_push(list_a, list_b, s);
		if ((*list_a)->cont < find_min(list_b))
		{
			ra(list_a);
		}
	}
}
