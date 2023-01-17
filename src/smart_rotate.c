/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:50:49 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/17 20:15:16 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_info	rb_or_rrb(int size, int max, int min)
{
	t_info	info;
	int		rb_count;
	int		rrb_count;

	if (size - (min - 1) <= size - (max - 1))
		rrb_count = size - (min - 1);
	else
		rrb_count = size - (max - 1);
	if (min - 1 <= max - 1)
		rb_count = min - 1;
	else
		rb_count = max - 1;
	if (rb_count <= rrb_count)
	{
		info.nb = 1;
	}
	else
	{
		info.nb = 0;
	}
	return (info);
}

void	smart_rotate(t_int_list **list_b, int size, int max, int min)
{
	t_info	info;

	info = rb_or_rrb(size, max, min);
	if (info.nb == 1)
		while ((*list_b)->cont != find_min(list_b) && (*list_b)->cont != find_max(list_b))
			rb(list_b);
	else
		while ((*list_b)->cont != find_min(list_b) && (*list_b)->cont != find_max(list_b))
			rrb(list_b);
}
