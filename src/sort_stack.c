/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:52:26 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 19:22:46 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort3(t_root *root)
{
	t_item	*iptr;

	iptr = root->a;
	while (iptr->n > iptr->next->n || iptr->n > iptr->prev->n)
		iptr = iptr->next;
	if (iptr->next->n > iptr->prev->n)
		ft_sa(root);
	while (root->a != iptr)
		ft_ra(root);
}

static void	return_to_a(t_root *root)
{
	int	count;

	count = 3;
	while (root->b)
	{
		while (root->a->prev->n > root->b->n && count)
		{
			ft_rra(root);
			count--;
		}
		ft_pa(root);
	}
	while (root->a->n > root->a->prev->n)
		ft_rra(root);
}

static void	initial_check(t_root *root)
{
	t_item	*iptr;

	iptr = root->a;
	while (iptr->n < iptr->next->n)
	{
		iptr = iptr->next;
		if (iptr->next == root->a)
			exit(0);
	}
	if (root->a_am > 3)
		return ;
	else if (root->a_am == 2)
	{
		if (root->a->n > root->a->next->n)
			ft_ra(root);
	}
	else if (root->a_am == 3)
		sort3(root);
	exit(0);
}

static void	place_max_on_top(t_root *root)
{
	int	i;

	i = find_i_from_n(root->b, root->b_max->n);
	if (i < root->b_am / 2)
	{
		while (i--)
			ft_rb(root);
	}
	else
	{
		i = root->b_am - i;
		while (i--)
			ft_rrb(root);
	}
}

void	sort_stack(t_root *root)
{
	t_pair	opt;

	initial_check(root);
	ft_pb(root);
	root->b_max = root->b;
	root->b_min = root->b;
	if (root->a_am > 3)
	{
		if (root->a->n > root->b_max->n)
			root->b_max = root->a;
		else
			root->b_min = root->a;
		ft_pb(root);
	}
	while (root->a_am > 3)
	{
		opt = find_cheapest(root);
		push_cheapest(root, opt.a, opt.b);
	}
	sort3(root);
	place_max_on_top(root);
	return_to_a(root);
}
