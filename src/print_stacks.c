/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:33:06 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 13:05:51 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_elements(t_root *root, int i, t_item **aptr, t_item **bptr)
{
	if (i <= root->a_am)
	{
		ft_printf("|%i ", (*aptr)->n);
		*aptr = (*aptr)->next;
	}
	else
		ft_printf("|  ");
	if (i <= root->b_am)
	{
		ft_printf("%i|\n", (*bptr)->n);
		*bptr = (*bptr)->next;
	}
	else
		ft_printf(" |\n");
}

void	print_stacks(t_root *root)
{
	int		i;
	t_item	*aptr;
	t_item	*bptr;

	if (root->a_am > root->b_am)
		i = root->a_am + 1;
	else
		i = root->b_am + 1;
	aptr = root->a;
	bptr = root->b;
	ft_printf("|###|\n");
	while (--i > 0)
		print_elements(root, i, &aptr, &bptr);
	ft_printf("|- -|\n|a b|\n|___|\n");
}
