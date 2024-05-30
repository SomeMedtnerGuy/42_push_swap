/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:22:03 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 19:18:45 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_item
{
	int				n;
	unsigned int	opt;
	struct s_item	*next;
	struct s_item	*prev;
}	t_item;

typedef struct s_pair
{
	int	a;
	int	b;
}	t_pair;

typedef struct s_root
{
	t_item	*a;
	t_item	*b;
	int		a_am;
	int		b_am;
	t_item	*b_max;
	t_item	*b_min;
}	t_root;

t_item	*item_new(int n);
void	item_push(t_item **stack, t_item *new);
t_item	*item_pop(t_item **stack);
void	parse_stacks(char **items, t_root *root);
void	free_stack(t_item *stack, int size);

void	ft_sa(t_root *root);
void	ft_sb(t_root *root);
void	ft_ss(t_root *root);

void	ft_pa(t_root *root);
void	ft_pb(t_root *root);

void	ft_ra(t_root *root);
void	ft_rb(t_root *root);
void	ft_rr(t_root *root);

void	ft_rra(t_root *root);
void	ft_rrb(t_root *root);
void	ft_rrr(t_root *root);

void	sort_stack(t_root *root);
void	push_cheapest(t_root *root, int a, int b);
t_pair	find_cheapest(t_root *root);

int		ft_min(int a, int b);
void	update_min_max(t_root *root);
int		find_i_from_n(t_item *first, int n);

void	print_stacks(t_root *root);

#endif
