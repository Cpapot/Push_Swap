/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:50:17 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/14 14:11:47 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_int_list **list_a)
{
	t_int_list	tmp;
	t_int_list	*list;

	list = *list_a;
	tmp.cont = list->cont;
	tmp.nb = list->nb;
	list->cont = list->next->cont;
	list->nb = list->next->nb;
	list->next->cont = tmp.cont;
	list->next->nb = tmp.nb;
	ft_printf("sa\n");
	return ;
}

void	sb(t_int_list **list_b)
{
	t_int_list	tmp;
	t_int_list	*list;

	list = *list_b;
	tmp.cont = list->cont;
	tmp.nb = list->nb;
	list->cont = list->next->cont;
	list->nb = list->next->nb;
	list->next->cont = tmp.cont;
	list->next->nb = tmp.cont;
	ft_printf("sb\n");
	return ;
}

void	ss(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	tmp;
	t_int_list	*lista;
	t_int_list	*listb;

	lista = *list_a;
	tmp.cont = lista->cont;
	tmp.nb = lista->nb;
	lista->cont = lista->next->cont;
	lista->nb = lista->next->nb;
	lista->next->cont = tmp.cont;
	lista->next->nb = tmp.nb;
	listb = *list_b;
	tmp.cont = listb->cont;
	tmp.nb = listb->nb;
	listb->cont = listb->next->cont;
	listb->next->cont = tmp.cont;
	listb->next->nb = tmp.nb;
	ft_printf("ss\n");
	return ;
}
