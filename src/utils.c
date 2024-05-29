/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:07 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/29 17:03:11 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	update_min_max(t_root *root)
{
	if (root->b->n < root->b_min->n)
		root->b_min = root->b;
	else if (root->b->n > root->b_max->n)
		root->b_max = root->b;
}
