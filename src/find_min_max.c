/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:13:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/15 17:00:16 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_pos(t_int_list **list)
{
	int			i;
	int			tmp;
	int			pos;
	t_int_list	*tmplist;

	i = 0;
	tmplist = *list;
	tmp = INT_MIN;
	while (tmplist != NULL)
	{
		i++;
		if (tmplist->cont >= tmp)
		{
			tmp = tmplist->cont;
			pos = i;
		}
		tmplist = tmplist->next;
	}
	return (pos);
}

int	min_pos(t_int_list **list)
{
	int			i;
	int			tmp;
	t_int_list	*tmplist;
	int			pos;

	i = 0;
	tmp = INT_MAX;
	tmplist = *list;
	while (tmplist != NULL)
	{
		i++;
		if (tmplist->cont <= tmp)
		{
			tmp = tmplist->cont;
			pos = i;
		}
		tmplist = tmplist->next;
	}
	return (pos);
}

int	find_max(t_int_list **list)
{
	int			tmp;
	t_int_list	*tmplist;

	tmplist = *list;
	tmp = INT_MIN;
	while (tmplist != NULL)
	{
		if (tmplist->cont >= tmp)
		{
			tmp = tmplist->cont;
		}
		tmplist = tmplist->next;
	}
	return (tmp);
}

int	find_min(t_int_list **list)
{
	int			tmp;
	t_int_list	*tmplist;

	tmp = INT_MAX;
	tmplist = *list;
	while (tmplist != NULL)
	{
		if (tmplist->cont <= tmp)
		{
			tmp = tmplist->cont;
		}
		tmplist = tmplist->next;
	}
	return (tmp);
}
