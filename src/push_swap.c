/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:04:56 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/17 20:46:38 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_int_list *list)
{
	while (list->next)
	{
		if (list->cont > list->next->cont)
			return (0);
		list = list->next;
	}
	return (1);
}

t_int_list	*read_args_split(int argc, char **argv)
{
	t_int_list	*start;
	t_int_list	*node;
	int			i;

	i = 1;
	start = ft_lstintnew(ft_atoi(argv[0]));
	while (i < argc)
	{
		node = ft_lstintnew(ft_atoi(argv[i]));
		ft_lstintadd_back(&start, node);
		if (node == NULL)
		{
			ft_lstintclear(&start);
			return (NULL);
		}
		i++;
	}
	return (start);
}

t_int_list	*read_args(int argc, char **argv)
{
	t_int_list	*start;
	t_int_list	*node;
	int			i;

	i = 2;
	start = ft_lstintnew(ft_atoi(argv[1]));
	while (i < argc)
	{
		node = ft_lstintnew(ft_atoi(argv[i]));
		ft_lstintadd_back(&start, node);
		if (node == NULL)
		{
			ft_lstintclear(&start);
			return (NULL);
		}
		i++;
	}
	return (start);
}

int	main(int argc, char **argv)
{
	t_int_list	*intlist_a;
	char		**split;
	int			i;

	if (!check_args(argc, argv))
		print_error(NULL);
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[i])
			i++;
		intlist_a = read_args_split(i, split);
		free(split);
	}
	else
		intlist_a = read_args(argc, argv);
	if (!check_duplicate(intlist_a))
		print_error(intlist_a);
	call_sorter(&intlist_a);
}
