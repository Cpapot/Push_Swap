/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:25:01 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/16 12:57:50 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	test(t_int_list	*list)
{
	int	i;

	i = 0;
	while ((list))
	{
		ft_printf("%d\n", list->cont);
		ft_printf("%p\n", list->next);
		list = (list)->next;
		i++;
		if (i > 7)
		{
			ft_printf("c'est peter\n");
			exit(EXIT_SUCCESS);
		}
	}
	ft_printf("c'est pas peter\n");
	return ;
}
