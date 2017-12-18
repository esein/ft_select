/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcadiou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 20:55:08 by gcadiou           #+#    #+#             */
/*   Updated: 2017/12/18 16:51:08 by gcadiou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerft_select.h"

struct s_elem	*del_selected(t_elem *elem)
{
	t_elem	*first;

	first = elem;
	while (elem != NULL)
	{
		if (elem->selected == 1)
		{
			if (elem->next != NULL)
				elem->next->prev = elem->prev;
			if (elem->prev != NULL)
				elem->prev->next = elem->next;
			else
				first = elem->next;
			if (first == NULL)
				return (NULL);
			if (elem->cursor_on == 1)
			{
				if (elem->next != NULL)
					elem->next->cursor_on = 1;
				else
					first->cursor_on = 1;
			}
			elem = ft_free(elem);
			elem = first;
		}
		else
			elem = elem->next;
	}
	return (first);
}

struct s_elem	*del_elem(t_elem *elem)
{
	t_elem	*first;

	first = elem;
	while (elem != NULL)
	{
		if (elem->cursor_on == 1)
			break;
		elem = elem->next;
	}
	if (elem == NULL)
		error_ft_select(CODING_BUG, "del_elem");
	if (elem->next != NULL)
	{
		elem->next->prev = elem->prev;
		elem->next->cursor_on = 1;
	}
	else
		first->cursor_on = 1;
	if (elem->prev != NULL)
		elem->prev->next = elem->next;
	else
		first = elem->next;
	elem = ft_free(elem);
	return (first);
}

struct s_elem	*add_elem(t_elem *entries, char *name)
{
	struct s_elem		*new;

	new = NULL;
	new = ft_memalloc(sizeof(t_elem));
	new->prev = entries;
	new->next = NULL;
	new->name = name;
	new->name_len = ft_strlen(name);
	new->cursor_on = 0;
	new->selected = 0;
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
	entries->cursor_on = 1;
	while (x < argc)
	{
		entries->next = add_elem(entries, argv[x]);
		entries = entries->next;
		x++;
	}
	return (first);
}
