/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:52:35 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 12:52:18 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->next;
	ft_printf("ra\n");
}

void	ft_rb(t_root *root)
{
	if (root->b_am > 0)
		root->b = root->b->next;
	ft_printf("rb\n");
}

void	ft_rr(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->next;
	if (root->b_am > 0)
		root->b = root->b->next;
	ft_printf("rr\n");
}
