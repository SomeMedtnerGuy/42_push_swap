/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:11 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/22 19:39:45 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_item *item, int size)
{
	t_item	*buffer;
	int		i;

	i = 0;
	while (i++ < size)
	{
		buffer = item->next;
		free(item);
		item = buffer;
	}
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
	while (--i > 0)
	{
		if (i <= root->a_am)
		{
			ft_printf("%i ", aptr->n);
			aptr = aptr->next;
		}
		else
			ft_printf("  ");
		if (i <= root->b_am)
		{
			ft_printf("%i\n", bptr->n);
			bptr = bptr->next;
		}
		else
			ft_printf(" \n");
	}
	ft_printf("- -\na b\n");
}

int	main(int argc, char **argv)
{
	t_root	root;
	int		i;

	if (argc < 2)
		return (0);
	root.a = NULL;
	parse_stacks(argv, &root);
	print_stacks(&root);
	i = 0;
	while (i++ < root.a_am)
	{
		ft_rra(&root);
		ft_printf("____________\npb performed\n____________\n\n");
		print_stacks(&root);
	}
	free_stack(root.a, root.a_am);
}
