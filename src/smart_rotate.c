/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:50:49 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/15 02:12:23 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		rb_or_rrb(int size, int max_pos, int min_pos)
{
	if () // rb
	{

		return (1);
	}
	else
	{
		return (0);
	}
}

int		near_min_or_max(int size, int max_pos, int min_pos)
{
	int	pos;

	if (rb_or_rrb(size, max_pos, min_pos)
	{
		if ((min_pos - 1) <= (max_pos - 1))
			pos = min_pos;
		else
			pos = max_pos;
		return (pos - 1)
	}
	else
	{
		if ((size - (min_pos - 1)) <= (size - (max_pos - 1)))
			pos = min_pos;
		else
			pos = max_pos;
		return (size - (pos - 1));
	}
}

void	smart_rotate(t_int_list list_b, int size, int max, int min)
{
	int		pos;
	int		rotation;

	pos = near_min_or_max(size, max, min);
	if (rb_or_rrb(size, max, max))
	{
		rotation = pos - 1;
		rb_to_push(list_b, rotation);
	}
	else
	{
		rotation = size - (pos - 1);
		rrb_to_push(list_a, rotation);
	}
}
