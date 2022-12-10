/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:50:17 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/10 22:53:43 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_int_list **list_a)
{
	int			tmp;
	t_int_list	*list;

	list = *list_a;
	tmp = list->cont;
	list->cont = list->next->cont;
	list->next->cont = tmp;
	ft_printf("sa\n");
	return ;
}

void	sb(t_int_list **list_b)
{
	int			tmp;
	t_int_list	*list;

	list = *list_b;
	tmp = list->cont;
	list->cont = list->next->cont;
	list->next->cont = tmp;
	ft_printf("sb\n");
	return ;
}

void	ss(t_int_list **list_a, t_int_list **list_b)
{
	int			tmp;
	t_int_list	*lista;
	t_int_list	*listb;

	lista = *list_a;
	tmp = lista->cont;
	lista->cont = lista->next->cont;
	lista->next->cont = tmp;
	listb = *list_b;
	tmp = listb->cont;
	listb->cont = listb->next->cont;
	listb->next->cont = tmp;
	ft_printf("ss\n");
	return ;
}
