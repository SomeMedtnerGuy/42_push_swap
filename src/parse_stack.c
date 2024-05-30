/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:11:23 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/05/23 17:35:59 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		ft_strict_atoi(char *nptr);
static int		is_n_zero(char *nptr);
static int		n_already_exists(t_root *root, int n);
static void		free_and_exit(t_root *root);

void	parse_stacks(char **items, t_root *root)
{
	t_item	*new;
	int		n;

	root->a_am = 0;
	root->b_am = 0;
	root->a = NULL;
	root->b = NULL;
	while (*items)
	{
		n = ft_strict_atoi(*items);
		if (n_already_exists(root, n))
			free_and_exit(root);
		new = item_new(ft_strict_atoi(*items));
		item_push(&root->a, new);
		root->a = root->a->next;
		root->a_am++;
		if (!new || (new->n == 0 && !is_n_zero(*items)))
			free_and_exit(root);
		items++;
	}
}

static int	ft_strict_atoi(char *nptr)
{
	long	n;
	int		neg;

	neg = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + *nptr - 48;
		nptr += 1;
	}
	if (*nptr != '\0')
		return (0);
	n *= neg;
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	return ((int)n);
}

static int	is_n_zero(char *nptr)
{
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr == '0')
		nptr++;
	if (*nptr == '\0')
		return (1);
	return (0);
}

static int	n_already_exists(t_root *root, int n)
{
	int		i;
	t_item	*iptr;

	i = 0;
	iptr = root->a;
	while (i < root->a_am)
	{
		if (iptr->n == n)
			return (1);
		iptr = iptr->next;
		i++;
	}
	return (0);
}

static void	free_and_exit(t_root *root)
{
	write(2, "Error\n", 6);
	free_stack(root->a, root->a_am);
	exit(0);
}
