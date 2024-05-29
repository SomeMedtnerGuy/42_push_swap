/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:52 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 17:03:53 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_with_a_up(t_root *root, t_pair i, t_pair opt)
{
	opt.b = ft_min(i.b - opt.a, root->b_am - i.b);
	if (opt.b == i.b - opt.a)
	{
		while (opt.a-- > 0)
			ft_rr(root);
		while (opt.b-- > 0)
			ft_rb(root);
	}
	else
	{
		while (opt.a-- > 0)
			ft_ra(root);
		while (opt.b-- > 0)
			ft_rrb(root);
	}
}

static void	push_with_a_down(t_root *root, t_pair i, t_pair opt)
{
	opt.b = ft_min(i.b, (root->b_am - opt.a) - i.b);
	if (opt.b == i.b)
	{
		while (opt.a-- > 0)
			ft_rra(root);
		while (opt.b-- > 0)
			ft_rb(root);
	}
	else
	{
		while (opt.a-- > 0)
			ft_rrr(root);
		while (opt.b-- > 0)
			ft_rrb(root);
	}
}

static void	push_with_b_up(t_root *root, t_pair i, t_pair opt)
{
	opt.a = ft_min(i.a - opt.b, root->a_am - i.a);
	if (opt.a == i.a - opt.b)
	{
		while (opt.b-- > 0)
			ft_rr(root);
		while (opt.a-- > 0)
			ft_ra(root);
	}
	else
	{
		while (opt.b-- > 0)
			ft_rb(root);
		while (opt.a-- > 0)
			ft_rra(root);
	}
}

static void	push_with_b_down(t_root *root, t_pair i, t_pair opt)
{
	opt.a = ft_min(i.a, root->a_am - opt.b - i.a);
	if (opt.a == i.a)
	{
		while (opt.b-- > 0)
			ft_rrb(root);
		while (opt.a-- > 0)
			ft_ra(root);
	}
	else
	{
		while (opt.b-- > 0)
			ft_rrr(root);
		while (opt.a-- > 0)
			ft_rra(root);
	}
}

void	push_cheapest(t_root *root, int a, int b)
{
	t_pair	indexes;
	t_pair	opt_moves;

	indexes.a = a;
	indexes.b = b;
	opt_moves.a = ft_min(a, root->a_am - a);
	opt_moves.b = ft_min(b, root->b_am - b);
	if (opt_moves.a < opt_moves.b)
	{
		if (indexes.a == opt_moves.a)
			push_with_a_up(root, indexes, opt_moves);
		else
			push_with_a_down(root, indexes, opt_moves);
	}
	else
	{
		if (indexes.b == opt_moves.b)
			push_with_b_up(root, indexes, opt_moves);
		else
			push_with_b_down(root, indexes, opt_moves);
	}
	ft_pb(root);
	update_min_max(root);
}
