/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quarter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:56:40 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/17 01:46:44 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	quarter_size(int size, int index)
{
	int	i;

	i = 0;
	if (size % 4 == 0)
		return (size / 4);
	else
	{
		while (size % 4 != 0)
		{
			size--;
			i++;
		}
		if (index == 0)
			return (((size / 4) + i));
		else
			return (size / 4);
	}
}

t_info	quarter_info(t_int_list **list_a, int index, int size)
{
	t_info		info;
	int			i;
	int			tmp;

	info.quart_min = INT_MIN;
	info.quart_max = INT_MIN;
	info.quart_size = quarter_size(size, index);
	tmp = 0;
	i = 0;
	while (i <= index)
	{
		tmp += quarter_size(size, i);
		i++;
	}
	i = 0;
	while (i != tmp)
	{
		info.quart_max = find_min_superior_at(info.quart_max, list_a);
		if (i == (tmp - info.quart_size))
			info.quart_min = info.quart_max;
		i++;
	}
	return (info);
}

void	push_quarter(t_int_list **list_a, t_int_list **list_b, int size, int index)
{
	int			i;
	int			min;
	t_info		info;

	info = quarter_info(list_a, index, size);
	i = 0;
	while (i != info.quart_size)
	{
		while ((*list_a)->cont > info.quart_max || (*list_a)->cont < info.quart_min)
			ra(list_a);
		pb(list_a, list_b);
		i++;
	}
	min = min_pos(list_a);
	while ((*list_a)->cont != find_min(list_a))
	{
		if (min <= median_pos(size))
			ra(list_a);
		else
			rra(list_a);
	}
	smart_push_and_rotate(list_b, list_a, info.quart_size);
}

void	sort_quarter(t_int_list	**list_a, int size)
{
	t_int_list	*list_b;
	int			i;
	int			min;

	i = 0;
	list_b = NULL;
	while (i != 4)
	{
		push_quarter(list_a, &list_b, size, i);
		i++;
	}
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
