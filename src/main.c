/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:11 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/30 10:26:40 by ndo-vale         ###   ########.fr       */
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

void	free_ints(char **ints)
{
	int	i;

	i = 0;
	while (ints[i])
		free(ints[i++]);
	free(ints);
}

int	main(int argc, char **argv)
{
	t_root	root;
	char	**ints;
	int		mflag;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ints = ft_split(argv[1], ' ');
		mflag = 1;
	}
	else
	{
		ints = argv + 1;
		mflag = 0;
	}
	parse_stacks(ints, &root, mflag);
	if (mflag)
		free_ints(ints);
	sort_stack(&root);
	free_stack(root.a, root.a_am);
}
