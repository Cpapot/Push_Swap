/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:34:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/13 16:14:47 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*lista;
	t_int_list	*listb;
	t_int_list	*new;

	lista = *list_a;
	listb = *list_b;
	if (listb == NULL)
	{
		listb = ft_lstintnew(lista->cont);
		list_a = &lista->next;
		ft_lstintdelone(lista);
	}
	else
	{
		new = ft_lstintnew(lista->cont);
		list_a = &lista->next;
		ft_lstintdelone(lista);
		ft_lstintadd_front(&lista, new);
	}
	ft_printf("pb\n");
	return ;
}

void	pa(t_int_list **list_a, t_int_list **list_b)
{
	t_int_list	*lista;
	t_int_list	*listb;
	t_int_list	*new;

	lista = *list_a;
	listb = *list_b;
	if (lista == NULL )
	{
		lista = ft_lstintnew(listb->cont);
		*list_b = listb->next;
		ft_lstintdelone(listb);
	}
	else
	{
		new = ft_lstintnew(listb->cont);
		*list_b = listb->next;
		ft_lstintdelone(listb);
		ft_lstintadd_front(&lista, new);
	}
	ft_printf("pa\n");
	return ;
}
