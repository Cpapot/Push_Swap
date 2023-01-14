/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:29:05 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/14 21:02:28 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_median_in_array(int *int_array, int size, int median_pos)
{
	int	i;
	int	u;
	int	count;

	i = 0;
	while (i < size)
	{
		u = 0;
		count = 0;
		while (u < size)
		{
			if (int_array[i] >= int_array[u])
				count++;
			u++;
		}
		if (count == median_pos)
			return (int_array[i]);
		i++;
	}
	return (0);
}

int	median_pos(int size)
{
	int			median_pos;

	if (size % 2 == 1)
		median_pos = (size + 1) / 2;
	else
		median_pos = size / 2;
	return (median_pos);
}

int	find_median(int size, t_int_list **list_a)
{
	int			med_pos;
	int			i;
	int			*int_array;
	int			result;

	i = 0;
	med_pos = median_pos(size);
	int_array = malloc(sizeof(int) * (size + 1));
	if (int_array == NULL)
		print_error(*list_a);
	while (*list_a)
	{
		int_array[i] = (*list_a)->cont;
		(*list_a) = (*list_a)->next;
		i++;
	}
	result = find_median_in_array(int_array, size, med_pos);
	free(int_array);
	return (result);
}
