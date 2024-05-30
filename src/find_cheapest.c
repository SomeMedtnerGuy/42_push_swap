/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:36 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 17:03:37 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_idest(t_root *root, t_item *aptr)
{
	t_item	*iptr;
	int		i;

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

static int	calculate_movs_am(int a, int b, int amod, int bmod)
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
	int		i;
	int		j;

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
