/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:04:56 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/10 17:50:39 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

	if (!check_args(argc, argv))
		print_error(NULL);
	if (argc <= 1)
		return (0);
	intlist_a = read_args(argc, argv);
	if (!check_duplicate(intlist_a))
		print_error(intlist_a);
	call_sorter(intlist_a);
	ft_lstintclear(&intlist_a);
}
