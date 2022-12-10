/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:35:16 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 00:07:21 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_int_list **list_a)
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
	ft_printf("ra\n");
	return ;
}

void	rb(t_int_list **list_b)
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
	ft_printf("rb");
	return ;
}

void	rr(t_int_list **list_a, t_int_list **list_b)
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
	ft_printf("rr\n");
	return ;
}
