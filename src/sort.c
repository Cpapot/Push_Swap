/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:27:18 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/14 21:58:37 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min_pos(t_int_list **list)
{
	int			i;
	int			tmp;
	t_int_list	*tmplist;
	int		pos;

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

int	find_max_pos(t_int_list **list)
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

//calculer le plus renta entre ra et rra et pour le min et le max et trouver le plus renta entre le min et le max
void	smart_push(t_int_list **list_a, t_int_list **list_b, int size)
{
	int		tmp;
	int		i;

	/*if (find_min_pos(list_b) - 1 <= size - (find_min_pos(list_b)- 1))
	{
		if (find_max_pos(list_b) - 1 <= size - (find_max_pos(list_b)- 1))
		{
			if (find_min_pos(list_b) - 1 <= find_max_pos(list_b) - 1)

			else

		}
		else
		{
			if (find_min_pos(list_b) - 1 <= size - (find_max_pos(list_b)- 1))

			else

		}
	}
	else
	{
		//pareil
	}*/
	max = find_max_pos(list_b);
	min = find_min_pos(list_b);

	ft_printf("\n%d, %d", min, max);
}

void	push_half(t_int_list **list_a, t_int_list **list_b, int median_nbr, int size)
{
	int			i;

	i = 0;
	while (i != median_pos(size))
	{
		while ((* list_a)->cont > median_nbr)
			ra(list_a);
		pb(list_a, list_b);
		i++;
	}
}

void	sort(t_int_list **list_a)
{
	int			median_nbr;
	int			size;
	t_int_list	*list_b;
	t_int_list	*tmp;


	tmp = *list_a;
	size = ft_lstintsize(tmp);
	median_nbr = find_median(size, &tmp);
	list_b = NULL;
	push_half(list_a, &list_b, median_nbr, size);
	smart_push(list_a, &list_b, size);
	ft_lstintclear(&list_b);
	ft_lstintclear(list_a);
}
