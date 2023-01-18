/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:04:56 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/18 17:59:34 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long long	ft_atoll(const char *str)
{
	long long	result;
	long long	tmp;
	char		is_negative;

	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	is_negative = *str == '-';
	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		tmp = result * 10 + *str++ - '0';
		if (tmp < result)
		{
			if (is_negative)
				return (LLONG_MIN);
			return (LLONG_MAX);
		}
		result = tmp;
	}
	if (is_negative)
		return (-result);
	return (result);
}

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
	long long	tmp;

	i = 1;
	tmp = ft_atoll(argv[0]);
	if (tmp > INT_MAX || tmp < INT_MIN)
		print_error(NULL);
	start = ft_lstintnew((int)tmp);
	while (i < argc)
	{
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			print_error(start);
		node = ft_lstintnew((int)tmp);
		ft_lstintadd_back(&start, node);
		if (node == NULL)
		{
			ft_lstintclear(&start);
			print_error(start);
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
	long long	tmp;

	i = 2;
	tmp = ft_atoll(argv[1]);
	if (tmp > INT_MAX || tmp < INT_MIN)
		print_error(NULL);
	start = ft_lstintnew((int)tmp);
	while (i < argc)
	{
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			print_error(start);
		node = ft_lstintnew(tmp);
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

	i = 0;
	check_args(argc, argv);
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		split = ft_split(check_splitted_numbers(argv[1]), ' ');
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
