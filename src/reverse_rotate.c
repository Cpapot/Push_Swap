/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:35:16 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/12 23:44:09 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate(t_int_list	**list)
{
	t_int_list	*listtmp;
	int			tmp;
	int			tmp2;

	tmp = 0;
	listtmp = *list;
	while (list)
	{
		tmp2 = listtmp->cont;
		listtmp->cont = tmp;
		tmp = tmp2;
		listtmp = listtmp->next;
	}
	listtmp = *list;
	listtmp->cont = tmp;
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
