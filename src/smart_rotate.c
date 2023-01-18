/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:50:49 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/18 17:01:29 by cpapot           ###   ########.fr       */
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

void	smart_rotate(t_int_list **li, int size, int max, int min)
{
	t_info	info;

	info = rb_or_rrb(size, max, min);
	if (info.nb == 1)
		while ((*li)->cont != find_min(li) && (*li)->cont != find_max(li))
			rb(li);
	else
		while ((*li)->cont != find_min(li) && (*li)->cont != find_max(li))
			rrb(li);
}
