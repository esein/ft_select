/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:55:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/02 22:47:19 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

struct s_elem	*add_elem(t_elem *entries, char *name)
{
	struct s_elem		*new;

	new = NULL;
	new = ft_memalloc(sizeof(t_elem));
	new->prev = entries;
	new->next = NULL;
	new->name = name;
	return (new);
}

struct s_elem	*parse_entry(int argc, char **argv)
{
	int		x;
	t_elem	*entries;
	t_elem	*first;

	entries = NULL;
	entries = add_elem(NULL, argv[1]);
	first = entries;
	x = 2;
	while (x < argc)
	{
		entries->next = add_elem(entries, argv[x]);
		entries = entries->next;
		x++;
	}
	return (first);
}
