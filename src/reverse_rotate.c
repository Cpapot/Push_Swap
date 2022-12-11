/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:41:41 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 17:08:33 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_int_list **list_a)
{
	int			tmp;
	t_int_list	*lista;

	lista = *list_a;
	tmp = lista->cont;
	while (lista->next)
	{
		lista->cont = lista->next->cont;
		lista = lista->next;
	}
	lista->cont = tmp;
	ft_printf("rra\n");
	return ;
}

void	rrb(t_int_list **list_b)
{
	int			tmp;
	t_int_list	*listb;

	listb = *list_b;
	tmp = listb->cont;
	while (listb->next)
	{
		listb->cont = listb->next->cont;
		listb = listb->next;
	}
	listb->cont = tmp;
	ft_printf("rrb");
	return ;
}

void	rrr(t_int_list **list_a, t_int_list **list_b)
{
	int			tmp;
	t_int_list	*lista;
	t_int_list	*listb;

	lista = *list_a;
	tmp = lista->cont;
	while (lista->next)
	{
		lista->cont = lista->next->cont;
		lista = lista->next;
	}
	lista->cont = tmp;
	listb = *list_b;
	tmp = listb->cont;
	while (listb->next)
	{
		listb->cont = listb->next->cont;
		listb = listb->next;
	}
	listb->cont = tmp;
	ft_printf("rrr\n");
	return ;
}
