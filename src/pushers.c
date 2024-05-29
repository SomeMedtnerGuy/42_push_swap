/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:46:35 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 17:36:53 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_root *root)
{
	if (root->b_am > 0)
	{
		item_push(&root->a, item_pop(&root->b));
		root->a_am++;
		root->b_am--;
	}
	ft_printf("pa\n");
}

void	ft_pb(t_root *root)
{
	if (root->a_am > 0)
	{
		item_push(&root->b, item_pop(&root->a));
		root->a_am--;
		root->b_am++;
	}
	ft_printf("pb\n");
}
