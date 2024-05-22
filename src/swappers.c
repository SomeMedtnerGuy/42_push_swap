/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:06:00 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 18:43:39 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_item **stack)
{
	t_item	*item;

	item = item_remove(stack);
	*stack = (*stack)->next;
	item_add(stack, item);
	*stack = (*stack)->prev;
}

void	ft_sa(t_root *root)
{
	if (root->a_am > 1)
		swap(&root->a);
}

void	ft_sb(t_root *root)
{
	if (root->b_am > 1)
		swap(&root->b);
}

void	ft_ss(t_root *root)
{
	ft_sa(root);
	ft_sb(root);
}
