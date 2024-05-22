/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotaters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:58:38 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 19:00:43 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->prev;
}

void	ft_rrb(t_root *root)
{
	if (root->b_am > 0)
		root->b = root->b->prev;
}

void	ft_rrr(t_root *root)
{
	ft_rra(root);
	ft_rrb(root);
}
