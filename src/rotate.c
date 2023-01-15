/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:41 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/15 01:09:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_int_list **list)
{
	t_int_list	tmp;
	t_int_list	*lista;

	lista = *list;
	tmp.cont = lista->cont;
	tmp.nb = lista->nb;
	while (lista->next)
	{
		lista->cont = lista->next->cont;
		lista->nb = lista->next->nb;
		lista = lista->next;
	}
	lista->cont = tmp.cont;
	lista->nb = tmp.nb;
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

void	rb_to_push(t_int_list **list_b, int rotation)
{
	int		i;

	i = 0;
	while (i != rotation)
	{
		rb(list_b);
		i++;
	}
}
