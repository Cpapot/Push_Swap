/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:03:10 by cpapot            #+#    #+#             */
/*   Updated: 2022/12/11 00:05:28 by cpapot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

/*					check_error					*/
void	print_error(t_int_list *list);
int		check_args(int argc, char **argv);
int		check_duplicate(t_int_list *list);

/*					call_sorter					*/
void	call_sorter(t_int_list *list_a);

/*					sort_three					*/
void	sort_three_nbr(t_int_list *list_a);

/*					sort_five					*/
void	sort_five_nbr(t_int_list *list_a);

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

#endif
