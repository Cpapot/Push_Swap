/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:29:50 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/18 18:29:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_error(t_int_list *list)
{
	if (list)
		ft_lstintclear(&list);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	u;
	int	tmp;

	i = 1;
	tmp = 0;
	while (i != argc)
	{
		u = 0;
		while (argv[i][u])
		{
			tmp += ft_isdigit(argv[i][u]);
			if ((!ft_isdigit(argv[i][u]) && argv[i][u] != '-'
				&& argv[i][u] != ' ') || (argv[i][u] == '-'
					&& !ft_isdigit(argv[i][u + 1])) || (argv[i][u] == '-'
						&& (u != 0 && argv[i][u - 1] != ' ')))
				print_error(NULL);
			u++;
		}
		i++;
	}
	if (tmp >= 1)
		return (1);
	else
		return (0);
}

char	*check_splitted_numbers(char *str)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]))
			tmp += 1;
		i++;
	}
	if (tmp == 0)
		print_error(NULL);
	return (str);
}

int	check_duplicate(t_int_list *list)
{
	t_int_list	*tmp_list;
	int			tmp;

	while (list)
	{
		tmp = list->cont;
		list = list->next;
		tmp_list = list;
		while (tmp_list)
		{
			if (tmp == tmp_list->cont)
				return (0);
			tmp_list = tmp_list->next;
		}
	}
	return (1);
}
