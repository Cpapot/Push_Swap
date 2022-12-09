/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:04:56 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/09 19:41:26 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
/*
t_list	read_args(int argc, char **argv)
{
	int	i;

	i = 0;

}*/

void	print_error(void)
{
	ft_printf("Error\n");
	exit (0);
}

int	main(int argc, char **argv)
{

	if (!check_args(argc, argv))
		print_error();
	ft_printf("ok");
}
