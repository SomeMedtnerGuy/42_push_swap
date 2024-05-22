/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:46:35 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 18:58:15 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_root *root)
{
	if (root->b_am > 0)
	{
		item_add(&root->a, item_remove(&root->b));
		root->a_am++;
		root->b_am--;
	}
}

void	ft_pb(t_root *root)
{
	if (root->a_am > 0)
	{
		item_add(&root->b, item_remove(&root->a));
		root->a_am--;
		root->b_am++;
	}
}
