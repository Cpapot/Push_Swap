/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:43:48 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/17 20:33:48 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	call_sorter(t_int_list **list_a)
{
	int			len;
	t_int_list	*list;

	list = *list_a;
	len = ft_lstintsize(list);
	if (is_sorted(list))
	{
		ft_lstintclear(list_a);
		return ;
	}
	else if (len == 2)
	{
		ra(list_a);
		ft_lstintclear(list_a);
	}
	else if (len == 3)
		sort_three_nbr(&list);
	else if (len == 5)
		sort_five_nbr(&list);
	else if (len < 100)
		sort_median(&list);
	else
		sort_quarter(&list, len);
}
