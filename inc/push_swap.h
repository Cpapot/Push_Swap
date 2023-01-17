/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:03:10 by cpapot            #+#    #+#             */
/*   Updated: 2023/01/17 20:30:10 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

# define INT_MAX	2147483647
# define INT_MIN	-2147483647

typedef struct s_info
{
	int					nb;
	int					rota;
	int					quart_size;
	int					quart_max;
	int					quart_min;
}					t_info;

/*					push_swap					*/
int		is_sorted(t_int_list *list);

/*					check_error					*/
void	print_error(t_int_list *list);
int		check_args(int argc, char **argv);
int		check_duplicate(t_int_list *list);

/*					call_sorter					*/
void	call_sorter(t_int_list **list_a);

/*					sort_three					*/
void	sort_three_nbr(t_int_list **list_a);

/*					sort_five					*/
void	sort_five_nbr(t_int_list **list_a);

/*					swap						*/
void	sa(t_int_list **list_a);
void	sb(t_int_list **list_b);
void	ss(t_int_list **list_a, t_int_list **list_b);

/*					push						*/
void	pb(t_int_list **list_a, t_int_list **list_b);
void	pa(t_int_list **list_a, t_int_list **list_b);

/*					rotate						*/
void	rb(t_int_list **list_b);
void	ra(t_int_list **list_a);
void	rr(t_int_list **list_a, t_int_list **list_b);

/*					reverse rotate				*/
void	rrb(t_int_list **list_b);
void	rra(t_int_list **list_a);
void	rrr(t_int_list **list_a, t_int_list **list_b);

/*					median						*/
int		find_median_in_array(int *int_array, int size, int median_pos);
int		median_pos(int size);
int		find_median(int size, t_int_list **list_a);

/*					find min max				*/
int		max_pos(t_int_list **list);
int		min_pos(t_int_list **list);
int		find_max(t_int_list **list);
int		find_min(t_int_list **list);
int	find_min_superior_at(int a, t_int_list **list);

/*					smart_rotate				*/
void	smart_rotate(t_int_list **list_b, int size, int max, int min);

/*					sort median						*/
void	sort_median(t_int_list **list_a);

/*					sort						*/
void	smart_push_and_rotate(t_int_list **list_b, t_int_list **list_a, int s);
void	smart_push(t_int_list **list_a, t_int_list **list_b, int size);

/*					sort_quarter				*/
void	sort_quarter(t_int_list	**list_a, int size);

#endif
