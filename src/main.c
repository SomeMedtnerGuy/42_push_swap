/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:11 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 14:55:26 by ndo-vale         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_root	root;

	if (argc < 2)
		return (0);
	parse_stacks(argv, &root);
	//print_stacks(&root);
	sort_stack(&root);
	//print_stacks(&root);
	free_stack(root.a, root.a_am);
	free_stack(root.b, root.b_am);
}
