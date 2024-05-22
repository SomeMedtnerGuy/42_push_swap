/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotaters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:52:35 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 18:56:56 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_root *root)
{
	if (root->a_am > 0)
		root->a = root->a->next;
}

void	ft_rb(t_root *root)
{
	if (root->b_am > 0)
		root->b = root->b->next;
}

void	ft_rr(t_root *root)
{
	ft_ra(root);
	ft_rb(root);
}
