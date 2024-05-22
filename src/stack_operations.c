/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:41:07 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 17:51:52 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_item	*item_new(int n)
{
	t_item	*item;

	item = (t_item *)ft_calloc(1, sizeof(t_item));
	if (!item)
		return (NULL);
	item->n = n;
	item->opt = UINT_MAX;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

void	item_add(t_item **stack, t_item *new)
{
	if (!new || !stack)
		return ;
	if (!*stack)
	{
		new->next = new;
		new->prev = new;
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->prev = (*stack)->prev;
	(*stack)->prev->next = new;
	(*stack)->prev = new;
	*stack = new;
}

t_item	*item_remove(t_item **stack)
{
	t_item	*item;

	item = *stack;
	item->prev->next = item->next;
	item->next->prev = item->prev;
	*stack = item->next;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}
