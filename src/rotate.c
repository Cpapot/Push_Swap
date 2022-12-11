/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 23:35:16 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 17:11:27 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_int_list **list_a)
{
	t_int_list	*list;
	int			tmp;
	int			tmp2;

	list = *list_a;
	while (list)
	{
		tmp2 = list->cont;
		list->cont = tmp;
		tmp = tmp2;
		list = list->next;
	}
	list = *list_a;
	list->cont = tmp;
	ft_printf("ra\n");
	return ;
}

void	rb(t_int_list **list_b)
{
	t_int_list	*list;
	int			tmp;
	int			tmp2;

	list = *list_b;
	while (list)
	{
		tmp2 = list->cont;
		list->cont = tmp;
		tmp = tmp2;
		list = list->next;
	}
	list = *list_b;
	list->cont = tmp;
	ft_printf("rn\n");
	return ;
}

void	rr(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*list;
	int			tmp;
	int			tmp2;

	list = *list_a;
	while (list)
	{
		tmp2 = list->cont;
		list->cont = tmp;
		tmp = tmp2;
		list = list->next;
	}
	list = *list_a;
	list->cont = tmp;
	list = *list_b;
	while (list)
	{
		tmp2 = list->cont;
		list->cont = tmp;
		tmp = tmp2;
		list = list->next;
	}
	list = *list_b;
	list->cont = tmp;
	ft_printf("rr\n");
}
