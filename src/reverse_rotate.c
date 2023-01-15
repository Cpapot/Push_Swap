/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:35:16 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/15 01:08:43 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_int_list	**list)
{
	t_int_list	*listtmp;
	t_int_list	*start;
	t_int_list	temp;
	int			tmp;
	int			bintmp;

	tmp = 0;
	start = *list;
	listtmp = *list;
	while (listtmp)
	{
		tmp = listtmp->cont;
		bintmp = listtmp->nb;
		listtmp->cont = temp.cont;
		listtmp->nb = temp.nb;
		temp.cont = tmp;
		temp.nb = bintmp;
		listtmp = listtmp->next;
	}
	start->cont = tmp;
}

void	rra(t_int_list **list_a)
{
	reverse_rotate(list_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_int_list **list_b)
{
	reverse_rotate(list_b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_int_list **list_a, t_int_list **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	ft_printf("rrr\n");
}

void	rrb_to_push(t_int_list **list_b, int rotation)
{
	int		i;

	i = 0;
	while (i != rotation)
	{
		rrb(list_b);
		i++;
	}
}
