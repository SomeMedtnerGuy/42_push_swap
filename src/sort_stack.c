/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:52:26 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 15:54:02 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	find_i_from_n(t_item *first, int n)
{
	t_item	*iptr;
	int	i;

	iptr = first;
	i = 0;
	while (n != iptr->n)
	{
		iptr = iptr->next;
		i++;
	}
	return (i);
}

int	get_idest(t_root *root, t_item *aptr)
{
	t_item	*iptr;
	int	i;

	if (aptr->n > root->b_max->n)
		return (find_i_from_n(root->b, root->b_max->n));
	else if (aptr->n < root->b_min->n)
		return (find_i_from_n(root->b, root->b_max->n));
	iptr = root->b;
	i = 0;
	while (iptr->n < aptr->n)
	{
		iptr = iptr->next;
		i++;
	}
	while (aptr->n < iptr->n)
	{
		iptr = iptr->next;
		i++;
	}
	if (i == root->b_am)
		i = 0;
	return (i);
}

int	calculate_movs_am(int a, int b, int amod, int bmod)
{
	int	aopt;
	int	bopt;

	aopt = ft_min(a, amod - a);
	bopt = ft_min(b, bmod - b);
	if (aopt < bopt)
	{
		if (a == aopt)
			return (aopt + ft_min(b - aopt, bmod - b));
		else
			return (aopt + ft_min(b, (bmod - aopt) - b));
	}
	else
	{
		if (b == bopt)
			return (bopt + ft_min(a - bopt, amod - a));
		else
			return (bopt + ft_min(a, amod - bopt - a));
	}
}

t_pair	find_cheapest(t_root *root)
{
	t_item	*aptr;
	t_pair	opt;
	int	i;
	int	j;

	i = 0;
	aptr = root->a;
	opt.a = i++;
	opt.b = get_idest(root, aptr);
	while (i < root->a_am)
	{
		aptr = aptr->next;
		j = get_idest(root, aptr);
		if (calculate_movs_am(i, j, root->a_am, root->b_am)
			< calculate_movs_am(opt.a, opt.b, root->a_am, root->b_am))
			{
				opt.a = i;
				opt.b = j;
			}
		i++;
	}
	return (opt);
}

void	push_cheapest(t_root *root, int a, int b)
{
	int     aopt;
        int     bopt;

        aopt = ft_min(a, root->a_am - a);
        bopt = ft_min(b, root->b_am - b);
        if (aopt < bopt)
        {
                if (a == aopt)
		{
                        bopt = ft_min(b - aopt, root->b_am - b);
			if (bopt == b - aopt)
			{
				while (aopt-- > 0)
					ft_rr(root);
				while (bopt-- > 0)
					ft_rb(root);
			}
			else
			{
				while (aopt-- > 0)
					ft_ra(root);
				while (bopt-- > 0)
					ft_rrb(root);
			}
		}
                else
		{
                        bopt = ft_min(b, (root->b_am - aopt) - b);
			if (bopt == b)
			{
				while (aopt-- > 0)
					ft_rra(root);
				while (bopt-- > 0)
					ft_rb(root);
			}
			else
			{
				while (aopt-- > 0)
					ft_rrr(root);
				while (bopt-- > 0)
					ft_rrb(root);
			}
		}
        }
        else
        {
                if (b == bopt)
		{
                        aopt = ft_min(a - bopt, root->a_am - a);
			if (aopt == a - bopt)
			{
				while (bopt-- > 0)
					ft_rr(root);
				while (aopt-- > 0)
					ft_ra(root);
			}
			else
			{
				while (bopt-- > 0)
					ft_rb(root);
				while (aopt-- > 0)
					ft_rra(root);
			}
		}
		else
		{
                        aopt = ft_min(a, root->a_am - bopt - a);
			if (aopt == a)
			{
				while (bopt-- > 0)
					ft_rrb(root);
				while (aopt-- > 0)
					ft_ra(root);
			}
			else
			{
				while (bopt-- > 0)
					ft_rrr(root);
				while (aopt-- > 0)
					ft_rra(root);
			}
		}
        }
	ft_pb(root);
	if (root->b->n < root->b_min->n)
		root->b_min = root->b;
	else if (root->b->n > root->b_max->n)
		root->b_max = root->b;
}

void	sort3(t_root *root)
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

void	sort_stack(t_root *root)
{
	t_pair	opt;

	ft_pb(root);
	root->b_max = root->b;
	root->b_min = root->b;
	if (root->a->n > root->b_max->n)
		root->b_max = root->a;
	else
		root->b_min = root->a;
	ft_pb(root);

	while (root->a_am > 3)
	{
		opt = find_cheapest(root);
		push_cheapest(root, opt.a, opt.b);
	}
	sort3(root);
	while (root->b != root->b_max)
		ft_rb(root);
	int	count = 3;
	while (root->b)
	{
		if (root->a->prev->n > root->b->n && count)
		{
			ft_rra(root);
			count--;
		}
		ft_pa(root);
	}
}
