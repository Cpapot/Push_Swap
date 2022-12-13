/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:43:48 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/13 00:39:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	call_sorter(t_int_list *list_a)
{
	int	len;

	len = ft_lstintsize(list_a);
	if (is_sorted(list_a))
		return ;
	else if (len == 3)
		sort_three_nbr(list_a);
	else if (len == 5)
		sort_five_nbr(list_a);
}
