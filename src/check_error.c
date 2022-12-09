/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:29:50 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/09 22:39:03 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_error(t_int_list *list)
{
	if (list)
		ft_lstintclear(&list);
	ft_printf("Error\n");
	exit (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	u;

	i = 1;
	if (argc <= 1)
		return (0);
	while (i != argc)
	{
		u = 0;
		while (argv[i][u])
		{
			if (!ft_isdigit(argv[i][u]))
				return (0);
			u++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(t_int_list *list)
{
	t_int_list	*tmp_list;
	int			tmp;

	while (list)
	{
		tmp = list->content;
		list = list->next;
		tmp_list = list;
		while (tmp_list)
		{
			if (tmp == tmp_list->content)

				return (0);
			tmp_list = tmp_list->next;
		}

	}
	return (1);
}
