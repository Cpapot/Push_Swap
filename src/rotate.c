/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:41 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/12 23:43:48 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_int_list **list)
{
	int			tmp;
	t_int_list	*lista;

	tmp = 0;
	lista = *list;
	tmp = lista->cont;
	while (lista->next)
	{
		lista->cont = lista->next->cont;
		lista = lista->next;
	}
	lista->cont = tmp;
	return ;
}

void	ra(t_int_list **list_a)
{
	rotate(list_a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_int_list **list_b)
{
	rotate(list_b);
	ft_printf("rb");
	return ;
}

void	rr(t_int_list **list_a, t_int_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
	return ;
}
