/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotaters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:58:38 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 12:54:06 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->prev;
	ft_printf("rra\n");
}

void	ft_rrb(t_root *root)
{
	if (root->b_am > 0)
		root->b = root->b->prev;
	ft_printf("rrb\n");
}

void	ft_rrr(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->prev;
	if (root->b_am > 0)
		root->b = root->b->prev;
	ft_printf("rrr\n");
}
