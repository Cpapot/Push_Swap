/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:34:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/14 19:43:20 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*tmp;

	if (list_a == NULL || *list_a == NULL)
		return ;
	tmp = (*list_a)->next;
	(*list_a)->next = *list_b;
	*list_b = *list_a;
	*list_a = tmp;
	ft_printf("pb\n");
}

void	pa(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*tmp;

	if (list_b == NULL || *list_b == NULL)
		return ;
	tmp = (*list_b)->next;
	(*list_b)->next = *list_a;
	*list_a = *list_b;
	*list_b = tmp;
	ft_printf("pa\n");
	return ;
}
